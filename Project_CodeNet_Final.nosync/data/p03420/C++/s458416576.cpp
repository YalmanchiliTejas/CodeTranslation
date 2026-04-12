#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(int argc, const char *argv[]) {
  ll n, k;
  cin >> n >> k;

  // bを固定する
  ll ans = 0;
  for (ll b = 1; b <= n; b++) {
    ll p = n / b;
    ll r = n - p * b;
    ans += p * max(0ll, b - k);
    ans += max(0ll, r - k + 1);
  }

  if (k == 0) {
    ans -= n;
  }
  cout << ans << '\n';
  return 0;
}
