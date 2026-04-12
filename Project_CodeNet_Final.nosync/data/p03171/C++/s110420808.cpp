#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 3005
ll inf = 1e14;
ll mod = 1e9 + 7;
char en = '\n';

ll abs1(ll x) {
  if (x < 0)
    return -x;
  return x;
}
ll power(ll x, ll n, ll mod) {
  ll res = 1;
  while (n) {
    if (n & 1)
      res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}

ll dp[N][N][2];
ll arr[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k;
  cin >> n;
  for (ll i = 1; i <= n; i++)
    cin >> arr[i];

  memset(dp, 0, sizeof(dp));

  for (ll i = 1; i <= n; i++) {
    dp[i][i][0] = arr[i];
    dp[i][i][1] = -arr[i];
  }

  for (ll len1 = 2; len1 <= n; len1++) {
    for (ll i = 1; i <= n - len1 + 1; i++) {
      ll j = i + len1 - 1;
      dp[i][j][0] = max(arr[i] + dp[i + 1][j][1], arr[j] + dp[i][j - 1][1]);
      dp[i][j][1] = min(-arr[i] + dp[i + 1][j][0], -arr[j] + dp[i][j - 1][0]);
    }
  }

  cout << dp[1][n][0] << en;

  return 0;
}
