#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int N, M;
vector<vector<int>> G;

int dfs(int d, int cur, int v) {
  if(v + 1 == 1 << N) return 1;
  int ret = 0;
  for(int nx : G[cur]) {
    int bit = 1 << nx;
    if(!(v & bit)) ret += dfs(d + 1, nx, bit | v);
  }
  return ret;
}
int main() {
  cin >> N >> M;
  G.resize(N);
  rep(i, 0, M) {
    int a, b; cin >> a >> b; a--, b--;
    G[a].push_back(b); G[b].push_back(a);
  }
  cout << dfs(0, 0, 1) << endl;
  return 0;
}
