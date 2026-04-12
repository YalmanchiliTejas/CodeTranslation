#include <bits/stdc++.h>

using namespace std;

int n, m, q;
long long cost;
int l[100010], h[100010];

struct edge
{
    int u, v;
    long long w;
    bool operator < (const edge& other) const
    {
        return w < other.w;
    }
} e[400010];

int Find(int x)
{
    return x == l[x] ? x : l[x] = Find(l[x]);
}

int Union(int u, int v)
{
    if ((u = Find(u)) == (v = Find(v))) return 0;
    if (h[u] < h[v]) swap(u, v);
    l[v] = u;
    h[u] += h[v];
    return 1;
}

int in[100010], out[100010], par[100010][15], times;
long long rmq[100010][15], c[100010];
vector <pair <int, long long> > adj[100010];

void dfs(int u, int p)
{
    in[u] = ++times;
    par[u][0] = p;
    for (int i = 1; i < 15; ++i)
        par[u][i] = par[par[u][i - 1]][i - 1];
    rmq[u][0] = c[u];
    for (int i = 1; i < 15; ++i)
        rmq[u][i] = max(rmq[u][i - 1], rmq[par[u][i - 1]][i - 1]);
    for (int i = 0; i < adj[u].size(); ++i)
    {
        int v = adj[u][i].first;
        long long w = adj[u][i].second;
        if (v == p) continue;
        c[v] = w;
        dfs(v, u);
    }
    out[u] = times;
}

int check(int u, int v)
{
    return (in[u] <= in[v] && out[v] <= out[u]);
}

int LCA(int u, int v)
{
    if (check(u, v)) return u;
    for (int i = 14; i + 1; --i)
        if (par[u][i] && !check(par[u][i], v)) u = par[u][i];
    return par[u][0];
}

long long calc(int u, int w)
{
    long long res = 0;
    for (int i = 14; i + 1; --i)
        if (par[u][i] && check(w, par[u][i]))
        {
            res = max(res, rmq[u][i]);
            u = par[u][i];
        }
    return res;
}

void Kruskal()
{
    for (int i = 1; i <= n; ++i) l[i] = i, h[i] = 1;
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= m; ++i)
        if (Union(e[i].u, e[i].v))
        {
            adj[e[i].u].push_back({e[i].v, e[i].w});
            adj[e[i].v].push_back({e[i].u, e[i].w});
            cost += e[i].w;
        }
}

int main()
{
//    freopen("ELECTRIC.inp", "r", stdin);
//    freopen("ELECTRIC.out", "w", stdout);

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; ++i)
        cin >> e[i].u >> e[i].v >> e[i].w;
    Kruskal();
    dfs(1, 0);

    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        int w = LCA(u, v);
        cout << cost - max(calc(u, w), calc(v, w)) << "\n";
    }
}


