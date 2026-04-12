#include <bits/stdc++.h>
using namespace std;
#define int long long
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;

struct LowestCommonAncestorTreeMax {
        const int LOGM = 30;
        vector<int> depth, par_w;
        vector<vector<int>> parent, parmax;
        LowestCommonAncestorTreeMax(int root, const vector<vector<pair<int, int>>> &g) {
                int n = g.size();
                depth.resize(n);
                par_w.resize(n);
                parent.resize(LOGM);
                parmax.resize(LOGM);
                for (int i = 0; i < LOGM; i ++) { 
                        parent[i].resize(n);
                        parmax[i].resize(n);
                }
                function<void (int, int, int)> dfs = [&](int u, int prev, int d) {
                        parent[0][u] = prev;
                        parmax[0][u] = par_w[u];
                        depth[u] = d;
                        for (auto e : g[u]) { 
                                int v = e.first;
                                if (v != prev) { 
                                        par_w[v] = e.second;
                                        dfs(v, u, d + 1);
                                }
                        }
                };
                dfs(root, -1, 0);
                for (int k = 0; k < LOGM - 1; k ++) {
                        for (int i = 0; i < n; i ++) {
                                if (parent[k][i] < 0) { 
                                        parent[k + 1][i] = -1;
                                } else { 
                                        parent[k + 1][i] = parent[k][parent[k][i]];
                                        if (parent[k + 1][i] >= 0) {
                                                parmax[k + 1][i] = max(parmax[k][i], parmax[k][parent[k][i]]);
                                        }
                                }
                        }
                }
        }
        int lca(int u, int v) { 
                if (depth[u] > depth[v]) swap(u, v);
                for (int k = 0; k < LOGM; k ++) {
                        if ((depth[v] - depth[u]) >> k & 1) { 
                                v = parent[k][v];
                        }
                }
                if (u == v) return u;
                for (int k = LOGM - 1; k >= 0; k --) {
                        if (parent[k][u] != parent[k][v]) {
                                u = parent[k][u];
                                v = parent[k][v];
                        }
                }
                return parent[0][u];
        }
        int dist(int u, int v) {
                return depth[u] + depth[v] - 2 * depth[lca(u, v)];
        }
        int getmax(int v, int ancestor) {
                int res = 0;
                int d = depth[v] - depth[ancestor];
                for (int k = 0; k < LOGM; k ++) {
                        if ((d >> k) & 1) {
                                res = max(res, parmax[k][v]);
                                v = parent[k][v];
                        }
                }
                return res;
        }
};

struct edge {
    int a, b, c;
};

vi par;

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}
bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return true;
    par[x] = y;
    return false;
}

signed main() {
    // freopen("/Users/xuzijian/atcoder/hoge/input", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);
    int n, m;
    cin >> n >> m;
    vector<edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges.push_back({a, b, c});
    }

    sort(edges.begin(), edges.end(), [](edge a, edge b) {return a.c < b.c;});
    par = vi(n + 1);
    iota(par.begin(), par.end(), 0);

    unordered_set<int> ns;

    vector<vector<pair<int, int>>> adj(n);
    i64 sum = 0;
    for (int i = 0; i < m; i++) {
        int x = edges[i].a, y = edges[i].b;
        if (!unite(x, y)) {
            ns.insert(x);
            ns.insert(y);
            assert(0 <= x && x < n && 0 <= y && y < n);
            adj[x].push_back(make_pair(y, edges[i].c));
            adj[y].push_back(make_pair(x, edges[i].c));
            sum += edges[i].c;
        }
    }

    LowestCommonAncestorTreeMax tree(0, adj);
    auto maxw = [&](int s, int t) {
        int lca = tree.lca(s, t);
        // cout << "lca" << lca << endl;
        // cout << s << " " << t << endl;
        return max(tree.getmax(s, lca), tree.getmax(t, lca));
    };

    int q;
    cin >> q;
    while (q--) {
        // cout << "hoge" << q << endl;
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        cout << sum - maxw(s, t) << endl;
    }
}
