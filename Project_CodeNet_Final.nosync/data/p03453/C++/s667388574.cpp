#include <bits/stdc++.h>
using namespace std;
#define maxn 500000
#define mod 1000000007
#define int long long
int n, m, dis1[maxn], dis2[maxn];
int ans, K, S, T, Way1[maxn], Way2[maxn];
bool vis[maxn];

int read()
{
    int x = 0, k = 1;
    char c; c = getchar();
    while(c < '0' || c > '9') { if(c == '-') k = -1; c = getchar(); }
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * k;
}

struct edge
{
    int cnp, fr[maxn], to[maxn], co[maxn];
    int last[maxn], head[maxn], degree[maxn];
    edge() { cnp = 2; }
    void add(int u, int v, int w = 0)
    { 
        fr[cnp] = u, to[cnp] = v, co[cnp] = w;
        last[cnp] = head[u], head[u] = cnp ++; 
    }
}E[2], G;

struct node
{
    int x, y;
    node(int _x = 0, int _y = 0) { x = _x, y = _y; }
    friend bool operator <(const node& a, const node& b)
    { return a.y > b.y; }
}; priority_queue <node> q;

void Up(int &x, int y) { x = (x + y) % mod; }
int Qpow(int x) { return x * x % mod; }
void Dijk(int S, int *dis)
{
    memset(vis, 0, sizeof(vis));
    dis[S] = 0; q.push(node(S, 0));
    while(!q.empty())
    {
        node now = q.top(); q.pop();
        int u = now.x; if(vis[u]) continue; vis[u] = 1;
        for(int i = G.head[u]; i; i = G.last[i])
        {
            int v = G.to[i];
            if(dis[v] > dis[u] + G.co[i])
            {
                dis[v] = dis[u] + G.co[i];
                q.push(node(v, dis[v]));
            }
        }
    }
}

void Toposort()
{
    memset(vis, 0, sizeof(vis));
    queue <int> q; q.push(S);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i = G.head[u]; i; i = G.last[i])
        {
            int v = G.to[i];
            if((dis1[u] + dis2[v] + G.co[i]) == K)
            {
                E[0].add(u, v); E[0].degree[v] ++;
                E[1].add(v, u); E[1].degree[u] ++;
                if(!vis[v]) q.push(v), vis[v] = 1;
            }
        }
    }
}

void TopoDP(int opt, int *Way)
{
    queue <int> q;
    for(int i = 1; i <= n; i ++) 
        if(!E[opt].degree[i]) 
            q.push(i), Way[i] = 1;
    while(!q.empty())
    {
        int u = q.front(); q.pop(); 
        for(int i = E[opt].head[u]; i; i = E[opt].last[i])
        {
            int v = E[opt].to[i];
            E[opt].degree[v] --; Up(Way[v], Way[u]);
            if(!E[opt].degree[v]) q.push(v);
        }
    }
}

signed main()
{
    n = read(), m = read(); S = read(), T = read();
    for(int i = 1; i <= m; i ++) 
    {
        int x = read(), y = read(), w = read();
        G.add(x, y, w), G.add(y, x, w);
    }
    memset(dis1, 127, sizeof(dis1)); memset(dis2, 127, sizeof(dis2)); 
    Dijk(S, dis1), Dijk(T, dis2);
    K = dis1[T]; Toposort(); 
    TopoDP(0, Way1); TopoDP(1, Way2);
    for(int i = 1; i <= n; i ++)
        if(dis1[i] + dis1[i] == K) 
            Up(ans, Qpow(Way1[i] * Way2[i] % mod) % mod);
    for(int i = 2; i < E[1].cnp; i ++)
    {
        int u = E[0].fr[i], v = E[0].to[i];
        if(dis1[u] * 2 == K || dis1[v] * 2 == K) continue;
        if(K > 2 * dis1[u] && K < 2 * (K - dis2[v])) 
            Up(ans, Qpow(Way1[u] * Way2[v] % mod) % mod);
    }
    ans = (Way1[T] * Way1[T] % mod - ans + mod) % mod;
    printf("%lld\n", ans);
    return 0;
}