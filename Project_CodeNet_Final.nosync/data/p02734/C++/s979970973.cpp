#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
const ll mod = 998244353;

int main(){
  ll n, s;
  cin >> n >> s;
  ll a[n];
  rep(i,n) cin >> a[i];
  ll ans = 0;
  vector<vector<ll>> dp(n+1,vector<ll>(s+1,0));
  rep(i,n) {
    rep(j,s+1) {
      dp[i+1][j] += dp[i][j];
      if(j == 0 && a[i] <= s) {
        (dp[i+1][a[i]] += i+1) %= mod;
      } else {
        if(j-a[i] >= 0) (dp[i+1][j] += dp[i][j-a[i]]) %= mod;
      }
    }
    (ans += dp[i+1][s]) %= mod;
  }
  cout << ans << endl;
  return 0;
}
