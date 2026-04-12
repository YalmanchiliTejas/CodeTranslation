#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(n);++i)
using vertex = struct vertex {ll to,cost;vertex(ll to,ll cost):to(to),cost(cost){}};
using AdjList = vector<vector<vertex>>;
using edge = struct edge{ll from,to,cost;edge(ll from,ll to,ll cost):from(from),to(to),cost(cost){}};
using Edges = vector<edge>;

AdjList adj;
ll ans;

void dfs(ll now_v,vector<bool> visited){
  if(visited[now_v])return;
  visited[now_v]=true;
  bool goal=true;
  for(const auto& element:visited)goal&=element;
  if(goal){
    ans++;
    return;
  }
  for(const auto& next_v:adj[now_v]){
    dfs(next_v.to,visited);
  }
}

main(){

  ll n,m;
  cin>>n>>m;
  adj.resize(n);
  rep(i,m){
    ll a,b;
    cin>>a>>b;
    a--;b--;
    adj[a].emplace_back(b,1);
    adj[b].emplace_back(a,1);
  }
  vector<bool> visited(n,false);
  dfs(0,visited);
  cout<<(ans)<<endl;


}