#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> a(H);
  rep(i, H) cin >> a[i];

  vector<bool> row(H, false);
  vector<bool> col(W, false);

  rep(i, H) {
    rep(j, W) {
      if (a[i][j] == '#') {
        row[i] = true;
        col[j] = true;
      }
    }
  }

  rep(i, H) {
    if (row[i]) {
      rep(j, W) {
        if (col[j]) {
          cout << a[i][j];
        }
      }
      cout << endl;
    }
  }
  return 0;
}