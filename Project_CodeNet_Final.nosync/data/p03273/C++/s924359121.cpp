#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i,h) cin >> a[i];
  vector<int> y;
  vector<string> ans;
  rep(i,h) {
    int cnt = 0;
    rep(j,w) if(a[i][j] == '.') cnt++;
    if(cnt != w) ans.push_back(a[i]);
  }
  rep(j,w) {
    int cnt = 0;
    rep(i,h) if(a[i][j] == '.') cnt++;
    if(cnt == h) y.push_back(j);
  }
  if ((int) y.size() > 0) {
    rep(i,(int)ans.size()) {
      int k = 0;
      rep(j,w) {
      if (y[k] == j) {
          if (k < ((int)y.size()-1)) k++;
          continue;
        } else cout << ans[i][j];
      }
      cout << endl;
    }
  } else {
    rep(i,(int)ans.size()) cout << ans[i] << endl;
  }
  
  return 0;
}