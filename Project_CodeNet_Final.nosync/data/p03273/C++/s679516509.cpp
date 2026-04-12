#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];
  vector<bool> rm_h(h, true), rm_w(w, true);
  rep(i, h) rep(j, w) if (a[i][j] == '#') {
    rm_h[i] = false;
    rm_w[j] = false;
  }
  rep(i, h) {
    if (rm_h[i]) continue;
    rep(j, w) {
      if (rm_w[j]) continue;
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}