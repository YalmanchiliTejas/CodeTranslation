#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;
using namespace std;

typedef pair<ll,int> P;
vector<ll> dijkstra(int s, const vector<vector<pair<int,int> > >& G){
    priority_queue< P, vector<P>, greater<P> > que;
    vector<ll> d(G.size(), LINF);
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        int curr  = que.top().second;
        ll  dcurr = que.top().first;
        que.pop();
        if(d[curr] < dcurr) continue;
        int i;
        for(i=0; i<(int)G[curr].size(); i++){ 
            int next = G[curr][i].first;
            ll  dist = G[curr][i].second;
            if(d[next] > d[curr] + dist){
                d[next] = d[curr] + dist;
                que.push(P(d[next], next));
            }
        }
    }
    return d;
}

void solve()
{
    int n,m,s,t;
    scanf("%d%d%d%d", &n, &m, &s, &t); s--; t--;
    vector<vector<pair<int,int> > > g(n);
    vector<int> uu(m),vv(m),dd(m);
    int i;
    for(i=0; i<m; i++) {
        int u,v,d;
        scanf("%d%d%d", &u, &v, &d); u--; v--;
        uu[i]=u; vv[i]=v; dd[i]=d;
        g[u].push_back(make_pair(v,d));
        g[v].push_back(make_pair(u,d));
    }
    vector<ll> dist=dijkstra(s, g);

    vector<pair<ll,int> > z;
    for(i=0; i<n; i++) {
        z.push_back(make_pair(dist[i],i));
    }
    sort(z.begin(),z.end());

    vector<ll> dp0(n);
    dp0[s]=1;
    for(i=0; i<n; i++) {
        int id=z[i].second;
        int k;
        for(k=0; k<(int)g[id].size(); k++) {
            int ne=g[id][k].first;
            int dd=g[id][k].second;
            if(dist[ne]==dist[id]+dd) {
                dp0[ne]=(dp0[ne]+dp0[id])%MOD;
            }
        }
    }

    vector<ll> dp1(n);
    dp1[t]=1;
    for(i=n-1; i>=0; i--) {
        int id=z[i].second;
        int k;
        for(k=0; k<(int)g[id].size(); k++) {
            int ne=g[id][k].first;
            int dd=g[id][k].second;
            if(dist[ne]==dist[id]+dd) {
                dp1[id]=(dp1[id]+dp1[ne])%MOD;
            }
        }
    }

    ll ans0=0;
    for(i=0; i<n; i++) {
        if(dist[i]*2==dist[t]) {
            ll tmp0=dp0[i]*dp1[i]%MOD;
            ans0=(ans0+tmp0*tmp0%MOD)%MOD;
        }
    }
    for(i=0; i<m; i++) {
        if(dist[vv[i]]==dist[uu[i]]+dd[i]) {
            if(dist[uu[i]]*2<dist[t] && dist[vv[i]]*2>dist[t]) {
                ll tmp0=dp0[uu[i]]*dp1[vv[i]]%MOD;
                ans0=(ans0+tmp0*tmp0%MOD)%MOD;
            }
        }
        if(dist[uu[i]]==dist[vv[i]]+dd[i]) {
            if(dist[vv[i]]*2<dist[t] && dist[uu[i]]*2>dist[t]) {
                ll tmp0=dp0[vv[i]]*dp1[uu[i]]%MOD;
                ans0=(ans0+tmp0*tmp0%MOD)%MOD;
            }
        }
    }
    ll ans=(dp0[t]*dp0[t]%MOD-ans0+MOD)%MOD;
    printf("%lld\n", ans);

    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
