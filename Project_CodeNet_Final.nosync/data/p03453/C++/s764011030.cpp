#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

const int64 INF = 1e18;
const int MOD = 1000000007;

struct Edge {
    int to;
    int64 cost;
    Edge(int _to, int64 _cost) : to(_to), cost(_cost) {}
};

template<class T>
vector<T> Dijkstra(const vector<vector<Edge>> &G, int s, T def, vector<int64> &path) {
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> que;
    vector<T> dist((int)G.size(), def);
    que.emplace(0, s);
    dist[s] = 0;
    path[s] = 1;
    while(!que.empty()) {
        auto p = que.top(); que.pop();
        int cur = p.second;
        if(dist[cur] < p.first) continue;
        for(auto &e : G[cur]) {
            if(dist[e.to] > dist[cur] + e.cost) {
                dist[e.to] = dist[cur] + e.cost;
                que.emplace(dist[e.to], e.to);
                path[e.to] = path[cur];
            } else if(dist[e.to] == dist[cur] + e.cost) {
                path[e.to] += path[cur];
                path[e.to] %= MOD;
            }
        }
    }
    return dist;
}

int main() {
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    --S, --T;
    vector<vector<Edge>> G(N);
    for(int i = 0; i < M; ++i) {
        int a, b;
        int64 c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
    vector<int64> path_s(N);
    vector<int64> path_t(N);
    auto dist_s = Dijkstra(G, S, INF, path_s);
    auto dist_t = Dijkstra(G, T, INF, path_t);
    int64 ans = path_s[T] * path_t[S] % MOD;
    for(int i = 0; i < N; ++i) {
        if(dist_s[i] + dist_t[i] == dist_s[T] && dist_s[i] == dist_t[i]) {
            int64 n = path_s[i] * path_t[i] % MOD;
            n = n * n % MOD;
            ans -= n;
            if(ans < 0) ans += MOD;
        }
    }
    for(int i = 0; i < N; ++i) {
        for(auto &e : G[i]) {
            int j = e.to;
            if(dist_s[i] + dist_t[j] + e.cost == dist_s[T] && 2 * dist_s[i] < dist_s[T] && 2 * dist_t[j] < dist_s[T]) {
                int64 n = path_s[i] * path_t[j] % MOD;
                n = n * n % MOD;
                ans -= n;
                if(ans < 0) ans += MOD;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
