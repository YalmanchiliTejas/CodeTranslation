#include <bits/stdc++.h>
using namespace std;

int N,M;
bool visited[8];
vector<int> G[8];

int dfs(int s){
  bool all = true;
  for(int i=0;i<N;i++)
    if(!visited[i]) all = false;
  if(all) return 1;
  int ret = 0;
  for(int i=0;i<G[s].size();i++){
    int nx = G[s][i];
    if(visited[nx]) continue;
    visited[nx] = true;
    ret += dfs(nx);
    visited[nx] = false;
  }
  return ret;
}

int main(){
  cin>>N>>M;
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  visited[0] = true;
  cout<<dfs(0)<<endl;
  return 0;
}
