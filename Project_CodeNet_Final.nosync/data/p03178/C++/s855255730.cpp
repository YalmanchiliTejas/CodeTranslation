#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <bitset>
using namespace std;

typedef long long ll;

const int MOD = 1000000000 + 7;
const int MAX_DIGIT = 10001;
const int MAX_D = 101;

ll dp[MAX_DIGIT][2][MAX_D];


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int N = s.size();

  int K[N];
  for (int i = 0; i < s.size(); i++) K[i] = s[i] - '0';
  
  int D;
  cin >> D;

  dp[0][0][0] = 1;
  
  for (int i = 0; i < N; i++) {
    for (int d = 0; d < D; d++) {
      
      for (int k = 0; k <= 9; k++) {
	dp[i + 1][1][(d + k) % D] += dp[i][1][d];
	dp[i + 1][1][(d + k) % D] %= MOD;
      }
      
      for (int k = 0; k < K[i]; k++) {
	dp[i + 1][1][(d + k) % D] += dp[i][0][d];
	dp[i + 1][1][(d + k) % D] %= MOD;
      }

      dp[i + 1][0][(d + K[i]) % D] += dp[i][0][d];
      dp[i + 1][0][(d + K[i]) % D] %= MOD;
      
    }
  }

  int res = (dp[N][0][0] + dp[N][1][0] - 1 + MOD) % MOD;
  cout << res << endl;
  
  return 0;
}

