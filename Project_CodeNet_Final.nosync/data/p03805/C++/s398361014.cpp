#include <bits/stdc++.h>
using namespace std;

#define NMAX 8

int n, m;
bool graph[NMAX + 1][NMAX + 1];
bool visited[NMAX + 1];

void initialize_graph() {
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      graph[i][j] = false;
    }
  }

  return;
}

bool all_visited() {
  int i;
  for (i = 0; i < n; i++) {
    if (visited[i] == false) {
      return false;
    }
  }
  return true;
}

int dfs(int u) {
  int v, ret = 0;

  visited[u] = true;

  if (all_visited()) {
    return 1;
  } else {
    for (v = 0; v < n; v++) {
      if (graph[u][v] == true && visited[v] == false) {
        visited[v] = true;
        ret += dfs(v);
        visited[v] = false;
      }
    }
  }
  return ret;
}

int main() {

  int i, a, b;

  cin >> n >> m;

  initialize_graph();

  for (i = 0; i < m; i++) {
    cin >> a >> b;
    graph[a - 1][b - 1] = true;
    graph[b - 1][a - 1] = true;
  }

  cout << dfs(0) << '\n';

  return 0;
}