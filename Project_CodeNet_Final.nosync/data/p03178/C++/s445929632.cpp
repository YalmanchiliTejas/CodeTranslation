#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf = 1 << 20;
const int mod = 1e9 + 7;

ll dp[100005][2][105];
int ctoi(char c) { return c - '0'; }
int main() {
   string K;
   int D;
   cin >> K >> D;

   dp[0][0][0] = 1;
   rep(i, 0, K.size()) rep(j, 0, D) {
      int k = ctoi(K[i]);
      rep(digit, 0, 10)(dp[i + 1][1][(j + digit) % D] += dp[i][1][j]) %= mod;
      rep(digit, 0, k)(dp[i + 1][1][(j + digit) % D] += dp[i][0][j]) %= mod;
      (dp[i + 1][0][(j + k) % D] += dp[i][0][j]) %= mod;
   }
   int ans = (dp[K.size()][0][0] + dp[K.size()][1][0] - 1 + mod) % mod;
   cout << ans << endl;
   return 0;
}