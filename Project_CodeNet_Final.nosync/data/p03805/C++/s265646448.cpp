#include <bits/stdc++.h>
using namespace std;
const int limit=8;
bool graph[limit][limit];
int dfs(int v,int n,bool visited[limit]){
  bool allvisited=true;
  for(int i=0;i<n;i++)if(visited[i]==false)allvisited=false;
  if(allvisited)return 1;
  int ret=0;
  for(int i=0;i<n;i++){
    if(graph[v][i]==false)continue;
    if(visited[i])continue;
    visited[i]=true;
    ret+=dfs(i,n,visited);
    visited[i]=false;
  }
  return ret;
}
int main(){
  int n,m;
  cin >> n >> m;
  int a[m],b[m];
  for(int i=0;i<m;i++){
    cin >> a[i] >> b[i];
    graph[a[i]-1][b[i]-1]=graph[b[i]-1][a[i]-1]=true;
  }
  bool visited[limit];
  for(int i=0;i<n;i++)visited[i]=false;
  visited[0]=true;
  cout << dfs(0,n,visited)<<endl;
}
