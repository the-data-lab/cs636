#include <pybind11/pybind11.h>
#include<pybind11/numpy.h>
#include <iostream>

namespace py = pybind11;
using std::cout;
using std::endl;

//#include "kernel.h"
#include "csr.h"

//#include "capsule_to_array.h"
//#include "generated_pybind.h"

void run_bfs(graph_t& graph, vid_t root);

PYBIND11_MODULE(kernel, m) {

  py::class_<graph_t>(m, "graph_t")
    .def(py::init<>())
     
    .def("get_vcount", &graph_t::get_vcount)
    .def("get_edge_count", &graph_t::get_edge_count)
    
    .def("run_bfs",
        [](graph_t& graph, vid_t root) {
            run_bfs(graph, root);
        }
    )
    ;
    
    
  m.def("init_graph",
      [](py::array offset_csr, py::array nebrs_csr, py::array offset_csc, py::array nebrs_csc, int64_t flag, int64_t num_vcount) {
           graph_t* graph =  new graph_t;
           //cout<< offset_csr.shape(0) - 1<< "num_vcount"<< endl;
           graph->init(offset_csr.shape(0) - 1, nebrs_csr.itemsize(), 
                 offset_csr.request().ptr, nebrs_csr.request().ptr,
                 offset_csc.request().ptr, nebrs_csc.request().ptr, flag, num_vcount);
           return graph;
      }
  );
    
  //export_kernel(m);
}
