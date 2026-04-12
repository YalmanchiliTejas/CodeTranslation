#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;

constexpr ll INFLL = 1e18;
constexpr int Mod = 1e9 + 7;

using weight = ll;

struct edge {
    int to;
    weight cost;
};

using edges = std::vector<edge>;
using graph = std::vector<edges>;

void add_edge(graph& g, int from, int to, weight cost) {
    g[from].push_back(edge{to, cost});
    g[to].push_back(edge{from, cost});
}

vector<weight> dijkstra(graph const& g, int s, vector<ll>& dp) {
    std::vector<ll> d(g.size(), INFLL);
    dp.assign(g.size(), 0);
    d[s] = 0;
    dp[s] = 1;
    std::priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.emplace(0, s);
    while(!que.empty()) {
        int v = que.top().second;
        ll cur_d = que.top().first;
        que.pop();
        if(cur_d > d[v]) {
            continue;
        }
        for(auto const& e : g[v]) {
            if(d[e.to] < cur_d + e.cost) continue;
            if(d[e.to] == cur_d + e.cost) {
                (dp[e.to] += dp[v]) %= Mod;
            }
            if(d[e.to] > cur_d + e.cost) {
                d[e.to] = cur_d + e.cost;
                que.emplace(d[e.to], e.to);
                dp[e.to] = dp[v];
            }
        }
    }
    return d;
}

int main() {
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    S--, T--;
    graph g(N);
    for(int i = 0; i < M; ++i) {
        ll U, V, D;
        cin >> U >> V >> D;
        add_edge(g, U - 1, V - 1, D);
    }
    vector<ll> dp1, dp2;
    vector<bool> used(N), used2(N);
    auto d1 = dijkstra(g, S, dp1);
    auto d2 = dijkstra(g, T, dp2);
    ll dist = d1[T];
    for(int i = 0; i < N; ++i) {
        used[i] = (dist == d1[i] + d2[i]);
    }
    ll ans = 0;
    for(int v = 0; v < N; ++v) {
        if(!used[v]) continue;
        if(d1[v] * 2 == dist) {
            ll t = (dp1[v] * dp2[v]) % Mod;
            t = (t * t) % Mod;
            ans = (ans + t) % Mod;
        } else {
            for(auto& e : g[v]) {
                int to = e.to;
                if(d1[v] + d2[to] + e.cost != dist) continue;
                if(d1[v] * 2 < dist && dist < d1[to] * 2) {
                    ll t = (dp1[v] * dp2[to]) % Mod;
                    t = (t * t) % Mod;
                    ans = (ans + t) % Mod;
                }
            }
        }
    }
    ans = (dp1[T] * dp2[S] - ans + Mod) % Mod;
    cout << ans << endl;
}

