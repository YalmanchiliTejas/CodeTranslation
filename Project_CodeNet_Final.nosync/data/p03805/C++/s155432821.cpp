#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> graph;

int dfs(int v, vector<bool> visited, graph& g) {
  visited[v] = true;

  bool flag = true;
  for (int b : visited) {
    if (!b) flag = false;
  }
  if (flag) return 1;

  int res = 0;
  for (int u : g[v]) {
    if (!visited[u]) {
      res += dfs(u, visited, g);
    }
  }
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  graph g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<bool> visited(n, false);
  cout << dfs(0, visited, g) << endl;
}