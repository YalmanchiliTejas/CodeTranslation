#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<bool> used;
vector<vector<int>> graph;

int dfs(int u, int c) {
  if (c == N - 1) return 1;

  int res = 0;
  for (auto v : graph[u]) {
    if (used[v]) continue;
    used[v] = true;
    res += dfs(v, c + 1);
    used[v] = false;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  used.assign(N, false);
  graph.assign(N, vector<int>());
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  used[0] = true;
  cout << dfs(0, 0) << '\n';
  return 0;
}
