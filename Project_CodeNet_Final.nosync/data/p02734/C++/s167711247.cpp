#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
const ll INF = 1LL<<60;
const ll mod = 998244353;

int main()
{
  ll n, s; cin >> n >> s;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<vector<ll>> dp(n+1, vector<ll>(s+1, 0));
  ll ans = 0;
  for (int i=0; i<n; i++) {
    (dp[i][0] += 1) %= mod;
    dp[i+1] = dp[i];
    rep(j, s+1-a[i]) {
      (dp[i+1][j+a[i]] += dp[i][j]) %= mod;
    }
    (ans += dp[i+1][s]) %= mod;
  }
  cout << ans << endl;

  return 0;
}
