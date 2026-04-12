#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

void dfs(Graph &G, int v, int N, vector<bool> visited, int &ans) {
  visited[v] = true;
  
  for (int next_v : G[v]) {
    if (visited[next_v]) continue;
    dfs(G, next_v, N, visited, ans);
  }
  
  bool all_visited = true;
  for (int i = 0; i < N; i++) {
    if (!visited[i]) all_visited = false;
  }
  
  if (all_visited) ans++;
}
  
int main() {
  int N, M; cin >> N >> M;
  Graph G(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
  }
  int ans = 0;
  vector<bool> visited(N, false);
  dfs(G, 0, N, visited, ans);
  cout << ans << endl;
}