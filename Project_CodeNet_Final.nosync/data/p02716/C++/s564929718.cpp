#include <iostream>
#include <assert.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;
constexpr int64_t MOD = 1e15 + 7;
constexpr int64_t MIN = -(1LL << 60);

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int32_t N;
  cin >> N;
  vector<int64_t> A(N);
  for (auto& a : A) {
    cin >> a;
  }

  vector<vector<vector<int64_t>>> dp(N+1, vector<vector<int64_t>>(2, vector<int64_t>(3, MIN)));
  dp[0][1][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 3; k++) {
        if (k + j < 3) dp[i+1][1][k+j] = max(dp[i+1][1][k+j], dp[i][j][k]);
        if (j == 1) dp[i+1][0][k] = max(dp[i+1][0][k], dp[i][1][k] + A[i]);
      }
    }
  }
  if (N%2 == 0) cout << max(dp[N][1][0], dp[N][0][1]) << endl;
  else cout << max(dp[N][0][2], dp[N][1][1]) << endl;
  return 0;
}
