#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<vector<bool>> g(n, vector<bool>(n, false));
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a][b] = true;
    g[b][a] = true;
  }

  vector<int> order(n);
  iota(order.begin(), order.end(), 0);

  int ans = 0;
  do {
    bool ok = true;
    for (int i = 0; i < order.size() - 1 && ok; ++i) {
      if (!g[order[i]][order[i + 1]]) {
        ok = false;
      }
    }

    if (ok) {
      ans++;
    }
  } while (next_permutation(order.begin() + 1, order.end()));

  cout << ans << '\n';
  return 0;
}