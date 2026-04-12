#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  
  sort(a.rbegin(), a.rend());
  
  ll ans = 0;
  if (n % 2 == 0) {
    for (int i = 0; i < n; i++) {
      if (i < n / 2 - 1) ans += 2 * a.at(i);
      else if (i == n / 2 - 1) ans += a.at(i);
      else if (i == n / 2) ans -= a.at(i);
      else ans -= 2 * a.at(i);
    }
  }
  else {
    ll keep1 = 0, keep2 = 0;
    for (int i = 0; i < n; i++) {
      if (i < n / 2 - 1) keep1 += 2 * a.at(i);
      else if (i == n / 2 || i == n / 2 - 1) keep1 += a.at(i);
      else keep1 -= 2 * a.at(i);
    }
    for (int i = 0; i < n; i++) {
      if (i < n / 2) keep2 += 2 * a.at(i);
      else if (i == n / 2 || i == n / 2 + 1) keep2 -= a.at(i);
      else keep2 -= 2 * a.at(i);
    }
    ans = max(keep1, keep2);
  }
  
  cout << ans << '\n';
}