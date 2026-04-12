#include<bits/stdc++.h>
using namespace std;

struct edge{
  int to;
  int64_t cost;
  edge(){}
  edge(int t,int64_t c):to(t),cost(c){}
};
vector<vector<edge>> adj;
vector<int64_t> dist,dist2;

void dfs1(int cur,int prv){
  for(auto nxt:adj[cur]){
    if(nxt.to==prv)continue;
    dfs1(nxt.to,cur);
    dist[cur] = max(dist[cur],dist[nxt.to]+nxt.cost);
  }
}

void dfs2(int cur,int prv){
  vector<pair<int64_t,int>> tmp;
  tmp.emplace_back(dist2[cur],prv);
  for(auto nxt:adj[cur]){
    if(nxt.to==prv)continue;
    tmp.emplace_back(dist[nxt.to]+nxt.cost,nxt.to);
  }
  sort(tmp.begin(),tmp.end(),greater<>());
  for(auto nxt:adj[cur]){
    if(nxt.to==prv)continue;
    dist2[nxt.to] = max(dist2[nxt.to],tmp[tmp[0].second==nxt.to].first+nxt.cost);
    dfs2(nxt.to,cur);
  }
}

signed main(){

  int n;
  cin>>n;
  adj.resize(n);
  dist.resize(n);
  dist2.resize(n);
  for(int i=0;i<n-1;++i){
    int s,t,w;
    cin>>s>>t>>w;
    adj[s].emplace_back(t,w);
    adj[t].emplace_back(s,w);
  }
  dfs1(0,-1);
  dfs2(0,-1);;
  for(int i=0;i<n;++i){
    cout<< max(dist[i],dist2[i]) <<endl;
  }

}
