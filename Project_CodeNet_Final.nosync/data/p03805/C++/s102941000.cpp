#include<bits/stdc++.h>
using namespace std;
 
const int nmax = 8;
bool graph[nmax][nmax];
 
int dfs(int v,int N,bool visited[nmax]){
  bool all_visited = true;
  for(int i = 0;i<N;++i){
    if(visited[i] == false){
      all_visited = false;
      break;
    }
  }
  
  if(all_visited){
    return 1;
  }
  
  int ret = 0;
  for(int i = 0; i<N;++i){
    if(graph[v][i] == false) continue;
    if(visited[i] == true) continue;
    
    visited[i] = true;
    ret+=dfs(i,N,visited);
    visited[i] = false;
  }
  
  return ret;
}
 
int main(){
  int N,M;
  cin >> N >> M;
  int a,b;
  for(int i=0;i<M;++i){
    cin >> a >> b;
    a--;
    b--;
    graph[a][b] = graph[b][a] = true;
  }
  
  bool visited[nmax];
  for(int i = 0; i < nmax ; ++i){
    visited[i] = false;
  }
  
  visited[0] = true;
  
  cout << dfs(0,N,visited) << endl;
  return 0;
 
}