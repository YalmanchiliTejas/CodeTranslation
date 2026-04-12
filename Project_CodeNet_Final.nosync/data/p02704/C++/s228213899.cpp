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
    void add_edge(const TEdge& e) {
        adj[e.u].push_back(edges.size());
        edges.push_back(e);
        if(not Directed) {
            adj[e.v].push_back(edges.size());
            edges.push_back(e.reverse());
        }
    }
};
template <typename T> struct fedge {
    int u, v; T c, f;
    T resid() { return c - f; }
    fedge reverse() const { return {v, u, 0, 0}; }
    friend ostream& operator<<(ostream& os, const fedge& e) {
        return os << "{u: " << e.u << ", v: " << e.v << ", c: " << e.c << ", f: " << e.f << "}";
    }
};
template <typename T, bool Index> using flow_graph = graph<0, fedge<T>, Index>;
template <typename T, bool Index> T max_flow(flow_graph<T, Index>& g, int s, int t) {
    vector<int> d(g.adj.size()), adj_ptr(g.adj.size());
    auto make_level_graph = [&]() {
        fill(d.begin(), d.end(), -1);
        d[s] = 0;
        queue<int> q({s});
        while(not q.empty()) {
            int u = q.front(); q.pop();
            for(int e : g[u]) {
                if(g(e).resid() > 0 and d[g(e).v] == -1) {
                    d[g(e).v] = d[g(e).u] + 1;
                    q.push(g(e).v);
                }
            }
        }
        return d[t] != -1;
    };
    function<T(int, T)> augment = [&](int u, T b) {
        if(u == t) return b;
        for(int& j = adj_ptr[u]; j < g[u].size(); j++) {
            fedge<T>& e = g(g[u][j]);
            if(T df; d[e.v] == d[u] + 1 and e.resid() > 0 and (df = augment(e.v, min(b, e.resid())))) {
                e.f += df, g(g[u][j] ^ 1).f -= df;
                return df;
            }
        }
        return T(0);
    };
    T ans = 0;
    while(make_level_graph()) {
        fill(adj_ptr.begin(), adj_ptr.end(), 0);
        while(T df = augment(s, numeric_limits<T>::max())) {
            ans += df;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> S(n), T(n);
    vector<bitset<64>> U(n), V(n);
    cin >> S >> T;
    for(int i = 0; i < n; i++) {
        unsigned long long ui;
        cin >> ui;
        U[i] = bitset<64>(ui);
    }
    for(int i = 0; i < n; i++) {
        unsigned long long vi;
        cin >> vi;
        V[i] = bitset<64>(vi);
    }
    vector<vector<bitset<64>>> ans(n, vector<bitset<64>>(n));
    auto row_node = [&](int row) { return row; };
    auto col_node = [&](int col) { return n + col; };
    auto real_s_row_edge = [&](int row) { return 2 * (2 * row + 0); };
    auto circ_s_row_edge = [&](int row) { return 2 * (2 * row + 1); };
    auto col_real_t_edge = [&](int col) { return 2 * (2 * n + 2 * col + 0); };
    auto col_circ_t_edge = [&](int col) { return 2 * (2 * n + 2 * col + 1); };
    auto cross_edge = [&](int row, int col) { return 2 * (4 * n + row * n + col); };
    int circ_s_real_t_edge = cross_edge(n - 1, n - 1) + 2;
    int real_s_circ_t_edge = cross_edge(n - 1, n - 1) + 4;
    int circ_s = 2 * n, circ_t = 2 * n + 1, real_s = 2 * n + 2, real_t = 2 * n + 3;
    graph<0, fedge<int>, 0> g(2 * n + 4);
    for(int row = 0; row < n; row++) {
        g.add_edge({real_s, row_node(row)});
        g.add_edge({circ_s, row_node(row)});
    }
    for(int col = 0; col < n; col++) {
        g.add_edge({col_node(col), real_t});
        g.add_edge({col_node(col), circ_t});
    }
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            g.add_edge({row_node(row), col_node(col), 1});
        }
    }
    g.add_edge({circ_s, real_t});
    g.add_edge({real_s, circ_t});
    g.add_edge({circ_t, circ_s, n * n});
    bool can = true;
    for(int b = 0; b < 64 and can; b++) {
        g(circ_s_real_t_edge).c = g(real_s_circ_t_edge).c = 0;
        for(int row = 0; row < n; row++) {
            if(S[row] == 0 and U[row][b] == 0) {
                g(circ_s_row_edge(row)).c = n - 1;
                g(circ_s_real_t_edge).c += g(real_s_row_edge(row)).c = 0;
            } else if(S[row] == 0 and U[row][b] == 1) {
                g(circ_s_row_edge(row)).c = 0;
                g(circ_s_real_t_edge).c += g(real_s_row_edge(row)).c = n;
            } else if(S[row] == 1 and U[row][b] == 0) {
                g(circ_s_row_edge(row)).c = 0;
                g(circ_s_real_t_edge).c += g(real_s_row_edge(row)).c = 0;
            } else {
                g(circ_s_row_edge(row)).c = n - 1;
                g(circ_s_real_t_edge).c += g(real_s_row_edge(row)).c = 1;
            }
        }
        for(int col = 0; col < n; col++) {
            if(T[col] == 0 and V[col][b] == 0) {
                g(col_circ_t_edge(col)).c = n - 1;
                g(real_s_circ_t_edge).c += g(col_real_t_edge(col)).c = 0;
            } else if(T[col] == 0 and V[col][b] == 1) {
                g(col_circ_t_edge(col)).c = 0;
                g(real_s_circ_t_edge).c += g(col_real_t_edge(col)).c = n;
            } else if(T[col] == 1 and V[col][b] == 0) {
                g(col_circ_t_edge(col)).c = 0;
                g(real_s_circ_t_edge).c += g(col_real_t_edge(col)).c = 0;
            } else {
                g(col_circ_t_edge(col)).c = n - 1;
                g(real_s_circ_t_edge).c += g(col_real_t_edge(col)).c = 1;
            }
        }
        for(auto& e : g.edges) {
            e.f = 0;
        }
        can &= max_flow(g, real_s, real_t) == g(circ_s_real_t_edge).c + g(real_s_circ_t_edge).c;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                ans[row][col][b] = g(cross_edge(row, col)).f;
            }
        }
    }
    if(can) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j) cout << " ";
                cout << ans[i][j].to_ullong();
            }
            cout << endl;
        }
        for(int i = 0; i < n; i++) {
            bitset<64> row_acc = 0;
            if(not S[i]) row_acc.flip();
            for(int j = 0; j < n; j++) {
                if(S[i]) {
                    row_acc |= ans[i][j];
                } else {
                    row_acc &= ans[i][j];
                }
            }
            assert(row_acc == U[i]);
        }
        for(int j = 0; j < n; j++) {
            bitset<64> col_acc = 0;
            if(not T[j]) col_acc.flip();
            for(int i = 0; i < n; i++) {
                if(T[j]) {
                    col_acc |= ans[i][j];
                } else {
                    col_acc &= ans[i][j];
                }
            }
            assert(col_acc == V[j]);
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}
