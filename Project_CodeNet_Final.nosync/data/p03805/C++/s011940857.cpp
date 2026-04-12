#include <bits/stdc++.h>
using namespace std;

int dfs(int v, int N, vector<vector<int>> graph, vector<bool> visited) {
  bool all_visited = true;
  for (int i=0; i<N; i++)
    if (!visited.at(i)) all_visited = false;
  
  if (all_visited) return 1;
  
  int pathc = 0;
  for (int i=0; i<N; i++) {
    if (!graph.at(v).at(i)) continue;
    else if (visited.at(i)) continue;
    else {
      visited.at(i) = true;
      pathc += dfs(i, N, graph, visited);
      visited.at(i) = false;
    }
  }
  return pathc;
} 

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  for (int i=0; i<M; i++) cin >> a.at(i) >> b.at(i);
  vector<vector<int>> graph(N, vector<int>(N));
  for (int i=0; i<M; i++) {
    graph.at(a.at(i)-1).at(b.at(i)-1) = 1;
    graph.at(b.at(i)-1).at(a.at(i)-1) = 1;
  }
  
  vector<bool> visited(N, false);
  visited.at(0) = true;
  int all_path = dfs(0, N, graph, visited);
  cout << all_path << endl;
}