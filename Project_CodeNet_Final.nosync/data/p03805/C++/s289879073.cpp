#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int N, M;
vector<vector<int>> G;
vector<int> visited;

int dfs(int d, int cur) {
  if(d == N - 1) return 1;
  int ret = 0;
  for(auto p : G[cur]) {
    if(visited[p]) continue;
    visited[p] = true;
    ret += dfs(d + 1, p);
    visited[p] = false;
  }
  return ret;
}

int main() {
  cin >> N >> M;
  G.resize(N);
  visited.resize(N);
  rep(i, 0, M) {
    int a, b; cin >> a >> b; a--, b--;
    G[a].push_back(b); G[b].push_back(a);
  }
  visited[0] = true;
  cout << dfs(0, 0) << endl;
  return 0;
}
