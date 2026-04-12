#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> h(n), w(n); for (int i = 0; i < n; ++i) cin >> h[i] >> w[i];
  V<string> s(4); for (auto&& e : s) cin >> e;
  V<> d(1 << 16, -1);
  queue<int> que;
  d[0] = 0;
  que.push(0);
  while (!que.empty()) {
    int bit = que.front(); que.pop();
    if (bit == ~(~0 << 16)) return cout << d.back() << '\n', 0;
    for (int k = 0; k < n; ++k) {
      for (int x = 1 - h[k]; x < 4; ++x) for (int y = 1 - w[k]; y < 4; ++y) {
        int nbit = bit;
        int r = 0, g = 0, b = 0;
        for (int i = max(x, 0); i < min(x + h[k], 4); ++i) for (int j = max(y, 0); j < min(y + w[k], 4); ++j) {
          if (bit >> i * 4 + j & 1) continue;
          r += s[i][j] == 'R';
          g += s[i][j] == 'G';
          b += s[i][j] == 'B';
          nbit |= 1 << i * 4 + j;
        }
        if (d[nbit] == -1 and r + g + b and max({r, g, b}) == r + g + b) {
          d[nbit] = d[bit] + 1;
          que.push(nbit);
        }
      }
    }
  }
}
