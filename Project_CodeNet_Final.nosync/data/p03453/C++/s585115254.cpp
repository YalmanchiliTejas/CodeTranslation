#include <bits/stdc++.h>
#define show(x) cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef pair<int, int> pairs;
const ll INF = 1ll << 60;
const int N = 404040;
const int MOD = 1000000007;

inline char get(void) {
    static char buf[100000], *S = buf, *T = buf;
    if (S == T) {
        T = (S = buf) + fread(buf, 1, 100000, stdin);
        if (S == T) return EOF;
    }
    return *S++;
}
template<typename T>
inline void read(T &x) {
    static char c; x = 0; int sgn = 0;
    for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
    for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
    if (sgn) x = -x;
}

struct edge {
    int to, key, next;
    edge(int t = 0, int k = 0, int n = 0): to(t), key(k), next(n) {};
} G[N];
int n, m, x, y, z, s, t, gcnt, ans;
ll dis[N], sid[N];
int head[N], vis[N], onw[N];
queue<int> Q;
vector<int> E[N], B[N];
int f[N], g[N];

inline void addEdge(int from, int to, int key) {
    G[++gcnt] = edge(to, key, head[from]); head[from] = gcnt;
    G[++gcnt] = edge(from, key, head[to]); head[to] = gcnt;
}
inline void shortestPath(ll *dis, int s) {
    for (int i = 1; i <= n; i++) {
        dis[i] = INF; vis[i] = 0;
    }
    Q.push(s); vis[s] = 1; dis[s] = 0;
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        for (int i = head[x]; i; i = G[i].next)
            if (dis[G[i].to] > dis[x] + G[i].key) {
                dis[G[i].to] = dis[x] + G[i].key;
                if (!vis[G[i].to]) {
                    vis[G[i].to] = 1;   Q.push(G[i].to);
                }
            }
        vis[x] = 0;
    }
}
inline void add(int &x, int a) {
    x = (x + a >= MOD) ? x + a - MOD : x + a;
}
inline void sub(int &x, int a) {
    x = (x < a) ? x - a + MOD : x - a;
}
inline void dfs1(int u) {
    vis[u] = 1;
    for (int to: E[u]) {
        if (!vis[to]) dfs1(to);
        add(f[u], f[to]);
    }
}
inline void dfs2(int u) {
    vis[u] = 1;
    for (int to: B[u]) {
        if (!vis[to]) dfs2(to);
        add(g[u], g[to]);
    }
}
inline int sqr(int x) {
    return (ll)x * x % MOD;
}

int main(void) {
    read(n); read(m);
    read(s); read(t);
    for (int i = 1; i <= m; i++) {
        read(x); read(y); read(z);
        addEdge(x, y, z);
    }
    shortestPath(dis, s);
    shortestPath(sid, t);
    for (int i = 1; i <= n; i++)
        onw[i] = (dis[i] + sid[i] == dis[t]);
    for (int i = 1; i <= n; i++)
        if (onw[i])
            for (int j = head[i]; j; j = G[j].next)
                if (onw[G[j].to] && dis[G[j].to] == dis[i] + G[j].key)
                    E[i].push_back(G[j].to);
    for (int i = 1; i <= n; i++)
        if (onw[i])
            for (int j = head[i]; j; j = G[j].next)
                if (onw[G[j].to] && sid[G[j].to] == sid[i] + G[j].key)
                    B[i].push_back(G[j].to);

    for (int i = 1; i <= n; i++) vis[i] = 0;
    vis[t] = 1; f[t] = 1; dfs1(s);
    for (int i = 1; i <= n; i++) vis[i] = 0;
    vis[s] = 1; g[s] = 1; dfs2(t);
    for (int i = 1; i <= n; i++)
        if (onw[i] && dis[i] * 2 == dis[t])
            add(ans, sqr((ll)f[i] * g[i] % MOD));
    for (int i = 1; i <= n; i++)
        if (onw[i] && dis[i] * 2 < dis[t])
            for (int j: E[i])
                if (dis[j] * 2 > dis[t])
                    add(ans, (ll)g[i] * f[j] % MOD * g[i] % MOD * f[j] % MOD);
    ans = (sqr(f[s]) - ans + MOD) % MOD;
    cout << ans << endl;
    return 0;
}
