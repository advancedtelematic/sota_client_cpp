#ifndef UPTANE_SECONDARYINTERFACE_H
#define UPTANE_SECONDARYINTERFACE_H

#include <string>

#include "json/json.h"
#include "uptane/tuf.h"

namespace Uptane {

class SecondaryInterface {
 public:
  using Ptr = std::shared_ptr<SecondaryInterface>;

 public:
  virtual EcuSerial getSerial() const = 0;
  virtual Uptane::HardwareIdentifier getHwId() const = 0;
  virtual PublicKey getPublicKey() const = 0;

  virtual Json::Value getManifest() const = 0;
  virtual bool putMetadata(const RawMetaPack& meta_pack) = 0;

  virtual int32_t getRootVersion(bool director) const = 0;
  virtual bool putRoot(const std::string& root, bool director) = 0;

  virtual bool sendFirmware(const std::string& data) = 0;

  virtual ~SecondaryInterface() = default;

 public:
  // make children non-copyable
  SecondaryInterface(const SecondaryInterface&) = delete;
  SecondaryInterface& operator=(const SecondaryInterface&) = delete;

 protected:
  SecondaryInterface() = default;
};
}  // namespace Uptane

#endif  // UPTANE_SECONDARYINTERFACE_H
