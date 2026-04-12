#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(15);

  int n, m;
  cin >> n >> m;
  vector<vector<bool>> p(n, vector<bool>(n, false));
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    p[a][b] = true;
    p[b][a] = true;
  }

  vector<int> g(n);
  for (int i = 0; i < n; ++i) {
    g[i] = i;
  }

  int ans = 0;
  do {
    if (g[0] != 0) break;
    bool ok = true;
    for (int i = 1; i < n; ++i) {
      if (!p[g[i - 1]][g[i]]) {
        ok = false;
        break;
      }
    }
    if (ok) ++ans;
  } while (next_permutation(g.begin(), g.end()));

  cout << ans << '\n';

  return 0;
}
