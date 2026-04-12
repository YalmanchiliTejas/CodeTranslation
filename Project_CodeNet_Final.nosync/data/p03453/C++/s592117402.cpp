#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template <typename T>
vector<T> dijkstra(Int s,vector<vector<pair<Int, T> > > & G,T INF){
  using P = pair<T, Int>;
  Int n=G.size();
  vector<T> d(n,INF);
  vector<Int> b(n,-1);
  priority_queue<P,vector<P>,greater<P> > q;
  d[s]=0;
  q.emplace(d[s],s);
  while(!q.empty()){
    P p=q.top();q.pop();
    Int v=p.second;
    if(d[v]<p.first) continue;
    for(auto& e:G[v]){
      Int u=e.first;
      T c=e.second;
      if(d[u]>d[v]+c){
	d[u]=d[v]+c;
	b[u]=v;
	q.emplace(d[u],u);
      }
    }
  }
  return d;
}

signed main(){
  Int n,m,s,t;
  cin>>n>>m>>s>>t;
  s--;t--;
  using P = pair<Int, Int>;
  vector<vector<P> > G(n);
  for(Int i=0;i<m;i++){
    Int u,v,d;
    cin>>u>>v>>d;
    u--;v--;
    G[u].emplace_back(v,d);
    G[v].emplace_back(u,d);
  }
  const Int INF = 1e17;
  auto X=dijkstra(s,G,INF);
  auto Y=dijkstra(t,G,INF);
  Int L=X[t];
  //cout<<L<<endl;
  
  const Int MOD = 1e9+7;
  auto calc=[&](Int st,vector<Int> &Z,vector<Int> &dp){
    priority_queue<P,vector<P>,greater<P> > pq;
    vector<Int> used(n,0);
    dp[st]=1;
    used[st]=1;
    pq.emplace(Z[st],st);
    while(!pq.empty()){
      Int v;
      tie(ignore,v)=pq.top();pq.pop();
      for(auto e:G[v]){
	Int u,c;
	tie(u,c)=e;
	if(Z[v]+c!=Z[u]) continue;
	if(X[u]+Y[u]!=L) continue;
	
	dp[u]+=dp[v];
	dp[u]%=MOD;
	
	if(used[u]) continue;
	used[u]=1;
	pq.emplace(Z[u],u);
      }
    }
  };
  vector<Int> dp(n,0),dp2(n,0);
  calc(s,X,dp);
  calc(t,Y,dp2);
  
  Int ans=dp[t]*dp[t]%MOD;
  for(Int v=0;v<n;v++){
    if(X[v]+Y[v]!=L||X[v]!=Y[v]) continue;
    Int tmp=dp[v]*dp2[v]%MOD;
    tmp=tmp*tmp%MOD;
    ans+=MOD-tmp;
    ans%=MOD;
  }
  
  for(Int v=0;v<n;v++){
    if(X[v]+Y[v]!=L||X[v]*2>=L) continue;
    for(auto e:G[v]){
      Int u,c;
      tie(u,c)=e;
      if(X[v]+c!=X[u]||X[u]*2<=L) continue;
      Int tmp=dp[v]*dp2[u]%MOD;
      tmp=tmp*tmp%MOD;
      ans+=MOD-tmp;
      ans%=MOD;
    }
  }
  ans%=MOD;
  cout<<ans<<endl;
  return 0;
}
