#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
const int MOD = (int)1e9 + 7;

// EnumerativeSemiring
template<class T> using Rig = pair<T, long long>;
template<class T> Rig<T> add(Rig<T> a, Rig<T> b) {
    if (a.first != b.first) return min(a, b);
    return Rig<T>(a.first, (a.second + b.second) % MOD);
}
template<class T> Rig<T> mul(Rig<T> a, Rig<T> b) {
    return Rig<T>(a.first + b.first, a.second * b.second % MOD);
}

using edge = pair<int, long long>;
using Graph = vector<vector<edge>>;

template<typename T>
vector<Rig<T>> dijkstra(const vector<vector<pair<int, T>>> &g, int s) {
    const T INF = numeric_limits<T>::max();
    vector<Rig<T>> dp(g.size(), Rig<T>(INF, 0));
    vector<bool> done(g.size());
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> que;
    dp[s] = Rig<T>(0, 1); que.emplace(0, s);
    while (!que.empty()) {
        int u = que.top().second; que.pop();
        if (done[u]) continue;
        done[u] = true;
        for (auto &e: g[u]) {
            int v; T c; tie(v, c) = e;
            dp[v] = add(dp[v], mul(dp[u], Rig<T>(c, 1)));
            que.emplace(dp[v].first, v);
        }
    }
    return dp;
}

int main() {
    int n, m; cin >> n >> m;
    int s, t; cin >> s >> t; s--, t--;
    Graph g(n);
    while (m--) {
        int u, v, d; cin >> u >> v >> d; u--, v--;
        g[u].emplace_back(v, d);
        g[v].emplace_back(u, d);
    }
    auto dp_s = dijkstra(g, s);
    auto dp_t = dijkstra(g, t);
    #define distS(v) dp_s[v].first
    #define patS(v) dp_s[v].second
    #define distT(v) dp_t[v].first
    #define patT(v) dp_t[v].second
    #define sq(x) ((x) * (x) % MOD)
    long long all = sq(patS(t));
    long long bad = 0;
    long long d = distS(t);
    for (int u = 0; u < n; u++) {
        if (distS(u) + distT(u) == d && distS(u) == distT(u)) {
            bad += sq(patS(u) * patT(u) % MOD);
            bad %= MOD;
        }
    }
    for (int u = 0; u < n; u++) for (auto &e: g[u]) {
        int v; long long c; tie(v, c) = e;
        if (distS(u) + c + distT(v) != d) continue;
        if (distS(u) * 2 < d && distT(v) * 2 < d) {
            bad += sq(patS(u) * patT(v) % MOD);
            bad %= MOD;
        }
    }
    cout << (all - bad + MOD) % MOD << endl;
    return 0;
}
