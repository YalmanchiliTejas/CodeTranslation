#include <bits/stdc++.h>
using namespace std;


int dfs(int curr_node, vector<bool> visited, vector<vector<bool>>& edge) {
  if (all_of(visited.begin(), visited.end(), [](bool node){return node;})) return 1;
  int ret = 0;
  for (int next_node = 0; next_node < visited.size(); ++next_node) {
    if (!edge[curr_node][next_node]) continue;
    if (visited[next_node]) continue;
    visited[next_node] = true;
    ret += dfs(next_node, visited, edge);
    visited[next_node] = false;
  }
  return ret;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> edge(n, vector<bool>(n, false));
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    edge[a - 1][b - 1] = true;
    edge[b - 1][a - 1] = true;
  }
  vector<bool> visited(n, false);
  visited[0] = true;
  cout << dfs(0, visited, edge) << endl;
}
