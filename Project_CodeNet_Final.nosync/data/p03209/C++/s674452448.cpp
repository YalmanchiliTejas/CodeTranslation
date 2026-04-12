#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n;
  ll x;
  cin >> n >> x;

  vector<ll> p(n+1);
  p[0] = 1;
  ll total = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] * 2 + 1;
    total = total * 2 + 3;
  }

  ll l = 0;
  ll r = total;
  int k = n;
  ll ans = 0;
  while (l <= r) {
    ll mid = (r + l + 1) / 2;
    if (mid == x) {
      ans += (p[k] + 1) / 2;
      break;
    }

    if (mid > x) {
      l++;
      r = mid - 1;
      k--;
      continue;
    }

    if (mid < x) {
      ans += (p[k] + 1) / 2;
      l = mid + 1;
      r--;
      k--;
      continue;
    }
  }

  cout << ans << endl;
  return 0;
}