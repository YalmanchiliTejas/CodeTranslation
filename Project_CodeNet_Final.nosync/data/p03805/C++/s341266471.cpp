#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> edges;
vector<bool> visited;
int ans;

void dfs(int v) {
  visited[v] = true;
  for (int e : edges[v]) {
    if (visited[e]) continue;
    dfs(e);
  }
  bool finish = true;
  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
      finish = false;
      break;
    }
  }
  if (finish) ans++;
  visited[v] = false;
}

int main() {
  cin >> N >> M;
  edges.assign(N, vector<int>());
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  visited.resize(N);
  dfs(0);
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
