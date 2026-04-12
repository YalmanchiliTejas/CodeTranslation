#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  rep(i, h) {
    rep(j, w) {
      cin >> a[i][j];
    }
  }
  vector<bool> elim_y(h, false), elim_x(w, false);
  rep(i, h) {
    bool white = true;
    rep(j, w) {
      if (a[i][j] == '#') white = false;
    }
    if (white) elim_y[i] = true;
  }
  rep(j, w) {
    bool white = true;
    rep(i, h) {
      if (a[i][j] == '#') white = false;
    }
    if (white) elim_x[j] = true;
  }
  for (int i = 0; i < h; i++) {
    if (elim_y[i]) {
      a.erase(a.begin() + i);
      elim_y.erase(elim_y.begin() + i);
      h = (int)a.size();
      i--;
    }
  }
  for (int j = 0; j < w; j++) {
    if (elim_x[j]) {
      rep(i, h) {
        a[i].erase(a[i].begin() + j);
      }
      elim_x.erase(elim_x.begin() + j);
      w = (int)a[0].size();
      j--;
    }
  }
  rep(i, h) {
    rep(j, w) {
      cout << a[i][j];
    }
    cout << '\n';
  }
  return 0;
}