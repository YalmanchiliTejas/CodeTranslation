#include<bits/stdc++.h>
bool PN(int x) {
  if (x <= 1) return false;
  if (x == 2) return true;
  for (int i = 2; i < sqrt(x) + 1; i++) if (x % i == 0) return false;
  return true;
}
using namespace std;

int graph[8][8];


int dfs(int v, int n, bool visited[8]){
  bool all_visited = true;
  for(int i = 0; i < n; ++i){
    if(visited[i]== false) all_visited = false;
  }
  if(all_visited) return 1;

  int ret = 0;
  for(int i = 0; i < n; ++i){
    if(graph[v][i] !=1) continue;
    if(visited[i]) continue;
    visited[i] = true;
    ret += dfs(i, n, visited);
    visited[i] = false;
  }

  return ret;
}

void solve(){
  int n, m; cin >> n >> m;
  for(int i = 0; i < m; ++i){
    int a, b; cin >> a >> b;
    graph[a-1][b-1] = graph[b-1][a-1] = 1;
  }
  
  bool visited[8];
  for(int i = 0; i < n; ++i){
    visited[i] = false;
  }
  visited[0] = true;

  cout << dfs(0, n, visited) << endl;
}

int main(){
  solve();
  return 0; 
}