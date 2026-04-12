#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int n, s;
vector<int> arr;

void solve() {
  // dp[i][j]到n[i-1]为止有多少个加起来等于j的开始点
  vector< vector<int> > dp(n + 1, vector<int>(s + 1, 0));
  int res = 0;
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = 1;
    for (int j = s; j >= 0; --j) {
      dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
      if (j + arr[i-1] <= s) {
        dp[i][j+arr[i-1]] = (dp[i][j+arr[i-1]] + dp[i-1][j]) % MOD;
      }
    }
    res = (res + dp[i][s]) % MOD;
  }
  // for (int i = 0; i <= n; ++i) {
  //   for (int j = 0; j <= s; ++j) {
  //     cout << dp[i][j] << ',';
  //   }
  //   cout << endl;
  // }
  cout << res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s;
  arr = vector<int>(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  solve();
  return 0;
}