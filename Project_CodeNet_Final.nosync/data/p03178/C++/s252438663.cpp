#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
ll dp[200][2][10000 + 100];
int main() {
  string S;
  int N;
  cin >> S >> N;
  dp[0][0][0] = 1;
  dp[0][1][0] = 1;
  REP(i, S.size()) {
    REP(j, N) {
      if (i != 0) {
        REP(k, 10) {
          int n = j + k;
          dp[n % N][0][i + 1] += dp[j][0][i];
          dp[n % N][0][i + 1] %= MOD;
        }
      }
    }
    REP(j, N) {
      int a = S[i] - '0';
      REP(k, a + 1) {
        int n = j + k;
        if (a != k) {
          dp[n % N][0][i + 1] += dp[j][1][i];
          dp[n % N][0][i + 1] %= MOD;
        } else {
          dp[n % N][1][i + 1] += dp[j][1][i];
          dp[n % N][1][i + 1] %= MOD;
        }
      }
    }
  }
  cout << (dp[0][0][S.size()] + dp[0][1][S.size()] + MOD - 1) % MOD << endl;
}
