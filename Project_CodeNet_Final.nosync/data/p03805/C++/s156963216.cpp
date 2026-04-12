#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<bool>> g(n, vector<bool>(n, false));

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a][b] = true;
    g[b][a] = true;
  }

  vector<int> p(n);
  for (int i = 0; i < n; i++)
    p[i] = i;

  int ans = 0;
  do {
    if (p[0] != 0)
      continue;

    bool ok = true;
    for (int i = 0; i + 1 < n; i++) {
      int f = p[i], t = p[i + 1];
      if (!(g[f][t] || g[t][f])) {
        ok = false;
      }
    }

    if (ok) {
      ans++;
    }

  } while (next_permutation(p.begin(), p.end()));

  cout << ans << endl;

  return 0;
}
