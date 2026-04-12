#include <bits/stdc++.h>
using namespace std;
const int nmax=8;
bool graph[nmax][nmax];
int dfs(int v,int n,bool visited[nmax]){
  bool all_visited=true;
  for(int i=0;i<n;i++){
    if(visited[i]==false){
      all_visited=false;
    }
  }
  if(all_visited){
    return 1;
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(graph[v][i]==false){
      continue;
    }
    if(visited[i]){
      continue;
    }
    visited[i]=true;
    ans+=dfs(i,n,visited);
    visited[i]=false;
  }
  return ans;
}

int main(){
  int n,m;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    graph[a-1][b-1]=graph[b-1][a-1]=true;
  }
  bool visited[nmax];
  memset(visited,false,sizeof(visited));
  visited[0]=true;
  cout << dfs(0,n,visited) << endl;
}