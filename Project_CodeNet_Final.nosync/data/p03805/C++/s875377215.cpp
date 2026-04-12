#include <bits/stdc++.h>

using namespace std;
const int MAXN = 8;
vector<int> G[MAXN];
int ans = 0;
int n, m;

void dfs(int cur, vector<bool> visited) {
  bool done = true;
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) done = false;
  }
  if (done) {
    ans++;
    return;
  }
  for (size_t i = 0; i < G[cur].size(); ++i) {
    int next = G[cur][i];
    if (!visited[next]) {
      visited[next] = true;
      dfs(next, visited);
      visited[next] = false;
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<bool> visited(n, false);
  visited[0] = true;
  dfs(0, visited);
  printf("%d\n", ans);
  return 0;
}
