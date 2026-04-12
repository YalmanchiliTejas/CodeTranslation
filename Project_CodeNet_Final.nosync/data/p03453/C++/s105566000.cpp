#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 100010, M = 200010;
const LL MOD = 1E9 + 7, INF = 0x3f3f3f3f3f3f3f3f;

inline void Inc(LL &a, LL b) {
    a = (a + b) % MOD;
    return;
}
inline LL Sqr(LL a) {
    return a * a % MOD;
}

int n, m, s, t;
int tot = -1, head[N];
struct Edge {
    int p, nxt, w;
    Edge(int p = 0, int nxt = 0, int w = 0) : p(p), nxt(nxt), w(w) {}
} edge[M << 1];
inline void Add(int u, int v, int w) {
    edge[++tot] = Edge(v, head[u], w);
    head[u] = tot;
    return;
}

bool exist[N];
int id[N];
queue<int> que;

void Init(int s, LL *dist, LL *cnt) {
    fill(dist + 1, dist + n + 1, INF);
    fill(cnt + 1, cnt + n + 1, 0);
    dist[s] = 0;
    que.push(s);
    exist[s] = 1;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        exist[u] = 0;
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].p, w = edge[i].w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!exist[v]) {
                    que.push(v);
                    exist[v] = 1;
                }
            }
        }
    }
    memset(id, 0, sizeof(id));
    for (int u = 1; u <= n; ++u)
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].p, w = edge[i].w;
            if (dist[u] + w == dist[v]) ++id[v];
        }
    cnt[s] = 1;
    que.push(s);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].p, w = edge[i].w;
            if (dist[u] + w == dist[v]) {
                Inc(cnt[v], cnt[u]);
                if (!--id[v]) que.push(v);
            }
        }
    }
    return;
}

LL d1[N], d2[N], c1[N], c2[N];

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        Add(u, v, w);
        Add(v, u, w);
    }
    Init(s, d1, c1);
    Init(t, d2, c2);
    LL res = 0, l = d1[t];
    for (int u = 1; u <= n; ++u) {
        if (d1[u] == d2[u] && d1[u] * 2 == l) Inc(res, Sqr(c1[u]) * Sqr(c2[u]));
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].p, w = edge[i].w;
            if (d1[u] + w + d2[v] == l && d1[u] * 2 < l && l < d1[v] * 2) Inc(res, Sqr(c1[u]) * Sqr(c2[v]));
        }
    }
    res = (c1[t] * c2[s] - res) % MOD;
    printf("%lld\n", res);
    return 0;
}