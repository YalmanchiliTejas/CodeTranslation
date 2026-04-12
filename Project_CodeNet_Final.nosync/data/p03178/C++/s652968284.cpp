#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e4 + 4;
const int maxd = 102;
int dp[maxn][maxd];
const int mod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  // cin.tie(NULL);

  string k;
  cin >> k;
  int d;
  cin >> d;
  dp[0][0] = 1;
  for (int i = 0; i < k.size(); i++) {
    for (int j = 0; j < d; j++) {
      for (int p = 0; p < 10; p++) {
        int nexj = (j + p) % d;
        dp[i + 1][nexj] = (dp[i + 1][nexj] + dp[i][j]) % mod;
      }
    }
  }
  int cur = 0;
  int ans = 0;
  for (int i = 0; i < k.size(); i++) {
    for (int j = 0; j < k[i] - '0'; j++) {
      ans = (ans + dp[k.size() - i - 1][(d - ((cur + j) % d)) % d]) % mod;
    }
    cur = (cur + k[i] - '0') % d;
  }
  if (cur == 0) ans++;
  cout << (ans - 1 + mod) % mod << '\n';

  return 0;
}
