#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef long long ll;

int main () {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(20) << fixed;

  int n; cin >> n;
  vector<int> a(n, 0);
  
  rep(i, n) { cin >> a[i]; }
  sort(a.begin(), a.end());

  ll ans = 0;

  if (n & 1) {
    ll t = 0, s = 0;
    rep(i, n) {
      if ( i < n/2 ) {
        s -= 2 * a[i];
      } else {
        s += 2 * a[i];
      }
      if ( i <= n/2 ) {
        t -= 2 * a[i];
      } else {
        t += 2 * a[i];
      }
    }
    s -= (a[n/2] + a[n/2+1]);
    t += (a[n/2] + a[n/2-1]);
    ans = max(s, t);
  } else {
    rep(i, n) {
      if (i < n/2) {
        ans -= 2 * a[i];
      } else {
        ans += 2 * a[i];
      }
    }
    ans += ( a[n/2-1]-a[n/2] );
  }

  cout << ans << endl;

  return 0;
}
