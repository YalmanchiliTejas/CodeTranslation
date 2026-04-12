#include <stdio.h>
#include <vector>
#include <queue>

struct edge {
    int to;
    long long cost;
};
typedef std::pair<long long, int> P;
typedef std::vector<edge> node;

const int MAX_N = 100000;
const long long INF = 1e17;
const int mod = 1e9 + 7;
node G[MAX_N];
long long ds[MAX_N], dt[MAX_N];
int dp1[MAX_N], dp2[MAX_N];
int N, M, S, T;

void dijkstra(int s, long long *d, int *dp) {
    std::priority_queue<P, std::vector<P>, std::greater<P> > que;
    std::fill(d, d + N, INF);
    d[s] = 0;
    dp[s] = 1;
    que.push(std::make_pair(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        long long v = p.second;
        if (d[v] < p.first) continue;
        for (auto e: G[v]) {
            if (d[e.to] > d[v] + e.cost) {
                dp[e.to] = dp[v];
                d[e.to] = d[v] + e.cost;
                que.push(std::make_pair(d[e.to], e.to));
            } else if (d[e.to] == d[v] + e.cost) {
                dp[e.to] += dp[v];
                dp[e.to] %= mod;
            }
        }
    }
}

int main() {
    scanf("%d %d %d %d", &N, &M, &S, &T);
    S--;
    T--;
    for (int i = 0; i < M; ++i) {
        int U, V, D;
        scanf("%d %d %d", &U, &V, &D);
        U--;
        V--;
        G[U].push_back((edge) {V, D});
        G[V].push_back((edge) {U, D});
    }

    dijkstra(S, ds, dp1);
    dijkstra(T, dt, dp2);

    long long ans = 1ll * dp1[T] * dp1[T] % mod;
    for (int v = 0; v < N; ++v) {
        //if (2 * ds[v] == ds[T]) {
        if (ds[v] == dt[v] && ds[v] + dt[v] == ds[T]) {
            ans -= 1ll * dp1[v] * dp1[v] % mod * dp2[v] % mod * dp2[v] % mod;
            ans += mod;
            ans %= mod;
        }
    }
    for (int u = 0; u < N; ++u) {
        for (auto e: G[u]) {
            int v = e.to;
            long long c = e.cost;
            //if (ds[v] == ds[u] + c && 2 * ds[u] < ds[T] && 2 * dt[v] < ds[T]) {
            if (std::max(ds[u], dt[v]) * 2 < ds[T] && ds[u] + c + dt[v] == ds[T]) {
                ans -= 1ll * dp1[u] * dp1[u] % mod * dp2[v] % mod * dp2[v] % mod;
                ans += mod;
                ans %= mod;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}