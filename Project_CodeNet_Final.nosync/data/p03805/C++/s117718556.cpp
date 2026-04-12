#include <functional>
#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;

  bool graph[n][n];
  bool visited[n];
  for (int i = 0; i < n; i++) {
    visited[i] = false;
    for (int j = 0; j < n; j++) { graph[i][j] = false; }
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    graph[a - 1][b - 1] = true;
    graph[b - 1][a - 1] = true;
  }

  int cnt = 0;
  std::function<void(const int, const int)> dfs = [&](const int i, const int dpt) {
    if (visited[i]) return;
    if (dpt == n) {
      cnt++;
      return;
    }
    visited[i] = true;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (graph[i][j]) dfs(j, dpt + 1);
    }
    visited[i] = false;
  };

  dfs(0, 1);
  std::cout << cnt << std::endl;
  return 0;
}

