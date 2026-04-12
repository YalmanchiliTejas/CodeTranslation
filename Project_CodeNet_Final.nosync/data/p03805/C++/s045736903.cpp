#include<bits/stdc++.h>
using ll=long long;
using namespace std;

bool edge[8][8];
int dfs(int v,int n,vector<bool>visited){

  bool all_visited=true;

  for(int i=0;i<n;i++){
    if(visited[i]==false)all_visited=false;
  }

  if(all_visited)return 1;

  int ans=0;

  for(int i=0;i<n;i++){
    if(edge[v][i]==false)continue;
    if(visited[i])continue;
    visited[i]=true;
    ans+=dfs(i,n,visited);
    visited[i]=false;}
  return ans;
}

int main(){
  //入力準備
  int n,m;
  cin>>n>>m;
  int x,y;
  for(int i=0;i<m;i++){
    cin>>x>>y;
    edge[x-1][y-1]=edge[y-1][x-1]=true;
  }
  
  vector<bool>visited(n);
  visited[0]=true;
  //dfsを用いた。具体的には、すべての頂点を通ればans１増加
  //出力
  cout<<dfs(0,n,visited)<<endl;
  return 0;
}
