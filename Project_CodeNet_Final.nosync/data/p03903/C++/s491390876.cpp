#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class union_find {
public:
    union_find(int n) : par(n, -1) {}

    int root(int x) {
        return par[x] < 0 ? x : par[x] = root(par[x]);
    }

    bool unite(int x, int y) {
        x = root(x), y = root(y);
        if(x == y) return false;
        if(par[x] < par[y]) std::swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

private:
    std::vector<int> par;
};

struct edge {
    int from, to;
    ll cost;
    edge(int f, int t, ll c) : from(f), to(t), cost(c) {}

    bool operator<(const edge& that) const {
        return cost < that.cost;
    }
};

using edges = vector<edge>;
using graph = vector<edges>;

constexpr int inf = 1e9;

int main() {
    int n, m; cin >> n >> m;
    edges es;
    for(int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        es.emplace_back(a - 1, b - 1, c);
    }
    sort(begin(es), end(es));

    union_find uf(n);
    graph g(n);
    ll ans = 0;
    for(const auto& e : es) {
        if(uf.unite(e.from, e.to)) {
            ans += e.cost;
            g[e.from].emplace_back(e.from, e.to, e.cost);
            g[e.to].emplace_back(e.to, e.from, e.cost);
        }
    }

    vector<vector<int>> ma(n, vector<int>(n, inf));
    for(int s = 0; s < n; ++s) {
        function<void(int, int, int)> dfs = [&] (int v, int p, int cur) {
            ma[s][v] = cur;
            for(auto const& e : g[v]) {
                if(e.to == p) continue;
                dfs(e.to, v, max(cur, (int)e.cost));
            }
        };
        dfs(s, -1, 0);
    }

    int q; cin >> q;
    while(q--) {
        int s, t; cin >> s >> t;
        cout << ans - ma[s - 1][t - 1] << endl;
    }
}