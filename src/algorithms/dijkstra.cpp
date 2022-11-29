//Hayden Prater
//010931631

#include <graph.hpp>
#include <queue>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};

std::vector<int> searchShortestPath(Graph &G, int start, int destination) {
    // YOUR CODE HERE
    std::vector<int> distance(G.n, INT_MAX);
    std::vector<int> parent(G.n, -1);

    distance[start] = 0;
    parent[start] = -1;

    for (int idx = 0; idx < G.n; ++idx) {
        int min = INT_MAX, u;
        for (int i = 0; i < G.n; ++i)
            if (distance[i] < min && !G.isVisited(i)) {
                min = distance[i];
                u = i;
            }
        G.setVisited(u);

        if (u == destination)
            break;

        for (int i = 0; i < G.e[u].size(); ++i) {
            int v = G.e[u][i].v;
            int w = G.e[u][i].w;
            if(G.isVisited(v))
                continue;
            if (distance[u] + w < distance[v]) {
                distance[v] = w + distance[u];
                parent[v] = u;
            }
        }
    }

    std::vector<int> path;
    int u = destination;
    while (u != -1) {
        path.push_back(u);
        u = parent[u];
    }
    std::reverse(path.begin(), path.end());
    return path;
}
