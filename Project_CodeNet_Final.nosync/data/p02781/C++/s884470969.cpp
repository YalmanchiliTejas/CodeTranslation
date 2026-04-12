#include <cstring>
#include <iostream>
#include <string>
using namespace std;

using ll = long long;

ll dp[110][2][110];

int main() {
  string N;
  int K;
  cin >> N >> K;

  memset(dp, 0, sizeof(dp));
  dp[0][1][0] = 1;

  for(int n = 0; n < N.size(); ++n) {
    for(int limited : {0, 1}) {
      int limit = (limited ? N[n] - '0' : 9);
      for(int i = 0; i <= limit; ++i) {
        for(int k = 0; k <= N.size(); ++k) {
          int add = i != 0 ? 1 : 0;
          dp[n + 1][limited && (i == limit)][k + add] += dp[n][limited][k];
        }
      }
    }
  }
  ll result = dp[N.size()][0][K] + dp[N.size()][1][K];
  cout << result << endl;
  return 0;
}