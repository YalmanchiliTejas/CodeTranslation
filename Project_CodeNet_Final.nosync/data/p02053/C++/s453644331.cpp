#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int h, w; cin >> h >> w;
  V<string> s(h); for (auto&& e : s) cin >> e;
  V<> l(h, w), r(h, -1);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) if (s[i][j] == 'B') {
      l[i] = min(l[i], j);
      r[i] = max(r[i], j);
    }
  }
  int res = 0;
  for (int i = 0; i < h; ++i) if (s[i].find('B') != string::npos) {
    for (int x = 0; x < h; ++x) if (s[x].find('B') != string::npos) {
      res = max(res, abs(i - x) + abs(l[i] - r[x]));
    }
  }
  cout << res << '\n';
}
