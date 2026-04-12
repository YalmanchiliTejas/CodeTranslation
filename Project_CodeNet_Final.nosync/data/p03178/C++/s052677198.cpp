#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (b); i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 2e9;
const int MOD = 1e9 + 7;

int dp[100005][2][105];
int main() {
   string K;
   int D;
   cin >> K >> D;

   dp[0][0][0] = 1;
   rep(i, 0, K.size()) {
      int k = K[i] - '0';
      rep(j, 0, D) {
         rep(digit, 0, 10)(dp[i + 1][1][(j + digit) % D] += dp[i][1][j]) %= MOD;
         rep(digit, 0, k)(dp[i + 1][1][(j + digit) % D] += dp[i][0][j]) %= MOD;
         (dp[i + 1][0][(k + j) % D] += dp[i][0][j]) %= MOD;
      }
   }
   int ans = (dp[K.size()][0][0] + dp[K.size()][1][0] - 1 + MOD) % MOD;
   cout << ans << endl;
   return 0;
}