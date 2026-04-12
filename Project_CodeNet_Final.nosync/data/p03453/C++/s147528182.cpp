#include <cstdio>
#include <queue>

using LL = long long;

const int N = 100000;
const int M = 200000;
const int MOD = (int)1e9 + 7;

int n, m, s, t, a[M << 1], c[M << 1], ws[N], wt[N];
LL ds[N], dt[N];
std::vector<std::pair<int, int>> graph[N];

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

void dij(int src, LL* dist, int* ways)
{
    for (int i = 0; i < n; ++ i) {
        dist[i] = 1000000000000000000LL;
    }
    dist[src] = 0, ways[src] = 1;
    std::priority_queue<std::pair<LL, int>> queue;
    queue.emplace(0, src);
    while (!queue.empty()) {
        auto top = queue.top();
        queue.pop();
        int u = top.second;
        if (-top.first != dist[u]) {
            continue;
        }
        for (auto it : graph[u]) {
            int v = it.first;
            if (dist[u] + it.second < dist[v]) {
                dist[v] = dist[u] + it.second;
                ways[v] = 0;
                queue.emplace(-dist[v], v);
            }
            if (dist[u] + it.second == dist[v]) {
                update(ways[v], ways[u]);
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    s --;
    t --;
    for (int i = 0; i < m << 1; ++ i) {
        scanf("%d", a + i);
        a[i] --;
        if (i & 1) {
            scanf("%d", c + i);
            c[i ^ 1] = c[i];
        }
    }
    for (int i = 0; i < m << 1; ++ i) {
        graph[a[i]].emplace_back(a[i ^ 1], c[i]);
    }
    dij(s, ds, ws);
    dij(t, dt, wt);
    int result = 1LL * ws[t] * ws[t] % MOD;
    for (int mid = 0; mid < n; ++ mid) {
        if (ds[mid] * 2 == ds[t] && ds[mid] + dt[mid] == ds[t]) {
            int cnt = 1LL * ws[mid] * wt[mid] % MOD;
            update(result, MOD - 1LL * cnt * cnt % MOD);
        }
    }
    for (int i = 0; i < m << 1; ++ i) {
        LL b = ds[a[i]];
        LL e = ds[a[i ^ 1]];
        if (b * 2 < ds[t] && ds[t] < e * 2 && b + c[i] + dt[a[i ^ 1]] == ds[t]) {
            int cnt = 1LL * ws[a[i]] * wt[a[i ^ 1]] % MOD;
            update(result, MOD - 1LL * cnt * cnt % MOD);
        }
    }
    printf("%d\n", result);
}
