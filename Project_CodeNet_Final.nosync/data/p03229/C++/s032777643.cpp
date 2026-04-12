#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  vector<int> d(n-1);
  rep(i, n-1) d[i] = a[i+1] - a[i];
  ll ans = 0;
  int l = 1, r = n-1;
  rep(i, n-1) ans += (ll)d[i] * 2 * min(l++, r--);
  if (n % 2 == 1) ans -= min(d[(n-3)/2], d[(n-1)/2]);
  else ans -= d[(n-2)/2];
  cout << ans << endl;
  return 0;
}