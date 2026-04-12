#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<ll>>;
vector<bool>seen;
ll N;
int main(){
  cin>>N;
  Graph G(N);
  vector<ll>indeg(N);
  seen.resize(N,false);
  for(ll i=0;i<N-1;i++){
  ll a,b;cin>>a>>b;a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
    indeg[a]++;indeg[b]++;
  }queue<ll>que;ll Sum=0;
  for(ll i=0;i<N;i++)
    if(indeg[i]==1)que.push(i);
  while(!que.empty()){
  ll v=que.front(); que.pop();
    if(seen[v])
      continue;
    seen[v]=true;
   ll sum=0;
    ll v1;
    for(auto u:G[v]){
    if(seen[u])
      continue;
      sum++;
      v1=u;
    }if(sum!=1)
      continue;
    Sum+=2;seen[v1]=true;
    for(auto u:G[v1]){
    if(seen[u])
      continue;
      indeg[u]--;
      if(indeg[u]==1)que.push(u);
     }
  }if( Sum==N)
    cout<<"Second"<<endl;
  else
    cout<<"First"<<endl;
  return 0;
}