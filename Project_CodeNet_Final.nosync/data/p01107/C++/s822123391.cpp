#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  V<> di{1, 0, -1, 0}, dj{0, 1, 0, -1};
  while (true) {
    int n, m; cin >> n >> m;
    if (!n) break;
    V<string> s(n + 2, string(m + 2, '#'));
    for (int i = 1; i <= n; ++i) {
      cin >> s[i];
      s[i] = '#' + s[i] + '#';
    }
    VV<> vis(n + 2, V<>(m + 2));
    auto fn = [&](int si, int sj, int ti, int tj, int d0) -> bool {
      int i = si, j = sj, d = d0;
      VV<bool> b(n + 2, V<bool>(m + 2));
      for (int _ = 0; _ < 4 * n * m; ++_) {
        int ni = i + di[d], nj = j + dj[d];
        if (s[ni][nj] == '#') d = d + 1 & 3;
        else {
          d = d - 1 & 3;
          i = ni, j = nj;
          if (i == ti and j == tj) {
            for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
              vis[i][j] += b[i][j];
            }
            return true;
          }
          b[i][j] = true;
        }
      }
      return false;
    };
    [&]{
      if (!fn(1, 1, n, 1, 0) or !fn(n, 1, n, m, 1) or !fn(n, m, 1, m, 2) or !fn(1, m, 1, 1, 3)) {
        cout << "NO" << '\n';
        return;
      }
      for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if (vis[i][j] > 1) {
        cout << "NO" << '\n';
        return;
      }
      cout << "YES" << '\n';
    }();
  }
}
