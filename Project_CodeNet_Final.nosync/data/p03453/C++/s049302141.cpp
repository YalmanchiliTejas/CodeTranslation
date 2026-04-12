#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<random>
#include<stdio.h>
using namespace std;

typedef long long ll;

long long Mod(long long val, long long m) {
  long long res = val % m;
  if (res < 0) res += m;
  return res;
}

#define INF 1e+16
#define MAX_V 1000000

ll mod=1000000007;

struct edge {
    ll to;
    ll cost;
};

// <最短距離, 頂点の番号>
using P = pair<ll, ll>;

ll V;
vector<edge> G[MAX_V];
ll d[MAX_V];
ll cnt[MAX_V];


void dijkstra(ll s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    fill(cnt,cnt+V,0);
    cnt[s]=1;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        ll v = p.second;
        if (d[v] < p.first) continue;

        for (ll i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
                cnt[e.to]=cnt[v];
            }
            else if (d[e.to] == d[v] + e.cost){
                cnt[e.to]+=cnt[v];
                cnt[e.to]=Mod(cnt[e.to],mod);
            }
        }
    }
}




int main(){
    cin>>V;
    ll M;
    cin>>M;
    ll S,T;
    cin>>S>>T;
    for (ll i=0;i<M;i++){
        ll u,v,d;
        cin>>u>>v>>d;
        edge e={v-1,d};
        edge f={u-1,d};
        G[u-1].push_back(e);
        G[v-1].push_back(f);
    }

    vector<ll> spath(V);
    vector<ll> tpath(V);

    vector<ll> Sways(V);
    vector<ll> Tways(V);


    dijkstra(S-1);
    for (ll i=0;i<V;i++){
        spath[i]=d[i];
        Sways[i]=cnt[i];
    }

    dijkstra(T-1);
    for (ll i=0;i<V;i++){
        tpath[i]=d[i];
        Tways[i]=cnt[i];
    }

    ll ans=Sways[T-1]*Tways[S-1];
    ans=Mod(ans,mod);
    ll minus=0;
    for (ll u=0;u<V;u++){
        for (ll j=0;j<G[u].size();j++){
            edge e=G[u][j];
          	ll v=e.to;
            ll d=e.cost;
            if (spath[u]+d+tpath[v]==spath[T-1]  and ((tpath[v]+d>spath[u] and spath[u]>=tpath[v]) or (tpath[v]+d>=spath[u]+d and spath[u]+d>tpath[v]))){
                ll m=Tways[v]*Sways[u];
                m=Mod(m,mod);
                m=Mod(m*m,mod);
                minus+=m;
                minus=Mod(minus,mod);
            }
        }
    }

    for (ll i=0;i<V;i++){
        if (spath[i]+tpath[i]==spath[T-1] and spath[i]==tpath[i]){
            ll M=Tways[i]*Sways[i];
            M=Mod(M,mod);
            M=Mod(M*M,mod);
            minus+=M;
            minus=Mod(minus,mod);
        }
    }

    ans-=minus;
    ans=Mod(ans,mod);

    cout<<ans<<endl;
  

}