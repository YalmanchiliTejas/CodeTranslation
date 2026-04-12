#include<bits/stdc++.h>
#define ll long long
#define pli pair<ll, int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 1e5 + 7;
const int mod = 1e9 + 7;
const ll INF = 1e17;
inline ll add(ll x, ll y) {return (x + y) % mod;}
inline ll mul(ll x, ll y) {return (x * y) % mod;}
inline ll sub(ll x, ll y) {return (x - y + mod) % mod;}
vector<pli>G[MAXN];
bool vis[MAXN];
int n, m;
void dijkstra(int s, ll *dis, ll *f)
{
    priority_queue<pli, vector<pli>, greater<pli> >pq;
    for (int i = 1; i <= n; i++) vis[i] = 0, dis[i] = INF;
    pq.push({dis[s] = 0, s}); f[s] = 1;
    while (pq.size())
    {
        int u = pq.top().sec; pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (pli e : G[u])
        {
            int v = e.sec, w = e.fir;
            if (dis[v] > dis[u] + w)
            {
                pq.push({dis[v] = dis[u] + w, v});
                f[v] = f[u];
            }
            else if (dis[v] == dis[u] + w) f[v] = add(f[v], f[u]);
        }
    }
}

ll dis[2][MAXN], f[2][MAXN];
int main()
{
    scanf("%d%d", &n, &m); 
    int S, T; scanf("%d%d", &S, &T);
    for (int i = 1, u, v, w; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        G[u].emplace_back(w, v);
        G[v].emplace_back(w, u);
    }
    dijkstra(S, dis[0], f[0]);
    dijkstra(T, dis[1], f[1]);
    ll len = dis[0][T]; 
    ll ans = mul(f[0][T], f[0][T]); 
    for (int i = 1; i <= n; i++)
        if (dis[0][i] + dis[1][i] == len && dis[0][i] == dis[1][i]) 
            ans = sub(ans, mul(mul(f[0][i], f[1][i]), mul(f[1][i], f[0][i])));
    for (int u = 1; u <= n; u++)
        for (pli e : G[u])
        {
            int v = e.sec; ll w = e.fir;
            if (dis[0][u] + w + dis[1][v] == len && dis[0][u] + w > dis[1][v] && dis[1][v] + w > dis[0][u])
                ans = sub(ans, mul(mul(f[0][u], f[1][v]), mul(f[1][v], f[0][u])));
        }
    printf("%lld\n", ans);
    return 0;
}