#include <iostream>

bool dist[8][8];

int dfsPath(int visited[], int n, int cur) {
  bool isAllVisited = true;
  for (int i = 0; i < n; i++) {
    if (visited[i] != 1) {
      isAllVisited = false;
    }
  }
  if (isAllVisited) {
    return 1;
  }
  int ret = 0;
  for (int i = 0; i < n; i++) {
    if (i == cur) continue;
    if (dist[cur][i] == true && visited[i] == 0) {
      visited[i] = 1;
      ret += dfsPath(visited, n, i);
      visited[i] = 0;
    }
  }
  return ret;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  int visited[8];
  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    dist[a - 1][b - 1] = dist[b - 1][a - 1] = 1;
  }
  for (int i = 0; i < n; i++) {
    dist[i][i] = 0;
    visited[i] = 0;
  }
  visited[0] = 1;
  std::cout << dfsPath(visited, n, 0) << "\n";
  return 0;
}