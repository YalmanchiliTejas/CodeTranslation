#include<bits/stdc++.h>
using namespace std;
using Int = long long;
Int n,k,ans;
vector<vector<Int> > G;
vector<Int> dp,sz;
void dfs(Int v,Int p){
  if(~p&&G[v].size()==1u){
    dp[v]=0;
    sz[v]=1;
    return;
  }
  using P=pair<Int,int>;
  vector<P> d;
  Int c=0;
  priority_queue<P> q;
  for(Int u:G[v]){
    if(u==p) continue;
    dfs(u,v);
    sz[v]+=sz[u];
    d.emplace_back(dp[u],sz[u]>=k);
    q.emplace(dp[u]-(sz[u]>=k),-(sz[u]>=k));
    c+=d.back().second;
  }
  if(d.size()>=2){
    Int tmp=c;
    if(~p&&n-sz[v]>=k) tmp++;
    auto x=q.top();q.pop();
    auto y=q.top();q.pop();
    tmp+=x.first;
    tmp+=y.first;
    if(0){
      cout<<v<<":"<<c<<" DDD "<<tmp<<endl;
      cout<<x.first<<" "<<x.second<<endl;
      cout<<y.first<<" "<<y.second<<endl;
    }
    ans=max(ans,tmp);
  }
  for(Int i=0;i<(Int)d.size();i++){
    Int x=d[i].first,y=d[i].second;
    dp[v]=max(dp[v],x+c-y);
  }
  
  {
    Int tmp=dp[v];
    if(~p&&n-sz[v]>=k) tmp++;
    //cout<<v<<":"<<dp[v]<<" "<<tmp<<endl;
    ans=max(ans,tmp);
  }

  dp[v]=max(dp[v],c);
}
signed main(){  
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>k;
  G.resize(n);
  dp.resize(n,-1);
  sz.resize(n,1);
  for(Int i=0;i<n-1;i++){
    Int u,v;
    cin>>u>>v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  ans=0;
  dfs(0,-1);
  //for(Int i=0;i<n;i++) cout<<i<<":"<<dp[i]<<" AAA "<<sz[i]<<endl;
  cout<<ans<<endl;
  return 0;
}

