#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long dp[2] = {0};
  long long x, acc_l;
  cin >> acc_l;
  for (int i = 2; i <= n; ++i) {
    cin >> x;
    if (i&1) {
      dp[1] = max(dp[1] + x, dp[0]);
      acc_l += x;
    } else {
      dp[0] = max(acc_l, dp[0] + x);
    }
  }
  cout << dp[(n&1)] << endl;
}