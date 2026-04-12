#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  int mx = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x >= mx) ans++;
    mx = max(x, mx);
  }
  cout << ans << endl;
  return 0;
}