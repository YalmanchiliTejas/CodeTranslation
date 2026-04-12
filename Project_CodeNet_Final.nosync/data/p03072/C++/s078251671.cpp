#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i,0,n) cin >> h[i];
  int ans = 1;
  rep(i,1,n) {
    bool flag = true;
    rep(j,0,i) {
      if (h[j] > h[i]) {
        flag = false;
      }
    }
    if (flag) ans++;
  }
  cout << ans << endl;
  return 0;
}
