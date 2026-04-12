#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const ll INF = 1LL<<60;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  vector<vector<ll>> dp(n+5, vector<ll>(n+5,0));
  for (int w = 1; w <= n; ++w) {
    for (int l = 0; l <= n-w; ++l) {
      int r = l + w;
      if ((n - (r-l)) % 2 == 0) {
        dp[l][r] = max(a[l] + dp[l+1][r], a[r-1] + dp[l][r-1]);
      }
      else {
        dp[l][r] = min(-a[l] + dp[l+1][r], -a[r-1] + dp[l][r-1]);
      }
    }
  }
  cout << dp[0][n] << endl;
  return 0;
}