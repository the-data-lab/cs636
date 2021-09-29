#include <cassert>
#include <iostream>
#include "csr.h"

using std::cout;
using std::endl;


void run_bfs(graph_t& g, vid_t root)
{
    csr_t* csr = &g.csr;
    csr_t* csc = &g.csc;
    
    //TODO
		
    cout << "root = " << root << endl; 
    //print bfs tree here
    //i.e. how many vertex in each level
}
