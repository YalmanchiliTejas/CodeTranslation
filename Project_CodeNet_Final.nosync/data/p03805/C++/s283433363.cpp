#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>G;
vector<bool>seen;
int ans=0;
void dfs(int v){
  //終了条件
  bool end=true;
  for(int i=0;i<seen.size();i++){
    if(!seen[i]&&i!=v)end=false;
  }
  if(end){
    ans++;
    return;
  }

  seen[v]=true;
  for(auto nv:G[v]){
    if(seen[nv])continue;
    dfs(nv);
  }
  seen[v]=false;
}
int main(){
  int N,M;
  cin>>N>>M;
  G.resize(N);
  seen=vector<bool>(N,false);
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(0);
  cout<<ans<<endl;
}