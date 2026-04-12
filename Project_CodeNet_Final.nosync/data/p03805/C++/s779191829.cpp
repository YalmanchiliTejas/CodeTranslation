#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

vector<vector<int>> G;
int n, m, a, b;

void dfs(int v, vector<bool> &seen, int &ans) {
  bool ok = true;
  rep(i, n) if (!seen[i] && i != v) ok = false;

  if (ok) ans++;

  seen[v] = true;
  for (auto nv : G[v]) {
    if (seen[nv]) continue;
    dfs(nv, seen, ans);
  }
  seen[v] = false;
}

int main() {
  cin >> n >> m;
  G.assign(n, vector<int>());
  rep(i, m) {
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<bool> seen(n, false);
  int ans = 0;
  dfs(0, seen, ans);

  cout << ans << endl;
  return 0;
}
