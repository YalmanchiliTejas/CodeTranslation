#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 100;
const int mod = 1e9 + 7;
set <pair<ll, int> > hs;
vector < pair<int, ll> > e[maxn];
const long long inf = 1e16;
int vis[maxn], ord[maxn][2];
void dij(ll *dis, int S, int n, int ty)
{
    for(int i = 1; i <= n; i++) dis[i] = inf, vis[i] = 0;
    dis[S] = 0;
    hs.clear();
    for(int i = 1; i <= n; i++) hs.insert(mp(dis[i], i));
    for(int i = 0; i < n; i++)
    {
        int u = (hs.begin())->se; hs.erase(hs.begin());
        vis[u] = 1; ord[i+1][ty] = u;
        for(int j = 0; j < e[u].size(); j++)
        {
            int v = e[u][j].fi;
            if(dis[v] > dis[u] + e[u][j].se)
            {
                hs.erase(mp(dis[v], v));
                dis[v] = dis[u] + e[u][j].se;
                hs.insert(mp(dis[v], v));
            }
        }
    }
}
int n, m, s, t, x, y, c;
ll ds[maxn], dt[maxn];
ll dp[maxn], dp2[maxn];
int main()
{
    cin>>n>>m;
    cin>>s>>t;
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &x, &y, &c);
        e[x].push_back(mp(y, c));
        e[y].push_back(mp(x, c));
    }
    dij(ds, s, n, 0);
    dij(dt, t, n, 1);
    dp[s] = 1;
    for(int i = 1; i <= n; i++){
        int x = ord[i][0];
        for(auto y : e[x]) {
            if(ds[x] + y.se + dt[y.fi] != ds[t]) continue;
            (dp[y.fi] += dp[x]) %= mod;
        }
    }
    dp2[t] = 1;
    for(int i = 1; i <= n; i++){
        int x = ord[i][1];
        for(auto y : e[x]) {
            if(dt[x] + y.se + ds[y.fi] != ds[t]) continue;
            (dp2[y.fi] += dp2[x]) %= mod;
        }
    }
    long long ans = dp[t]*dp[t]%mod, sub = 0;
    for(int x = 1; x <= n; x++){
        for(auto y : e[x]){
            if(ds[x] + y.se + dt[y.fi] != ds[t]) continue;

            if( (ds[x] <= dt[y.fi] && dt[y.fi] < ds[x] + y.se) || (dt[y.fi] < ds[x] && ds[x] < dt[y.fi] + y.se)){
                    //<= orz
                ll temp = dp[x]*dp2[y.fi]%mod;
                (sub += temp*temp%mod) %= mod;
            }
        }
        if(ds[x] == dt[x]) { // orz
            ll temp = dp[x]*dp2[x]%mod;
            (sub += temp*temp%mod) %= mod;
        }
    }
    ((ans -= sub) += mod) %= mod;
    cout<<ans<<endl;
    return 0;
}
