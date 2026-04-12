#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long int;

int main() {
  string S;
  int K;
  cin >> S >> K;
  vector<ll> n(S.size());
  for (size_t i = 0; i < S.size(); i++) {
    n[i] = S[i] - 48;
  }

  vector<vector<vector<ll>>> dp(n.size() + 1,
                                vector<vector<ll>>(4, vector<ll>(2, 0)));

  dp[0][0][0] = 1;

  for (size_t i = 0; i < n.size(); i++) {
    for (size_t d = 0; d < 10; d++) {
      for (size_t k = 0; k <= 3; k++) {
        for (size_t l = 0; l < 2; l++) {
          int nk = (d == 0) ? k : k + 1;
          int nl = l;
          // 元の数より大きい or 0 でない数字が多すぎる
          if ((l == 0 && d > n[i]) || nk > K) {
            continue;
          }
          if (l == 0 && d < n[i]) {
            nl = 1;
          }
          dp[i + 1][nk][nl] += dp[i][k][l];
        }
      }
    }
  }

  cout << (dp[n.size()][K][0] + dp[n.size()][K][1]) << endl;
}