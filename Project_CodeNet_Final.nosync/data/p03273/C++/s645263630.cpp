// https://atcoder.jp/contests/abc107/tasks/abc107_b
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int H, W;
  cin >> H >> W;

  vector<char> mp(H * W);
  vector<bool> col(W, true);
  vector<bool> row(H, true);

  rep(i, H) {
    rep(j, W) {
      cin >> mp.at(i * W + j);
      if (mp.at(i * W + j) == '#') {
        row.at(i) = false;
        col.at(j) = false;
      }
    }
  }

  rep(i, H) {
    if (row.at(i)) continue;
    rep(j, W) {
      if (col.at(j)) continue;
      putchar(mp.at(i * W + j));
    }
    cout << endl;
  }

  return 0;
}
