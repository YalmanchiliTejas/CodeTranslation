//OnestrokePath.cpp (C)
#include <iostream>
#include <string>
using namespace std;

bool graph[8][8];

int dfs(int v, int N, bool visited[8]);

int main(){
  int N,M,A,B;
  cin >> N >> M;
  bool visited[10];
  for(int i = 0; i < M; i++){
    cin >> A >> B;
    graph[A-1][B-1] = graph[B-1][A-1] = true;
  }

  for(int i = 0; i < N; i++) visited[i] = false;
  visited[0] = true;

  printf("%d\n",dfs(0,N,visited));
  return 0;
}

int dfs(int v, int N, bool visited[8]){
  bool allvisited = true;
  for(int i = 0; i < N; i++){
    if(visited[i]==false) allvisited = false;
  }
  if(allvisited) return 1;

  int ret = 0;

  for(int i = 0; i < N; i++){
    if(visited[i]) continue;
    if(graph[v][i]==false) continue;

    visited[i] = true;
    ret += dfs(i,N,visited);
    visited[i] = false;
  }
  return ret;
}
