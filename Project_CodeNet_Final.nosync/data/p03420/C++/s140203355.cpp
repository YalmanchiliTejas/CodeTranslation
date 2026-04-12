#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 1; i <= (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, k, ans = 0;
  cin >> n >> k;
  rep(b, n) ans += (n / b) * max(0LL, b - k) + max(0LL, n % b - k + 1);

  if (k == 0) ans -= n;

  cout << ans << endl;
  return 0;
}
