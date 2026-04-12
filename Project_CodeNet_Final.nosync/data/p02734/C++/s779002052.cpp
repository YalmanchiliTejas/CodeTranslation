#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;
const ll mod = 998244353;

int main()
{
  ll n, s; cin >> n >> s;
  vector<ll> a(n);
  for (int i=0; i<n; i++){
    cin >> a[i];
  }
  vector<vector<ll>> dp(n+2, vector<ll>(s+1, 0));
  ll ans = 0;
  rep(i, n) {
    (dp[i][0] += 1) %= mod;
    (dp[i+1][0] += 1) %= mod;
    rep(j, s+1-a[i]) {
      (dp[i+1][j+a[i]] += dp[i][j]) %= mod;
    }
    (ans += dp[i+1][s]) %= mod;
    dp[i+2] = dp[i+1];
  }
  cout << ans << endl;

  return 0;
}
