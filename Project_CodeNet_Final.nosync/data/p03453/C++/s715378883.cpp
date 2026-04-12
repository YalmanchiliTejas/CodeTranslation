#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using LL = long long;
const LL inf = 1e18;
const int MOD = (int)1e9 + 7;
const int kN = 100000 + 5;
int n, m, s, t;
std::vector<std::pair<int, int>> edges[kN];
LL dist[2][kN];
int ways[2][kN];

inline void add(int &a, int b)
{
    a += b;
    if (a >= MOD) a -= MOD;
}

void dijkstra(int source, LL *dist, int *ways)
{
    std::fill(dist, dist + n, inf);
    dist[source] = 0;
    ways[source] = 1;
    std::priority_queue<std::pair<LL, int>> pq;
    pq.emplace(-dist[source], source);
    while (!pq.empty()) {
        int u;
        LL tmp;
        std::tie(tmp, u) = pq.top(); pq.pop();
        if (dist[u] != -tmp) continue;
        for (auto e : edges[u]) {
            int v = e.first, w = e.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                ways[v] = ways[u];
                pq.emplace(-dist[v], v);
            } else if (dist[v] == dist[u] + w) {
                add(ways[v], ways[u]);
            }
        }
    }
}

int sqr(int x)
{
    return x * 1LL * x % MOD;
}

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%d%d", &s, &t); -- s; -- t;
    for (int i = 0; i < m; ++ i) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d); -- u; -- v;
        edges[u].emplace_back(v, d);
        edges[v].emplace_back(u, d);
    }
    dijkstra(s, dist[0], ways[0]);
    dijkstra(t, dist[1], ways[1]);

    int result = ways[0][t] * 1LL * ways[0][t] % MOD;
    // printf("result = %d\n", result);
    for (int overlay_point = 0; overlay_point < n; ++ overlay_point) {
        if (dist[0][overlay_point] == dist[1][overlay_point] && dist[0][overlay_point] + dist[1][overlay_point] == dist[0][t]) {
            add(result, MOD - sqr(ways[0][overlay_point] * 1LL * ways[1][overlay_point] % MOD));
            // printf("overlay_point = %d, result = %d\n", overlay_point, result);
        }
    }
    // printf("result = %d\n", result);
    for (int u = 0; u < n; ++ u) {
        for (auto e : edges[u]) {
            int v, w;
            std::tie(v, w) = e;
            if (dist[0][u] + dist[1][v] + w == dist[0][t] && (dist[0][u] <= dist[1][v] && dist[0][u] + w > dist[1][v] ||
                                                              dist[1][v] <= dist[0][u] && dist[1][v] + w > dist[0][u]))
                add(result, MOD - sqr(ways[0][u] * 1LL * ways[1][v] % MOD));
        }
    }
    printf("%d\n", result);
}
