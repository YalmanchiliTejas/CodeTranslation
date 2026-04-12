#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  rep(i, h) rep(j, w) cin >> a.at(i).at(j);
  // 行、列ごとの . の数
  vector<int> hh(h, 0);
  vector<int> ww(w, 0);
  rep(i, h) {
    rep(j, w) {
      if (a.at(i).at(j) == '.') {
        hh[i]++;
        ww[j]++;
      }
    }
  }
  rep(i, h) {
    if (hh.at(i) == w) {
      continue;
    }
    rep(j, w) {
      if (ww.at(j) == h) {
        continue;
      }
      cout << a.at(i).at(j);
    }
    cout << endl;
  }
  return 0;
}
