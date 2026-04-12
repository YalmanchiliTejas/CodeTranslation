#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  rep(i,0,H) cin >> a[i];

  vector<bool> row(H, false);
  vector<bool> col(W, false);
  rep(i, 0, H) {
    rep(j, 0, W) {
      if (a[i][j] == '#') {
        row[i] = true;
        col[j] = true;
      }
    }
  }

  rep(i, 0, H) {
    if (row[i]) {
      rep(j, 0, W) {
        if (col[j]) {
          cout << a[i][j];
        }
      }
      cout << endl;
    }
  }
}
