/**
 *    author:  tourist
 *    created: 09.01.2020 00:03:40       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  function<int(int, int)> Dfs = [&](int v, int pr) {
    int d = 1;
    for (int u : g[v]) {
      if (u == pr) {
        continue;
      }
      d -= Dfs(u, v);
    }
    if (d < 0 || (v == 0 && d == 1)) {
      cout << "First" << '\n';
      exit(0);
    }
    return d;
  };
  Dfs(0, -1);
  cout << "Second" << '\n';
  return 0;
}
