#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx2")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <stack>

#include <x86intrin.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x: a) cin >> x;

/*
  if (n % 2 == 0) {
    ll now = 0;
    for (int i = 0; i < n; i += 2) now += a[i];
    ll maximum = now;
    for (int i = n-2; i >= 0; i -= 2) {
      now += (a[i+1] - a[i]);
      if (now > maximum) maximum = now;
    }

    cout << maximum << endl;
  }
  else {
    vector<vector<ll> > dp(n+2, vector<ll>(3, (ll) -1e18));
    dp[0][0] = a[0];
    dp[1][1] = a[1];
    dp[2][2] = a[2];
    for (int i = 0; i < n; i++) {
      if (i+2 < n) dp[i+2][0] = max(dp[i+2][0], dp[i][0] + a[i+2]);
      if (i+2 < n) dp[i+2][1] = max(dp[i+2][1], dp[i][1] + a[i+2]);
      if (i+2 < n) dp[i+2][2] = max(dp[i+2][2], dp[i][2] + a[i+2]);
      if (i+3 < n) dp[i+3][1] = max(dp[i+3][1], dp[i][0] + a[i+3]);
      if (i+3 < n) dp[i+3][2] = max(dp[i+3][2], dp[i][1] + a[i+3]);
      if (i+4 < n) dp[i+4][2] = max(dp[i+4][2], dp[i][0] + a[i+4]);
    }

    cout << max(max(dp[n-3][0], dp[n-2][1]), dp[n-1][2]) << endl;
  }
*/

  vector<ll> even(n/2+16);
  vector<ll> odd(n/2+16);
  for (int i = 0; i < n; i += 2) even[i/2] = a[i];
  for (int i = 1; i < n; i += 2) odd[i/2] = a[i];

  vector<vector<ll> > dp(3, vector<ll>(n/2+16, (ll) -1e18));
  dp[0][0] = even[0];
  for (int i = 0; i < n/2; i++) {
    dp[0][i+1] = dp[0][i] + even[i+1];
  }
  dp[1][0] = odd[0];
  for (int i = 0; i < n/2; i++) {
    dp[1][i+1] = max(dp[0][i], dp[1][i]) + odd[i+1];
  }
  dp[2][0] = even[1];
  for (int i = 0; i < n/2; i++) {
    dp[2][i+1] = max(max(dp[0][i], dp[1][i]), dp[2][i]) + even[i+2];
  }

  ll ans = max(dp[0][n/2-1], dp[1][n/2-1]);
  if (n % 2 == 1) ans = max(ans, dp[2][n/2-1]);

  cout << ans << endl;

  return 0;
}
