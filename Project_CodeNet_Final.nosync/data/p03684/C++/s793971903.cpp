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

class CommonGraph {
    using ll = long long;
public:
    struct Edge {
        enum class Type { Directed, Undirected };
        int src, dst; ll cost;
        Edge() = default;
        Edge(const int& _src, const int& _dst, const ll& _cost = 0) :
            src(_src), dst(_dst), cost(_cost) { }
        friend std::ostream& operator <<(std::ostream& os, const Edge& e) {
            os << "src : " << e.src << ", " << "dst : " << e.dst << ", " << "cost : " << e.cost;
            return os;
        }
    };

    struct Vertex {
        ll cost;
        Vertex(const ll& _cost) : cost(_cost) { }
    };

    CommonGraph(const int&        num_vertex,
                const Edge::Type& edge_type,
                const ll&         inf_val = (ll)1e18 + 1) :
        vertex_(num_vertex, inf_val),
        edge_(num_vertex),
        num_edge_(0),
        total_cost_(0),
        edge_type_(edge_type) { }

    const ll& getTotalCost() const { return total_cost_; }
    const std::vector<Vertex>& getVertex() const { return vertex_; }
    const std::vector<std::vector<Edge>>& getEdge() const { return edge_; }

    void addEdge(const int& src, const int& dst, const ll& cost = 1) {
        edge_[src].emplace_back(src, dst, cost);
        if(edge_type_ == Edge::Type::Undirected) edge_[dst].emplace_back(dst, src, cost);
        num_edge_++;
        total_cost_ += cost;
    }

    /**
     *  DFSテンプレート
     *  例: 木における全ての頂点に対するある頂点からの最短距離
     */
    void dfs(const int& index,
             const ll&  inf_val = (ll)1e18 + 1) {
        std::fill(vertex_.begin(), vertex_.end(), inf_val);
        for(const auto& edge : edge_[index]) {
            if(vertex_[edge.dst].cost == inf_val) {
                vertex_[edge.dst].cost = vertex_[edge.src].cost + edge.cost;
                dfs(edge.dst, inf_val);
            }
        }
    }

    /**
     *  全ての頂点に対してある頂点からの最短経路を求める(Bellman-Ford法)
     *  NOTE: 計算量O(|V||E|), 始点と非連結の頂点はLINFとする
     *  @start_index: 始点
     *  @Return: 解が求まればtrueを返す 負の閉路が存在する場合falseを返す
     */
    bool calcMinCostByBellmanFord(const int&  start_index,
                                  const bool& init_vertex = true,
                                  const ll&   inf_val = (ll)1e18 + 1) {
        if(init_vertex) std::fill(vertex_.begin(), vertex_.end(), inf_val);
        vertex_[start_index].cost = 0; size_t cnt = 0;
        while(true) {
            bool update = false;
            for(size_t i = 0; i < vertex_.size(); i++) {
                for(const auto& edge : edge_[i]) {
                    if(vertex_[edge.src].cost != inf_val) {
                        auto cost = vertex_[edge.src].cost + edge.cost;
                        if(cost < vertex_[edge.dst].cost) {
                            vertex_[edge.dst].cost = cost; update = true;
                        }
                    }
                }
            }
            if(!update) break;
            if(cnt == vertex_.size() - 1) return false;
            cnt++;
        }
        return true;
    }

