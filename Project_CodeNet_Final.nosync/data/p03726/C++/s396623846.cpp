#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define fi first
#define se second
#define MP make_pair

int read()
{
    int v = 0, f = 1;
    char c = getchar();
    while (c < 48 || 57 < c) {if (c == '-') f = -1; c = getchar();}
    while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
    return v * f;
}

const int N = 1e5 + 10;

int f[N], g[N], head[N], en, n;

struct Edge
{
    int nxt, to;
} eg[N << 1];

void setEdge(int u, int v)
{
    eg[++en] = (Edge) {head[u], v};
    head[u] = en;
}

void dfs(int u, int fa)
{
    int t = 0;
    for (int e = head[u]; e; e = eg[e].nxt)
    {
        int v = eg[e].to;
        if (v == fa) continue;
        dfs(v, u);
        if (f[v]) continue;
        if (!g[v])
        {
            f[u] = g[u] = 0;
            return ;
        }
        t++;
    }
    if (t > 1)
        f[u] = g[u] = 0;
    if (t == 1)
        f[u] = 1, g[u] = 0;
    if (t == 0)
        f[u] = 0, g[u] = 1;
}

int main()
{
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        setEdge(u, v);
        setEdge(v, u);
    }
    dfs(1, 0);
    if (f[1])
        puts("Second");
    else
        puts("First");
}
