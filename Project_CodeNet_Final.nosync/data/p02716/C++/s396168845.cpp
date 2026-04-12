#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<vector<ll>> dp(n+1, vector<ll>(3, -LINF));
  dp[0][1] = 0;
  dp[1][1] = 0;
  dp[1][2] = a[0];
  for (int i = 2; i <= n; i++) {
    ll mn = i/2-1, mx = (i+1)/2;
    for (ll num = mn; num <= mx; num++) {
      int j = num-mn;
      if (num-((i-1)/2-1) >= 0 && num-((i-1)/2-1) <= 2)
        chmax(dp[i][j], dp[i-1][num-((i-1)/2-1)]);
      if (num-1-((i-2)/2-1) >= 0 && num-1-((i-2)/2-1) <= 2)
        chmax(dp[i][j], dp[i-2][num-1-((i-2)/2-1)]+a[i-1]);
    }
  }
  cout << dp[n][1] << endl;
  return 0;
}