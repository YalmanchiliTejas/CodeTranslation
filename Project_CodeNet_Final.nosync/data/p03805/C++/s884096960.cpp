#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

using ll = long long;
using ld = long double;

#ifdef EBUG
#define debug(x) cout << "\033[31m" << #x << ": " << x << "\033[0m\n";
#else
#define debug(x)
#endif

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll n, m, a[30], b[30];
bool g[10][10];

ll dfs(bool seen[10], int node) {
  seen[node] = true;

  bool all_seen = true;
  rep(i, n) {
    if (seen[i] == false) {
      all_seen = false;
    }
  }
  if (all_seen) {
    return 1;
  }

  ll c = 0;
  rep(i, n) {
    if (g[node][i]) {
      if (seen[i]) {
        continue;
      }
      debug(node);
      debug(i);
      c += dfs(seen, i);
      seen[i] = false;
    }
  }
  return c;
}

int main() {
  cin >> n >> m;
  rep(i, m) {
    cin >> a[i] >> b[i];
    g[a[i] - 1][b[i] - 1] = true;
    g[b[i] - 1][a[i] - 1] = true;
  }

  bool seen[10];
  rep(i, n) {
    seen[i] = false;
  }

  cout << dfs(seen, 0) << endl;
}