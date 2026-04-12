#include <iostream>
using namespace std;
#define nmax 8
bool G[nmax][nmax];
int dfs(int v,int N,bool visited[nmax]){
  bool all_visited = true;
  for(int i=0;i<N;i++){
    if(visited[i] == false){
      all_visited = false;
    }
  }
  if(all_visited)return 1;
  int ret = 0;
  for(int i=0;i<N;i++){
    if(G[v][i] == false)continue;
    else if(visited[i] == true)continue;
    visited[i] = true;
    ret += dfs(i,N,visited);
    visited[i] = false;
  }
  return ret;
}
int main(){
  int N,M;
  int x,y;
  bool visited[nmax];
  cin >> N >> M;
  for(int i=0;i<M;i++){
    cin >> x >> y;
    G[x-1][y-1] = G[y-1][x-1] = true;
  }
  for(int i=0;i<N;i++){
    visited[i] = false;
  }
  visited[0] = true;
  cout << dfs(0,N,visited) << endl;
  return 0;
}