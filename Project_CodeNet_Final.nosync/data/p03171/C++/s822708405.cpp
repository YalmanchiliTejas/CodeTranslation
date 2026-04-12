#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<vector<ll>> dp(n+1, vector<ll>(n+1));
  for (int len = 1; len <= n; len++) {
    for (int i = 0; i+len <= n; i++) {
      int j = i+len;
      if ((n-len)%2 == 0)
        dp[i][j] = max(dp[i+1][j]+a[i], dp[i][j-1]+a[j-1]);
      else
        dp[i][j] = min(dp[i+1][j]-a[i], dp[i][j-1]-a[j-1]);
    }
  }
  cout << dp[0][n] << endl;
  return 0;
}