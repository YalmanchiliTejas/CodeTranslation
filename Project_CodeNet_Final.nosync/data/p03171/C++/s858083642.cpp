#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long> a(N);
  for (auto &v : a) {
    cin >> v;
  }
  vector<vector<long>> dp(N, vector<long>(N));
  for (int l = N - 1; l >= 0; --l) {
    for (int r = l; r < N; ++r) {
      if (l == r) {
        dp[l][r] = a[l];
      } else {
        dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
      }
    }
  }
  cout << dp[0][N - 1];
  return 0;
}