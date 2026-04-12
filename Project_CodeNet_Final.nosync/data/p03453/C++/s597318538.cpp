#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

int N,M,S,T;
struct edge {int to; ll cost;};
typedef pair<ll, int> P; // firstは最短距離, secondは頂点の番号

const ll INF=LLONG_MAX/2;
const int MAX_V=101010;
vector<edge> G[MAX_V];
vector<tuple<int,int,ll> > E;
ll d[MAX_V];
ll dp1[101010], dp2[101010];

void dijkstra(int s){
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d+N, INF);
  d[s]=0;
  que.push(P(0, s));
  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second; // 頂点の番号
    if (d[v] < p.first) continue;
    for(int i=0;i<G[v].size();i++){
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main(){
  cin>>N>>M>>S>>T; S--, T--;
  rep(i,M){
    int u,v; ll d; cin>>u>>v>>d; u--, v--;
    G[u].push_back({v,d});
    G[v].push_back({u,d});
    E.push_back(make_tuple(u,v,d));
  }
  dijkstra(S);
  vector<P> V(N);
  rep(i,N) V[i]={d[i],i};
  sort(V.begin(),V.end());
  dp1[S]=dp2[T]=1;
  rep(i,N){
    int v=V[i].second;
    rep(j,G[v].size()){
      edge e=G[v][j];
      if(d[e.to]==d[v]+e.cost) (dp1[e.to]+=dp1[v])%=MOD;
    }
  }
  for(int i=N-1;i>=0;i--){
    int v=V[i].second;
    rep(j,G[v].size()){
      edge e=G[v][j];
      if(d[e.to]+e.cost==d[v]) (dp2[e.to]+=dp2[v])%=MOD;
    }
  }
  
  ll ans=dp1[T]*dp2[S]%MOD;
  rep(i,N) if(d[i]*2==d[T]){
    ll t=dp1[i]*dp2[i]%MOD;
    ans=(ans-t*t%MOD+MOD)%MOD;
  }
  for(auto e:E){
    int u=get<0>(e), v=get<1>(e);
    ll dd=get<2>(e);
    if(d[u]>d[v]) swap(u,v);
    if(2*d[u]<d[T]&&2*d[v]>d[T]&&d[u]+dd==d[v]){
      ll t=dp1[u]*dp2[v]%MOD;
      ans=(ans-t*t%MOD+MOD)%MOD;
    }
  }
  cout<<ans<<endl;
  return 0;
}
