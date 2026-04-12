#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll dp[3300][3300];

int main() {
  ll n;
  cin >> n;
  vll a(n);
  rep(i,n) cin >> a.at(i);
  rep(i,n) dp[i][i] = 0;
  for(ll width = 1; width <= n; width++) {
    for(ll l = 0; l + width <= n; l++) {
      ll r = l + width;
      if(width%2 == n%2) {
        dp[l][r] = max(dp[l+1][r]+a[l],dp[l][r-1]+a[r-1]);
      }
      else dp[l][r] = min(dp[l+1][r]-a[l],dp[l][r-1]-a[r-1]);
    }
  }
  cout << dp[0][n] << endl;
  return 0;
}