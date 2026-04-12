#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<bool> visited;
vector<vector<int>> graph;

int dfs(int u, int cnt) {
  if (cnt == N) return 1;
  int res = 0;
  for (int v : graph[u]) {
    if (visited[v]) continue;
    visited[v] = true;
    res += dfs(v, cnt + 1);
    visited[v] = false;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  visited.assign(N, false), graph.assign(N, vector<int>());
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  visited[0] = true;
  cout << dfs(0, 1) << '\n';
  return 0;
}
