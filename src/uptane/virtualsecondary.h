#ifndef UPTANE_VIRTUALSECONDARY_H_
#define UPTANE_VIRTUALSECONDARY_H_

#include <string>
#include <vector>

#include <boost/filesystem.hpp>
#include "json/json.h"

#include "types.h"
#include "uptane/secondaryconfig.h"
#include "uptane/secondaryinterface.h"
#include "uptane/tufrepository.h"

namespace Uptane {
class VirtualSecondary : public SecondaryInterface {
 public:
  VirtualSecondary(const SecondaryConfig &sconfig_in, Uptane::Repository *primary) : SecondaryInterface(sconfig_in);

  void setKeys(const std::string &public_key, const std::string &private_key);
  Json::Value verifyMeta(const TimeMeta &time_meta, const Root &root_meta, const Targets &targets_meta);
  bool writeImage(const uint8_t *blob, size_t size);
  Json::Value genAndSendManifest(Json::Value custom = Json::Value(Json::nullValue));

 private:
  std::string detected_attack;
  bool wait_for_target;
  std::string expected_target_name;
  std::vector<Hash> expected_target_hashes;
  int64_t expected_target_length;
};
}

#endif  // UPTANE_VIRTUALSECONDARY_H_
