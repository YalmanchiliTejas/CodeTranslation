#include <bits/stdc++.h>

#define TYPE(c)   remove_reference_t<decltype(c)>
#define REP(i, n) for(TYPE(n) i = 0; i < n; i++)
#define FOR(v, c) for(TYPE(c.begin()) v = c.begin(); v != c.end(); v++)
#define ALL(c)    c.begin(), c.end()
#define SORT(c)   sort(ALL(c))
#define RSORT(c)  sort(ALL(c), greater<TYPE(c)::value_type>())
#define UNIQUE(c) c.erase(unique(ALL(c)), c.end())

using namespace std;
using ll = long long;

constexpr int MOD  = (int)1e9 + 7;
constexpr int INF  = (int)1e9 + 1;
constexpr ll  LINF = (ll)1e18 + 1;

template<typename S, typename T> ostream& operator<<(ostream &os, const pair<S, T>& p)
{ return os << "(" << p.first << "," << p.second << ")"; }
template<typename T> auto operator<<(ostream& os, const T& t)
    -> typename conditional<true, ostream&, decltype(*t.begin())>::type
{ os << "["; FOR(v, t) { if(v != t.begin()) os << ","; os << *v; } os << "]"; return os; }

class Graph {
    using ll = long long;
public:
    struct Edge {
        enum class Type { Directed, Undirected };
        int  src, dst;
        ll   cost;
        bool validity;
        Edge(const int& _src, const int& _dst, const ll& _cost = 0) :
            src(_src), dst(_dst), cost(_cost), validity(true) { }
        friend std::ostream& operator <<(std::ostream& os, const Edge& e) {
            os << "src : " << e.src << ", " << "dst : " << e.dst << ", " << "cost : " << e.cost;
            return os;
        }
    };

    struct Vertex {
        ll cost;
        explicit Vertex(const ll& _cost) : cost(_cost) { }
    };

    Graph(const int&        num_vertex,
          const Edge::Type& edge_type,
          const ll&         vertex_init_cost = (ll)1e9 + 1) :
        vertices_(num_vertex, Vertex(vertex_init_cost)),
        edges_(num_vertex),
        num_vertex_(num_vertex),
        num_edge_(0),
        total_edge_cost_(0),
        total_vertex_cost_(num_vertex * vertex_init_cost),
        edge_type_(edge_type) { }

    const std::vector<Vertex>& getVertices() const { return vertices_; }
    const std::vector<std::vector<Edge>>& getEdges() const { return edges_; }
    const ll& getTotalEdgeCost() const { return total_edge_cost_; }
    const ll& getTotalVertexCost() const { return total_vertex_cost_; }
    const int& getNumVertex() const { return num_vertex_; }
    const int& getNumEdge() const { return num_edge_; }
    const Edge::Type& getEdgeType() const { return edge_type_; }

    void setCostToAllVertex(const ll& val) {
        total_vertex_cost_ = vertices_.size() * val;
        std::fill(vertices_.begin(), vertices_.end(), Vertex(val));
    };

    void setCostToSpecificVertex(const int& index, const ll& val) {
        total_vertex_cost_ += val - vertices_[index].cost;
        vertices_[index].cost = val;
    };

    int addVertex(const ll& cost = (ll)1e9 + 1) {
        vertices_.emplace_back(cost); edges_.emplace_back();
        total_vertex_cost_ += cost;
        return vertices_.size() - 1;
    }

    void addEdge(const int& src, const int& dst, const ll& cost = 1) {
        edges_[src].emplace_back(src, dst, cost);
        if(edge_type_ == Edge::Type::Undirected) edges_[dst].emplace_back(dst, src, cost);
        num_edge_++;
        total_edge_cost_ += cost;
    }

    void invalidateEdge(const int& src, const int& dst) {
        auto invalidate = [&](const int& src, const int& dst) -> ll {
                              for(auto& edge : edges_[src])
                                  if(edge.dst == dst) { edge.validity = false; return edge.cost; }
                              return 0LL;
                          };
        total_edge_cost_ -= invalidate(src, dst);
        if(edge_type_ == Edge::Type::Undirected) invalidate(dst, src);
        num_edge_--;
    }

    friend std::ostream& operator <<(std::ostream& os, const Graph& g) {
        for(const auto& v : g.edges_) { for(const auto& e : v) { os << "[" << e << "]" << std::endl; } }
        return os;
    }
private:
    std::vector<Vertex>            vertices_;
    std::vector<std::vector<Edge>> edges_;
    int                            num_vertex_;
    int                            num_edge_;
    ll                             total_edge_cost_;
    ll                             total_vertex_cost_;
    const Edge::Type               edge_type_;
};

int DFS(Graph&     g,
        const int& index) {
    auto& vs = g.getVertices();
    auto& es = g.getEdges();
    if(g.getTotalVertexCost() == g.getNumVertex()) return 1;

    auto ret = 0;
    for(const auto& e : es[index]) {
        if(vs[e.dst].cost == 0) {
            g.setCostToSpecificVertex(e.dst, 1);
            ret += DFS(g, e.dst);
            g.setCostToSpecificVertex(e.dst, 0);
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    Graph g(N, Graph::Edge::Type::Undirected, 0);
    REP(i, M) {
        int a, b;
        std::cin >> a >> b;
        g.addEdge(a - 1, b - 1, 1);
    }

    g.setCostToSpecificVertex(0, 1);
    std::cout << DFS(g, 0) << std::endl;

    return 0;
}
