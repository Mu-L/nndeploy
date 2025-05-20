#ifndef _NNDEPLOY_PREPROCESS_CONVERT_TO_H_
#define _NNDEPLOY_PREPROCESS_CONVERT_TO_H_

#include "nndeploy/base/any.h"
#include "nndeploy/base/common.h"
#include "nndeploy/base/glic_stl_include.h"
#include "nndeploy/base/log.h"
#include "nndeploy/base/macro.h"
#include "nndeploy/base/object.h"
#include "nndeploy/base/opencv_include.h"
#include "nndeploy/base/status.h"
#include "nndeploy/base/string.h"
#include "nndeploy/dag/edge.h"
#include "nndeploy/dag/node.h"
#include "nndeploy/device/buffer.h"
#include "nndeploy/device/device.h"
#include "nndeploy/device/tensor.h"

namespace nndeploy {
namespace preprocess {

class NNDEPLOY_CC_API ConvertToParam : public base::Param {
 public:
  base::DataType dst_data_type_ = base::dataTypeOf<float>();
};

class NNDEPLOY_CC_API ConvertTo : public dag::Node {
 public:
  ConvertTo(const std::string &name) : dag::Node(name) {
    key_ = "nndeploy::preprocess::ConvertTo";
    param_ = std::make_shared<ConvertToParam>();
    this->setInputTypeInfo<device::Tensor>();
    this->setOutputTypeInfo<device::Tensor>();
  }
  ConvertTo(const std::string &name, std::vector<dag::Edge *> inputs,
            std::vector<dag::Edge *> outputs)
      : dag::Node(name, inputs, outputs) {
    key_ = "nndeploy::preprocess::ConvertTo";
    param_ = std::make_shared<ConvertToParam>();
    this->setInputTypeInfo<device::Tensor>();
    this->setOutputTypeInfo<device::Tensor>();
  }
  virtual ~ConvertTo() {}

  virtual base::Status run();
};

}  // namespace preprocess
}  // namespace nndeploy

#endif /* _NNDEPLOY_PREPROCESS_CONVERT_TO_H_ */
