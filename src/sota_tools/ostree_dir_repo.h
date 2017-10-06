#ifndef SOTA_CLIENT_TOOLS_OSTREE_DIR_REPO_H_
#define SOTA_CLIENT_TOOLS_OSTREE_DIR_REPO_H_

#include <boost/array.hpp>
#include <boost/noncopyable.hpp>
#include <list>
#include <map>

#include "ostree_hash.h"
#include "ostree_object.h"
#include "ostree_ref.h"
#include "ostree_repo.h"

class OSTreeDirRepo : public OSTreeRepo {
 public:
  explicit OSTreeDirRepo(std::string root_path) : root_(root_path) {}

  bool LooksValid() const;
  OSTreeObject::ptr GetObject(const OSTreeHash hash) const;
  OSTreeObject::ptr GetObject(const uint8_t sha256[32]) const;
  OSTreeRef GetRef(const std::string &refname) const;

  const std::string root() const { return root_; }

 private:
  typedef std::map<OSTreeHash, OSTreeObject::ptr> otable;
  mutable otable ObjectTable;  // Makes sure that the same commit object is not added twice
  const std::string root_;
};

// vim: set tabstop=2 shiftwidth=2 expandtab:
#endif  // SOTA_CLIENT_TOOLS_OSTREE_DIR_REPO_H_