    /**
     *  全ての頂点に対してある頂点からの最短経路を求める(dijkstra法)
     *  NOTE: 計算量O(|E|log|V|), 始点と非連結の頂点はLINFとする
     *  @start_index: 始点
     *  @Return: void
     */
    void calcMinCostByDijkstra(const int&  start_index,
                               const bool& init_vertex = true,
                               const ll&   inf_val     = (ll)1e18 + 1) {
        using pll = std::pair<ll, ll>;
        if(init_vertex) std::fill(vertex_.begin(), vertex_.end(), inf_val);
        vertex_[start_index].cost = 0;
        std::priority_queue<pll, std::vector<pll>, std::greater<pll>> pq;
        pq.emplace(0, start_index);
        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            if(vertex_[top.second].cost < top.first) continue;
            for(const auto& edge : edge_[top.second]) {
                auto cost = vertex_[top.second].cost + edge.cost;
                if(cost < vertex_[edge.dst].cost) {
                    vertex_[edge.dst].cost = cost;
                    pq.emplace(vertex_[edge.dst].cost, edge.dst);
                }
            }
        }
    }

    /**
     *  最小全域木を求める(Kruskal法)
     *  NOTE: 計算量O(|E|log|V|)
     *  @Return: 最小全域木を返す グラフが非連結の場合、連結成分ごとに最小全域木を構成する
     */
    CommonGraph generateMinimumSpanningTree() {
        if(edge_type_ != Edge::Type::Undirected) { throw std::logic_error("Graph type is invalid"); }
        CommonGraph mst(vertex_.size(), Edge::Type::Undirected);
        std::vector<Edge> mst_e; mst_e.reserve(num_edge_ * 2);
        for(const auto& edges : edge_) for(const auto& edge : edges) mst_e.push_back(edge);
        sort(mst_e.begin(), mst_e.end(), [](const Edge& l, const Edge& r) { return l.cost < r.cost; });
        struct UF {
            struct N{ll p,r;N(const ll&_p=0,const ll&_r=0):p(_p),r(_r){}};std::vector<N>n;
            explicit UF(const ll&nn){n.reserve(nn);for(ll i=0;i<nn;i++){n.emplace_back(i);}}
            ll R(const ll&x){return(n[x].p==x)?x:n[x].p=R(n[x].p);} void U(const ll&x,const ll&y)
            {ll w=R(x);ll z=R(y);if(w!=z){if(n[w].r<n[z].r)std::swap(w,z);n[z].p=w;
            if(n[w].r==n[z].r)n[w].r++;}}bool S(const ll&x,const ll&y){return R(x)==R(y);}
        };
        UF uf(vertex_.size());
        for(const auto& e : mst_e)
        { if(!uf.S(e.src, e.dst)) { mst.addEdge(e.src, e.dst, e.cost); uf.U(e.src, e.dst); } }
        return mst;
    }

    /**
     *  全頂点間の最短距離を求める(Warshall-Floyd法)
     *  NOTE: 計算量O(|V|^3)
     *  @Return: array[i][j] :: 頂点iから頂点jまでの最短距離
     */
    std::vector<std::vector<ll>> calcMinCostBetweenAllVertices(const ll& inf_val = (ll)1e18 + 1) {
        std::vector<std::vector<ll>> dp(vertex_.size(), std::vector<ll>(vertex_.size(), inf_val));
        for(const auto& v : edge_) for(const auto& e : v) dp[e.src][e.dst] = e.cost;
        for(size_t i = 0; i < vertex_.size(); i++)
            for(size_t j = 0; j < vertex_.size(); j++)
                for(size_t k = 0; k < vertex_.size(); k++)
                    dp[j][k] = std::min(dp[j][k], dp[j][i] + dp[i][k]);
        return dp;
    }

    friend std::ostream& operator <<(std::ostream& os, const CommonGraph& g) {
        for(const auto& v : g.edge_) { for(const auto& e : v) { os << "[" << e << "]" << std::endl; } }
        return os;
    }

private:
    std::vector<Vertex>            vertex_;
    std::vector<std::vector<Edge>> edge_;
    ll                             num_edge_;
    ll                             total_cost_;
    const Edge::Type               edge_type_;
};

int main() {
    try {
        cin.tie(0);
        ios::sync_with_stdio(false);

        int N;
        std::cin >> N;

        vector<pair<pair<int, int>, int>> city_prior_x;
        vector<pair<pair<int, int>, int>> city_prior_y;
        REP(i, N) {
            int x, y;
            std::cin >> x >> y;
            city_prior_x.emplace_back(make_pair(x, y), i);
            city_prior_y.emplace_back(make_pair(y, x), i);
        }

        CommonGraph g(N, CommonGraph::Edge::Type::Undirected);

        sort(ALL(city_prior_x));
        sort(ALL(city_prior_y));
        for(int i = 0; i < N - 1; i++) {
            g.addEdge(city_prior_x[i].second,
                      city_prior_x[i + 1].second,
                      min(abs(city_prior_x[i].first.first  - city_prior_x[i + 1].first.first),
                          abs(city_prior_x[i].first.second - city_prior_x[i + 1].first.second)));
            g.addEdge(city_prior_y[i].second,
                      city_prior_y[i + 1].second,
                      min(abs(city_prior_y[i].first.first  - city_prior_y[i + 1].first.first),
                          abs(city_prior_y[i].first.second - city_prior_y[i + 1].first.second)));
        }

        auto mst = g.generateMinimumSpanningTree();
        std::cout << mst.getTotalCost() << std::endl;
    }
    catch(const exception& e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
    return 0;
}
