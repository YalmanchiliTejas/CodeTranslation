#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <cassert>
using namespace std;

const int MOD = 1e9 + 7;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

struct edge {
        int to;
        long long cost;
};

vector<long long> Dijkstra(int s, const vector<vector<edge>> &g) {
        vector<long long> dist(g.size(), INFL);
        vector<bool> used(g.size(), false);
        priority_queue<pair<long long, int>> q;
        q.push({ 0, s });
        while (!q.empty()) {
                auto p = q.top();
                q.pop();
                long long d = - p.first;
                int u = p.second;
                if (used[u]) continue;
                used[u] = true;
                dist[u] = d;
                for (auto e : g[u]) {
                        q.push({ - d - e.cost, e.to });
                }
        }
        return dist;
}

int main() {
        int n, m;
        scanf("%d %d", &n, &m);
        int s, t;
        scanf("%d %d", &s, &t);
        s --, t --;
        vector<vector<edge>> g(n);
        for (int i = 0; i < m; i ++) {
                int a, b, c;
                scanf("%d %d %d", &a, &b, &c);
                a --, b --;
                g[a].push_back({b, c});
                g[b].push_back({a, c});
        }
        auto dist1 = Dijkstra(s, g);
        auto dist2 = Dijkstra(t, g);
        long long len = dist1[t];
        vector<long long> dp1(n, 0), dp2(n, 0);
        dp1[s] = dp2[t] = 1;
        priority_queue<pair<long long, int>> q;
        vector<bool> used(n, false);
        q.push({ 0, s });
        while (!q.empty()) {
                auto p = q.top();
                q.pop();
                int u = p.second;
                if (used[u]) continue;
                used[u] = true;
                for (auto e : g[u]) {
                        if (dist1[u] + dist2[e.to] + e.cost == len) {
                                (dp1[e.to] += dp1[u]) %= MOD;
                                q.push({ - dist1[e.to], e.to });
                        }
                }
        }
        used.assign(n, false);
        q.push({ 0, t });
        while (!q.empty()) {
                auto p = q.top();
                q.pop();
                int u = p.second;
                if (used[u]) continue;
                used[u] = true;
                for (auto e : g[u]) {
                        if (dist2[u] + dist1[e.to] + e.cost == len) {
                                (dp2[e.to] += dp2[u]) %= MOD;
                                q.push({ - dist2[e.to], e.to });
                        }
                }
        }
        long long ans = dp1[t] * dp1[t] % MOD;
        for (int u = 0; u < n; u ++) {
                for (auto e : g[u]) {
                        int v = e.to;
                        long long d = e.cost;
                        if (dist1[u] + d + dist2[v] == len) {
                                if (dist1[u] * 2 < len && dist2[v] * 2 < len) {
                                        long long z = dp1[u] * dp2[v] % MOD;
                                        (ans -= z * z % MOD) %= MOD;
                                }
                        }
                }
                if (dist1[u] == dist2[u] && dist1[u] + dist2[u] == len) {
                        long long z = dp1[u] * dp2[u] % MOD;
                        (ans -= z * z % MOD) %= MOD;
                }
        }
        ans %= MOD;
        ans += MOD;
        ans %= MOD;
        printf("%lld\n", ans);
        return 0;
}

