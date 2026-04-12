#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

template <class T>
using lp_queue=priority_queue<T, deque<T>, greater<T>>;

using Weight=long long;
static const Weight INF=1LL<<57;

struct Edge {
    size_t src, dst;
    Weight weight;
    Edge() {}
    Edge(size_t src, size_t dst, Weight weight=1):
        src(src), dst(dst), weight(weight)
    {}
};

bool operator<(const Edge &e, const Edge &f) {
    if (e.weight != f.weight) {
        return e.weight > f.weight;
    } else {
        return e.src!=f.src? e.src<f.src : e.dst<f.dst;
    }
}

using Edges=vector<Edge>;
using Vertex=vector<Edge>;
using Graph=vector<Vertex>;

void join(Graph &g, size_t s, size_t d, Weight w=1) {
    // non-directed
    g[s].push_back(Edge(s, d, w));
    g[d].push_back(Edge(d, s, w));
}

void connect(Graph &g, size_t s, size_t d, Weight w=1) {
    // directed
    g[s].push_back(Edge(s, d, w));
}

Weight visit(const Graph &g, Graph &h, size_t i, size_t j) {
    if (h[i][j].weight >= 0) return h[i][j].weight;

    h[i][j].weight = g[i][j].weight;
    size_t u=h[i][j].dst;
    for (size_t k=0; k<h[u].size(); ++k) {
        if (h[u][k].dst == i) continue;
        h[i][j].weight = max(h[i][j].weight, visit(g, h, u, k)+g[i][j].weight);
    }

    return h[i][j].weight;
}

vector<Weight> get_treeheight(const Graph &g) {
    size_t V=g.size();
    Graph h(g);
    for (size_t i=0; i<V; ++i)
        for (Edge &e: h[i])
            e.weight = -INF;

    for (size_t i=0; i<V; ++i)
        for (size_t j=0; j<h[i].size(); ++j)
            if (h[i][j].weight < 0)
                h[i][j].weight = visit(g, h, i, j);

    vector<Weight> height(V);
    for (size_t i=0; i<V; ++i)
        for (Edge &e: h[i])
            height[i] = max(height[i], e.weight);

    return height;
}

int main() {
    size_t V, E;
    scanf("%zu", &V);
    E = V-1;

    Graph g(V);
    for (size_t i=0; i<E; ++i) {
        size_t s, t, w;
        scanf("%zu %zu %lld", &s, &t, &w);

        join(g, s, t, w);
    }

    vector<Weight> height=get_treeheight(g);

    for (Weight w: height)
        printf("%lld\n", w);

    return 0;
}