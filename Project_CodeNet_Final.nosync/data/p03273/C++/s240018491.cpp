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
  vector<bool> show_y(h, false), show_x(w, false);
  rep(i, h) {
    rep(j, w) {
      cin >> a[i][j];
      if (a[i][j] == '#') {
        show_y[i] = true;
        show_x[j] = true;
      }
    }
  }
  rep(i, h) {
    if (show_y[i]) {
      rep(j, w) {
        if (show_x[j]) {
          cout << a[i][j];
        }
      }
      cout << '\n';
    }
  }
  return 0;
}