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

LL dp[100001][2][101] = {};  // keta, smaller, sum % D

int main() {
  string S; cin >> S;
  int D; cin >> D;
  int N = S.size();
  dp[0][0][0] = 1;

  for (int i = 0; i < N; ++i) {
    int d = S[i] - '0';
    for (int sum = 0; sum < D; ++sum) {
      for (int n = 0; n < 10; ++n) {
        int nsum = (sum + n) % D;
        if (n < d) {
          dp[i + 1][1][nsum] += dp[i][0][sum] + dp[i][1][sum];
        } else if (n == d) {
          dp[i + 1][0][nsum] += dp[i][0][sum];
          dp[i + 1][1][nsum] += dp[i][1][sum];
        } else {
          dp[i + 1][1][nsum] += dp[i][1][sum];
        }

        dp[i + 1][0][nsum] %= kMod;
        dp[i + 1][1][nsum] %= kMod;
      }
    }
  }
  cout << (dp[N][0][0] + dp[N][1][0] + kMod - 1) % kMod << endl;
}
