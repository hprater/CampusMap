//Hayden Prater
//010931631

#include <graph.hpp>
#include <sort.hpp> 
#include <disjoint_set.hpp>


std::vector<Edge> constructMSTKruskal(Graph G) {
    std::vector<Edge> edges = G.exportEdges(); // Graph's edges
    
    //Code
    int n = G.n;
    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < G.e[u].size(); i += 1)
            edges.push_back(Edge(G.e[u][i]));
    }

    std::vector<int> parent(n, -1);
    sort(edges, 0, edges.size()-1);

    std::vector<Edge> MST;
    DisjointSet djs (G.n);

    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        int value = djs.isOnSameSet(u, v);
        if (value != 1){
            djs.join(u,v);
            MST.push_back(Edge(edges[i]));
        }
    }
    return MST;
}

