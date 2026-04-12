#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <typename X, typename Y> istream& operator>>(istream& is, pair<X, Y>& p) { return is >> p.first >> p.second; }
template <bool Directed, typename TEdge, bool Index> struct graph {
    using EType = TEdge;
    vector<TEdge> edges;
    vector<vector<int>> adj;
    graph(int n) : adj(n + Index) {}
    graph(int n, int m) : graph(n) { edges.reserve(m << not Directed); }
    TEdge& operator()(int e) { return edges[e]; }
    vector<int>& operator[](int u) { return adj[u]; }
    int size() { return adj.size() - Index; }
    void append(int u, const TEdge& e) {
        adj[u].push_back(edges.size());
        edges.push_back(e);
    }
    void add_edge(const TEdge& e) {
        append(e.u, e);
        if(not Directed) append(e.v, e.reverse());
    }
};
template <typename T> struct wedge {
    int u, v; T w;
    wedge reverse() const { return {v, u, w}; }
    friend ostream& operator<<(ostream& os, const wedge& e) {
        return os << "{u: " << e.u << ", v: " << e.v << ", w: " << e.w << "}";
    }
};
template <bool Directed, typename T, bool Index>
pair<T, vector<int>> mst(graph<Directed, wedge<T>, Index>& g, int s = Index) {
    vector<int> vis(g.adj.size()), p(g.adj.size(), -1);
    vector<T> d(g.adj.size(), lim<T>::max());
    priority_queue<pair<T, int>> pq({}, {{d[s] = 0, s}});
    while(not pq.empty()) {
        int u = pq.top().second; pq.pop();
        if(not vis[u]) {
            vis[u] = true;
            for(int e : g[u]) {
                if(not vis[g(e).v] and d[g(e).v] > g(e).w) {
                    pq.push({-(d[g(e).v] = g(e).w), g(p[g(e).v] = e).v});
                }
            }
        }
    }
    return {accumulate(d.begin() + Index, d.end(), T(0)), p};
}
template <typename T> pair<vector<T>, vector<T>> compress(const vector<T>& a) {
    vector<T> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    vector<T> compressed = a;
    for(T& val : compressed) {
        val = lower_bound(vals.begin(), vals.end(), val) - vals.begin();
    }
    return {vals, compressed};
}
void solve(long long N, std::vector<long long> x, std::vector<long long> y) {
    auto cx = compress(x);
    auto cy = compress(y);
    graph<0, wedge<ll>, 0> g(N + cx.first.size() + cy.first.size());
    for(int i = 0; i < N; i++) {
        g.add_edge({i, N + cx.second[i], 0});
        g.add_edge({i, N + cx.first.size() + cy.second[i], 0});
    }
    for(int i = 1; i < cx.first.size(); i++) {
        g.add_edge({N + i, N + i - 1, cx.first[i] - cx.first[i - 1]});
    }
    for(int i = 1; i < cy.first.size(); i++) {
        g.add_edge({N + cx.first.size() + i, N + cx.first.size() + i - 1, cy.first[i] - cy.first[i - 1]});
    }
    cout << mst(g).first << endl;
}
int main() {
    long long N;
    scanf("%lld",&N);
    std::vector<long long> x(N);
    std::vector<long long> y(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
    }
    solve(N, std::move(x), std::move(y));
    return 0;
}
