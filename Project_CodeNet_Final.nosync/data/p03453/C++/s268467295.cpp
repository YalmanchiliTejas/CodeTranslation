#include<bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 1e9+7;
constexpr ll inf = 4e18;

struct edge
{
    int t,w;
    edge(int t, int w) : t(t), w(w) {}
};

int sq(long long x)
{
    return x*x%mod;
}

vector<edge> g[100005];
ll dist[2][100005], cnt[2][100005];

void dijk(int st, ll* d, ll* cn)
{
    priority_queue<pair<ll,int>> pq;
    pq.emplace(0,st);
    while(!pq.empty())
    {
        ll w = -pq.top().first;
        int c = pq.top().second;
        pq.pop();
        if(w > d[c]) continue;
        for(auto e : g[c])
        {
            ll ww = w + e.w;
            if(ww>d[e.t]) continue;
            if(ww == d[e.t])
            {
                cn[e.t] += cn[c];
                cn[e.t] %= mod;
                continue;
            }
            d[e.t] = ww;
            cn[e.t] = cn[c];
            pq.emplace(-ww,e.t);
        }
    }
}

int main()
{
    int n,m,s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    while(m--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a].push_back(edge(b,c));
        g[b].push_back(edge(a,c));
    }
    for(int i=0;i<=n;i++) dist[0][i] = dist[1][i] = inf;
    dist[0][s] = dist[1][t] = 0;
    cnt[0][s] = cnt[1][t] = 1;
    dijk(s,dist[0],cnt[0]);
    dijk(t,dist[1],cnt[1]);
    ll len = dist[0][t];
    ll ans = cnt[0][t]*cnt[1][s]%mod;
    for(int i=1;i<=n;i++)
    {
        if(dist[0][i] == dist[1][i] && dist[0][i]*2 == len)
        {
            ans = (ans + mod - sq(cnt[0][i]*cnt[1][i]%mod))%mod;
        }
        else
        {
            if(dist[0][i] + dist[1][i] > len || dist[0][i]*2 > len) continue;

            for(auto e : g[i])
            {
                ll ww = dist[0][i] + e.w;
                if(ww + dist[1][e.t] > len || ww*2 <= len) continue;;
                ans = (ans + mod - sq(cnt[0][i]*cnt[1][e.t]%mod))%mod;
            }
        }
    }
    printf("%lld\n",ans);
}
