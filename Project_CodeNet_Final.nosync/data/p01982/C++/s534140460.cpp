#include <bits/stdc++.h>
using namespace std;
#define REP(i, s, e) for(int i = (int)(s); i < (int)(e); ++i)
#define rep(i, n) REP(i, 0, n)

int main() {
  int n, l, r;
  while(cin >> n >> l >> r) {
    if(n == 0 && l == 0 && r == 0) break;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    REP(i, l, r+1) {
      bool f = n&1;
      rep(j, n) {
	if(i % a[j] == 0) {
	  f = j&1;
	  break;
	}
      }
      if(!f) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}

