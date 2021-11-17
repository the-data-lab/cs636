#pragma once

#include "csr.h"
#include "op.h"

extern int THD_COUNT;
    
void run_bfs(graph_t& g, vid_t root);
