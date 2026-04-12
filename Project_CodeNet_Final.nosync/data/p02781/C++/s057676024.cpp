#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  string N;
  cin >> N;
  int K;
  cin >> K;

  const int M = N.size();
  vector<vector<vector<ll>>> dp(M + 1,
                                vector<vector<ll>>(K + 2, vector<ll>(2, 0)));
  dp[0][0][0] = 1;

  for (int i = 0; i < (int)M; ++i) for (int j = 0; j < (int)K + 1; ++j) {
    dp[i + 1][j + (N[i] != '0')][0] += dp[i][j][0];
    if (N[i] != '0') dp[i + 1][j][1] += dp[i][j][0];
    dp[i + 1][j + 1][1] += (N[i] - '0' - (N[i] >= '1')) * dp[i][j][0];
    dp[i + 1][j][1] += dp[i][j][1];
    dp[i + 1][j + 1][1] += 9 * dp[i][j][1];
  }

  cout << dp[M][K][0] + dp[M][K][1] << endl;
  return 0;
}
