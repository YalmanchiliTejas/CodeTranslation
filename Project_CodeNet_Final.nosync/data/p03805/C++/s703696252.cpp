#include <bits/stdc++.h>
using namespace std;

int n, m;
bool g[8][8];

int dfs(int v, int n, bool visited[8]) {
  bool all_visited = true;

  for (int i = 0; i < n; i ++) {
    if (visited[i] == false) all_visited = false;
  }

  if (all_visited) return 1;

  int ret = 0;
  for (int i = 0; i < n; i ++) {
    if (g[v][i] == false) continue;
    if (visited[i]) continue;

    visited[i] = true;
    ret += dfs(i, n, visited);
    visited[i] = false;
  }
  return ret;
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i ++) {
    int x, y;
    cin >> x >> y;
    x --, y --;
    g[x][y] = true, g[y][x] = true;
  }

  bool visited[8];
  for (int i = 0; i < n; i ++) visited[i] = false;

  visited[0] = true;

  cout << dfs(0, n, visited) << endl;
}
