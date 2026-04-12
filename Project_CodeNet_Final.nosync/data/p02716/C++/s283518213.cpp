#include <bits/stdc++.h>
using namespace std;

long long solve(const vector<int> &v, int N, int K) {
  vector<vector<long long>> dp(K, vector<long long>(N, INT_MIN));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      long long tmp = numeric_limits<long long>::min();
      for (int k = 0; k <= j; ++k) {
        tmp = max(tmp, (i-2-j+k >= 0 ? dp[k][i-2-j+k] : 0));
      }
      dp[j][i] = tmp + v[i];
    }
  }
  long long result = numeric_limits<long long>::min();
  for (int k = 0; k < K; ++k) {
    result = max(result, dp[K-1-k][N-1-k]);
  }
  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;

  vector<int> v(N);
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
  }

  cout << solve(v, N, (N & 1) ? 3 : 2) << endl;

  return 0;
}