#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

struct edge {
    typedef size_t weight_type;

    size_t m_to;

    edge(size_t to) : m_to(to) { }

    inline size_t to() const { return m_to; }

    inline weight_type weight() const { return 1; }

    friend std::ostream& operator<<(std::ostream &os, const edge &e) {
        os << "{ to: " << e.m_to << " }";
        return os;
    }
};

template <typename Weight>
struct weighted_edge : public edge {
    typedef Weight weight_type;

    weight_type m_weight;

    weighted_edge(size_t to, weight_type weight) : edge(to), m_weight(weight) { }

    inline weight_type weight() const { return m_weight; }

    friend std::ostream& operator<<(std::ostream &os, const weighted_edge &e) {
        os << "{ to: " << e.m_to << ", weight = " << e.m_weight << " }";
        return os;
    }
};

template <class Edge>
struct graph {
    typedef Edge edge_type;

    size_t m_n_vertices;
    std::vector<std::vector<edge_type>> m_edges;

    graph(size_t n_vertices) : m_n_vertices(n_vertices), m_edges(n_vertices) { }

    inline size_t n_vertices() const { return m_n_vertices; }

    inline void add_edge(size_t from, size_t to, typename edge_type::weight_type weight) {
        m_edges[from].emplace_back(to, weight);
    }

    inline void add_edge(size_t from, size_t to) {
        m_edges[from].push_back(to);
    }

    inline void add_edge(size_t from, const edge_type &e) {
        m_edges[from].emplace_back(e);
    }

    inline void add_biedge(size_t v0, size_t v1, typename edge_type::weight_type weight) {
        m_edges[v0].emplace_back(v1, weight);
        m_edges[v1].emplace_back(v0, weight);
    }

    inline void add_biedge(size_t v0, size_t v1) {
        m_edges[v0].push_back(v1);
        m_edges[v1].push_back(v0);
    }

    inline std::vector<edge_type> edges_from(size_t v) const {
        return m_edges[v];
    }
};

template <class Graph>
vector<typename Graph::edge_type::weight_type> tree_height(const Graph &g) {
    using Edge = typename Graph::edge_type;
    using Weight = typename Edge::weight_type;

    const size_t n_vertices = g.n_vertices();
    const size_t NIL = n_vertices;

    vector<Weight> longests(n_vertices);
    vector<Weight> second_longests(n_vertices);

    function<Weight(size_t, size_t)> dfs_longest = [&](size_t u, size_t parent) {
        Weight longest = 0;
        Weight second_longest = 0;
        for (Edge e: g.edges_from(u)) {
            size_t v = e.to();
            if (v == parent) {
                continue;
            }
            Weight weight = e.weight();
            Weight length = weight + dfs_longest(v, u);
            if (longest < length) {
                second_longest = longest;
                longest = length;
            } else if (second_longest < length) {
                second_longest = length;
            }
        }
        second_longests[u] = second_longest;
        return longests[u] = longest;
    };

    dfs_longest(0, NIL);

    vector<Weight> heights(n_vertices);

    function<void(size_t, size_t, Weight)> dfs_height = [&](size_t u, size_t parent, Weight parent_longest) {
        for (Edge e: g.edges_from(u)) {
            size_t v = e.to();
            if (v == parent) {
                continue;
            }
            Weight weight = e.weight();
            Weight length = weight + longests[v];
            Weight sibling_longest = weight + longests[v] == longests[u] ? second_longests[u] : longests[u];
            dfs_height(v, u, weight + max(parent_longest, sibling_longest));
        }
        heights[u] = max(longests[u], parent_longest);
    };

    dfs_height(0, NIL, 0);

    return heights;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    using Edge = weighted_edge<int>;
    using Graph = graph<Edge>;

    int n;
    cin >> n;
    Graph g(n);
    REP(i, n - 1) {
        int s, t, w;
        cin >> s >> t >> w;
        g.add_biedge(s, t, w);
    }

    auto height = tree_height(g);

    REP(i, n) {
        cout << height[i] << '\n';
    }
    cout << flush;

    return 0;
}
