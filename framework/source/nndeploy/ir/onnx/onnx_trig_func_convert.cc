/**
 * 三角函数的转换
 */

#include <google/protobuf/message.h>
#include <google/protobuf/text_format.h>

#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/io/zero_copy_stream_impl.h"
#include "nndeploy/ir/ir.h"
#include "nndeploy/ir/onnx/onnx_interpret.h"

namespace nndeploy {
namespace ir {
namespace {
#define REGISTER_ONNX_OP_CONVERT_CLASS(OP_NAME, OP_TYPE)                   \
  class Onnx##OP_NAME##Convert : public OnnxOpConvert {                    \
   public:                                                                 \
    Onnx##OP_NAME##Convert() : OnnxOpConvert() {}                          \
    virtual ~Onnx##OP_NAME##Convert() {}                                   \
                                                                           \
    virtual std::shared_ptr<OpDesc> convert(                               \
        const onnx::NodeProto &onnx_node) {                                \
      std::shared_ptr<OpDesc> op_desc = std::make_shared<OpDesc>(OP_TYPE); \
      OnnxOpConvert::convert(onnx_node, op_desc);                          \
      return op_desc;                                                      \
    }                                                                      \
  };                                                                       \
                                                                           \
  REGISTER_ONNX_OP_CONVERT_IMPLEMENTION(#OP_NAME, Onnx##OP_NAME##Convert)
}  // namespace

REGISTER_ONNX_OP_CONVERT_CLASS(Sin, kOpTypeSin);
REGISTER_ONNX_OP_CONVERT_CLASS(Cos, kOpTypeCos);
REGISTER_ONNX_OP_CONVERT_CLASS(Tan, kOpTypeTan);
REGISTER_ONNX_OP_CONVERT_CLASS(Asin, kOpTypeAsin);
REGISTER_ONNX_OP_CONVERT_CLASS(Acos, kOpTypeAcos);
REGISTER_ONNX_OP_CONVERT_CLASS(Atan, kOpTypeAtan);
REGISTER_ONNX_OP_CONVERT_CLASS(Sinh, kOpTypeSinh);
REGISTER_ONNX_OP_CONVERT_CLASS(Cosh, kOpTypeCosh);
REGISTER_ONNX_OP_CONVERT_CLASS(Tanh, kOpTypeTanh);

}  // namespace ir
}  // namespace nndeploy