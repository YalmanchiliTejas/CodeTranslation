#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <numeric>
#include <string>
#include <cassert>
#include <bitset>

using namespace std;
typedef long long ll;

int main() {
  string S;
  int K;
  cin >> S >> K;
  int N = S.size();

  vector<vector<int> > dp(N, vector<int>(K + 1));
  
  // init
  dp[0][0] = 1;
  dp[0][1] = int(S[0] - '0') - 1;
  int X = 1;

  // iterate
  for (int i = 1; i < N; ++i) {
    dp[i][0] = dp[i - 1][0];
    for (int j = 1; j <= K; ++j) {
      dp[i][j] = dp[i - 1][j - 1] * 9 + dp[i - 1][j];
    }
    
    if (S[i] != '0') {
      if (X <= K) dp[i][X] += 1;
      if (X + 1 <= K) dp[i][X + 1] += (S[i] - '0') - 1;
      ++X;
    }
  }

  // terminate
  if (X <= K)  dp[N - 1][X] += 1;
  cout << dp[N - 1][K] << endl;
  
  return 0;
}
