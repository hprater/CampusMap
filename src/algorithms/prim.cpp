//Hayden Prater
//010931631

#include <graph.hpp>
#include <sort.hpp>
#include <disjoint_set.hpp>
#include <queue>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};

std::vector<Edge> constructMSTPrim(Graph G) {
    std::vector<Edge> edges = G.exportEdges(); // Graph's edges

        //Code
    std::vector<int> distance(G.n, INT_MAX);
    std::vector<int> parent(G.n, -1);
    std::vector<bool> T(G.n, false);

    for (int i = 0; i < G.e[0].size(); ++i) {
        int v = G.e[0][i].v;
        int w = G.e[0][i].w;
        distance[v] = w;
        parent[v] = 0;
    }

    T[0] = true;
    std::vector<Edge> MST;
    for (int idx = 0; idx < G.n - 1; ++idx) {
        int min = INT_MAX, u;
        for (int i = 0; i < G.n; ++i)
            if (distance[i] < min && T[i] == false) {
                min = distance[i];
                u = i;
            }
        MST.push_back(Edge(u, parent[u], distance[u]));
        T[u] = true;
        for (int i = 0; i < G.e[u].size(); ++i) {
            int v = G.e[u][i].v;
            int w = G.e[u][i].w;
            if (w < distance[v]) {
                distance[v] = w;
                parent[v] = u;
            }
        }
    }

    return MST;
}

