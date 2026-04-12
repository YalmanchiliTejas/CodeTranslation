#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long int;

int main() {
  string S;
  int K;
  cin >> S >> K;

  vector<int> N(S.size());
  for (size_t i = 0; i < S.size(); i++) {
    N[i] = S[i] - '0';
  }

  ll dp[200][4][2] = {};
  dp[0][0][0] = 1;

  for (size_t i = 0; i < N.size(); i++) {
    for (size_t d = 0; d < 10; d++) {
      for (size_t k = 0; k < 4; k++) {
        for (size_t l = 0; l <= 1; l++) {
          int nk = k;
          if (d != 0) {
            nk++;
          }
          if ((l == 0 && N[i] < d) || nk > 3) {
            continue;
          }
          int nl = l;
          if (N[i] > d) {
            nl = 1;
          }
          dp[i + 1][nk][nl] += dp[i][k][l];
        }
      }
    }
  }

  cout << (dp[N.size()][K][1] + dp[N.size()][K][0]) << endl;
}