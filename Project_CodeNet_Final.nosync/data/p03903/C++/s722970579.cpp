#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

struct UnionFind {
        int n;
        vector<int> parent;
        vector<int> rank;
        vector<int> num;
        int find(int x) {
                if (parent[x] == x) return  x;
                return parent[x] = find(parent[x]);
        }
        UnionFind(int n_) {
                n = n_;
                parent.resize(n);
                for (int i = 0; i < n; i ++) parent[i] = i;
                rank.assign(n, 0);
                num.assign(n, 1);
        }
        void unite(int x, int y) {
                if ((x = find(x)) != (y = find(y))) {
                        if (rank[x] < rank[y]) {
                                parent[x] = y;
                                num[y] += num[x];
                        } else {
                                parent[y] = x;
                                if (rank[x] == rank[y]) rank[x] ++;
                                num[x] += num[y];
                        }
                        n --;
                }
        }
        bool same(int x, int y) { return find(x) == find(y); }
        int get() { return n; }
        int get(int x) { return num[find(x)]; }
};

struct LCA {
        const int LOGM = 30;
        vector<int> depth, par_w;
        vector<vector<int>> parent, parmax;
        LCA(int root, const vector<vector<pair<int, int>>> &g) {
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

int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<pair<int, pair<int, int>>> es;
        for (int i = 0; i < m; i ++) {
                int a, b, c;
                scanf("%d%d%d", &a, &b, &c);
                a --, b --;
                es.push_back({c, {a, b}});
        }
        sort(es.begin(), es.end());
        vector<pair<int, pair<int, int>>> use;
        UnionFind uf(n);
        long long tot = 0;
        for (int i = 0; i < (int) es.size(); i ++) {
                int a, b;
                tie(a, b) = es[i].second;
                if (uf.same(a, b)) continue;
                uf.unite(a, b);
                use.push_back(es[i]);
                tot += es[i].first;
        }
        assert((int) use.size() == n - 1);
        vector<vector<pair<int, int>>> g(n);
        for (int i = 0; i < n - 1; i ++) {
                int c = use[i].first;
                int a = use[i].second.first;
                int b = use[i].second.second;
                g[a].push_back({b, c});
                g[b].push_back({a, c});
        }
        LCA lca(0, g);
        int q;
        scanf("%d", &q);
        while (q --) {
                int s, t;
                scanf("%d%d", &s, &t);
                s --, t --;
                int l = lca.lca(s, t);
                int maxval = max(lca.getmax(s, l), lca.getmax(t, l));
                printf("%lld\n", tot - maxval);
        }
        return 0;
}
