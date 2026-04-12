#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int H, W; cin >> H >> W;
  
  vector<string> a(H);
  rep(i, H) cin >> a[i];
  
  vector<vector<bool>> t(H, vector<bool>(W, true));
  
  rep(i, H) {
    bool k = false;
    rep(j, W) if(a[i][j] == '#') k = true;
    if(!k) rep(j, W) t[i][j] = false;
  }
  rep(j, W) {
    bool k = false;
    rep(i, H) if(a[i][j] == '#') k = true;
    if(!k) rep(i, H) t[i][j] = false;
  }
  
  rep(i, H) {
    bool k = false;
    rep(j, W) {
      if(t[i][j]) {
        cout << a[i][j];
        k = true;
      }
    }
    if(k) cout << endl;
  }
}