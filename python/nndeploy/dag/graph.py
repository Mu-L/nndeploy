import nndeploy._nndeploy_internal as _C
import nndeploy.base
import nndeploy.device
from typing import List, Union, Optional

from .base import EdgeTypeInfo
from .edge import Edge
from .node import Node, NodeDesc


class Graph(_C.dag.Graph):
    def __init__(self, name: str, inputs: Union[Edge, List[Edge]] = None, outputs: Union[Edge, List[Edge]] = None):
        """
        初始化 Graph 对象
        
        参数:
            name: 图名称
            inputs: 输入边或输入边列表
            outputs: 输出边或输出边列表
        """
        if inputs is None and outputs is None:
            super().__init__(name)
        elif isinstance(inputs, list) and isinstance(outputs, list):
            super().__init__(name, inputs, outputs)
        else:
            raise ValueError("无效的输入或输出类型")
        
    def set_input_type(self, input_type: type):
        """设置输入类型
        
        Args:
            input_type: 输入类型
            
        Returns:
            状态码
        """
        edge_type_info = EdgeTypeInfo()
        edge_type_info.set_type(input_type)
        return self.set_input_type_info(edge_type_info)

    def set_output_type(self, output_type: type):
        edge_type_info = EdgeTypeInfo()
        edge_type_info.set_type(output_type)
        return self.set_output_type_info(edge_type_info)

    def create_edge(self, name: str) -> Edge:
        """
        创建一个边
        
        参数:
            name: 边名称
        返回:
            Edge 对象
        """
        return super().create_edge(name)

    def add_edge(self, edge: Edge):
        """
        添加一个边
        
        参数:
            edge: Edge 对象
        """
        return super().add_edge(edge)

    def update_edge(self, edge_wrapper: Edge, edge: Edge, is_external: bool = True):
        """
        更新边
        
        参数:
            edge_wrapper: 边包装器
            edge: 边对象
            is_external: 是否为外部边
        """
        return super().update_edge(edge_wrapper, edge, is_external)

    def get_edge(self, name: str) -> Edge:
        """
        通过名称获取边
        
        参数:
            name: 边名称
        返回:
            Edge 对象
        """
        return super().get_edge(name)

    def create_node(self, key_or_desc: Union[str, NodeDesc], name: str = "") -> Node:
        """
        创建节点
        
        参数:
            key_or_desc: 节点key或节点描述对象
            name: 节点名称,仅当key_or_desc为str时有效,默认为空字符串
        返回:
            Node 对象
        """
        if isinstance(key_or_desc, str):
            return super().create_node(key_or_desc, name)
        elif isinstance(key_or_desc, NodeDesc):
            return super().create_node(key_or_desc)
        else:
            raise ValueError("无效的节点描述对象")
        
    def set_node_desc(self, node: Node, desc: NodeDesc):
        """
        设置节点描述
        
        参数:
            node: 节点对象
            desc: 节点描述对象
            
        """
        return super().set_node_desc(node, desc)

    def add_node(self, node: Node):
        """
        添加节点
        
        参数:
            node: Node 对象
        """
        return super().add_node(node)

    def set_node_param(self, node_name: str, param: nndeploy.base.Param):
        """
        设置节点参数
        
        参数:
            node_name: 节点名称
            param: 参数对象
        """
        return super().set_node_param(node_name, param)

    def get_node_param(self, node_name: str) -> nndeploy.base.Param:
        """
        获取节点参数
        
        参数:
            node_name: 节点名称
        返回:
            参数对象
        """
        return super().get_node_param(node_name)

    def set_graph_node_share_stream(self, flag: bool):
        """
        设置图节点流共享标志
        
        参数:
            flag: 标志值
        """
        return super().set_graph_node_share_stream(flag)

    def get_graph_node_share_stream(self) -> bool:
        """
        获取图节点流共享标志
        
        返回:
            流共享标志
        """
        return super().get_graph_node_share_stream()

    def update_node_io(self, node: Node, inputs: List[Edge], outputs: List[str]):
        """
        更新节点输入和输出
        
        参数:
            node: 节点对象
            inputs: 输入边列表
            outputs: 输出边名称列表
        """
        return super().update_node_io(node, inputs, outputs)

    def init(self):
        """初始化图"""
        return super().init()

    def deinit(self):
        """反初始化图"""
        return super().deinit()

    def run(self):
        """运行图"""
        return super().run()

    def __call__(self, inputs):
        """
        调用图
        
        参数:
            inputs: 输入
        """
        return super().__call__(inputs)

    def dump(self):
        """输出图信息到标准输出"""
        return super().dump()
    
    def set_trace_flag(self, flag: bool):
        """
        设置追踪标志
        
        参数:
            flag: 追踪标志
        """
        return super().set_trace_flag(flag)
        
    def trace(self, inputs: List[Edge]) -> List[Edge]:
        """
        追踪图的执行流程
        
        参数:
            inputs: 输入边列表
            
        返回:
            追踪后的边列表
        """
        return super().trace(inputs)
        
    def serialize(self) -> str:
        return super().serialize()
        
    def deserialize(self, json_str: str):
        return super().deserialize(json_str)
