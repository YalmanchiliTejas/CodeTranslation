#include <bits/stdc++.h>
using namespace std;

const int Nmax = 8;
vector<vector<int>> graph(Nmax, vector<int>(Nmax));

int dfs(int v, int N, vector<bool> visited){
  bool all_visited = true;
  for(int i=0; i<N; i++){
    if(visited.at(i) == false){
      all_visited = false;
    }
  }
  
  if(all_visited){
    return 1;
  }
  
  int ans = 0;
  for(int i=0; i<N; i++){
    if(graph.at(v).at(i) == false) continue;
    if(visited.at(i)) continue;
    
    visited.at(i) = true;
    ans += dfs(i, N, visited);
    visited.at(i) = false;
  }
  
  return ans;
}

int main() {
  int N, M;
  cin >> N >> M;
  
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    graph.at(a-1).at(b-1) = true;
    graph.at(b-1).at(a-1) = true;
  }
  
  vector<bool> visited(Nmax);
  for(int i=0; i<N; i++){
    visited.at(i) = false;
  }
  
  visited.at(0) = true;
  cout << dfs(0, N, visited) << endl;
  return 0;
}