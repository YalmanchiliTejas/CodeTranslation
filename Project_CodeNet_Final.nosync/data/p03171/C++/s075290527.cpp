#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int main() {
  int N; cin >> N;
  vector<vector<LL>> dp(N, vector<LL>(N));
  for (int i = 0; i < N; ++i) {
    cin >> dp[i][i];
  }
  for (int j = 1; j < N; ++j) {
    for (int i = 0; i + j < N; ++i) {
      dp[i][i + j] = max(
          dp[i][i] - dp[i + 1][i + j],
          dp[i + j][i + j] - dp[i][i + j - 1]
      );
    }
  }
  cout << dp[0][N-1] << endl;
}
