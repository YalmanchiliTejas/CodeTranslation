#include<iostream>
using namespace std;

bool graph[8][8];
int N,M;

int dfs(int v, int N,bool visited[8] ) {
  bool all_visited = true;

  for ( int i = 0; i < N; i++ ) {
    if ( visited[i] == false ) all_visited = false;
  }

  if ( all_visited ) return 1;

  int ret = 0;

  for ( int i = 0; i < N; i++ ) {
    if ( graph[v][i] == false ) continue;
    if ( visited[i] ) continue;
    visited[i] = true;
    ret += dfs(i,N,visited);
    visited[i] = false;
  }
  return ret;
}

int main() {
  cin >> N >> M;
  for ( int i = 0; i < M; i++ ) {
    int a,b;
    cin >> a >> b;
    a--,b--;
    graph[a][b] = graph[b][a] = true;
  }

  bool visited[8];
  for ( int i = 0; i < N; i++ ) visited[i] = false;
  visited[0] = true;
  cout << dfs(0,N,visited) << endl;
  return 0;
}
