#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, k;
  cin >> n >> k;

  ll ans = 0;
  for (ll b = 1; b <= n; b++)
    ans += n / b * max((ll)0, b - k) + max((ll)0, n % b - k + 1);
  if (k == 0) ans -= n;
  cout << ans << endl;
  return 0;
}
