#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

// 木の直径
template<typename T>
struct Diameter {
private:
    struct edge {
        int to; T cost;
    };

    vector<vector<edge>> G;

    // (最遠点までのコスト,最遠点)
    pair<T, int> dfs(int v, int p) {
        pair<int, int> res = {0,v};
        for (auto &e : G[v]) {
            if (e.to == p) continue;
            auto d = dfs(e.to, v);
            if (res.first < d.first + e.cost) {
                res.first = d.first + e.cost;
                res.second = d.second;
            }
        }
        return res;
    }
public:
    vector<int> highest;
    void dfs_2(int v, int p, int h) {
        highest[v] = max(highest[v], h);
        for (auto &e : G[v]) {
            if (e.to == p) continue;
            dfs_2(e.to, v, h + e.cost);
        }
    }

    Diameter(int V) {
        G.resize(V);
        highest.resize(V, 0);
    }

    // 無向辺を張る
    void add_edge(int v, int u, T cost) {
        G[v].push_back({u,cost});
        G[u].push_back({v,cost});
    }

    void build() {
        auto p = dfs(0, -1);
        auto q = dfs(p.second, -1);
        dfs_2(p.second, -1, 0);
        dfs_2(q.second, -1, 0);
    }
};

int main() {
    int n; cin >> n;
    Diameter<int> G(n);
    REP(i, n - 1) {
        int s, t, w; scanf("%d %d %d", &s, &t, &w);
        G.add_edge(s, t, w);
    }
    G.build();
    REP(i, n) {
        cout << G.highest[i] << endl;
    }
    return 0;
}
