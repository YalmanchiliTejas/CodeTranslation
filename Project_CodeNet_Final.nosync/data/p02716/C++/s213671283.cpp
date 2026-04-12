#include <bits/stdc++.h>

using namespace std;

const int64_t INF = 1LL << 60;

template <typename T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  const int skip = 1 + (N % 2);
  vector<vector<int64_t>> dp(N + 2, vector<int64_t>(skip + 1, -INF));
  dp[0][0] = 0;
  for (int i = 0; i < N + 1; i++) {
    for (int j = 0; j < skip + 1; j++) {
      if (j < skip) chmax(dp[i + 1][j + 1], dp[i][j]);
      if (i < N) chmax(dp[i + 2][j], dp[i][j] + A[i]);
    }
  }
  cout << dp[N + 1][skip] << '\n';
  return 0;
}
