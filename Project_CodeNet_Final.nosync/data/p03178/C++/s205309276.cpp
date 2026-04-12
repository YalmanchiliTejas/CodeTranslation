#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void add(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  string s;
  cin >> s;
  int d;
  cin >> d;
  static long long dp[10005][105][2] = {};
  dp[0][0][0] = 1;
  int n = (int) s.length();
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < 2; k++) {
      int cur = k ? 9 : s[i] - '0';
      for (int j = 0; j < d; j++) {
        for (int l = 0; l <= cur; l++) {
          add(dp[i + 1][(j + l) % d][k || l < cur], dp[i][j][k]);
        }
      }
    }
  }
  cout << (mod + dp[n][0][0] + dp[n][0][1] - 1) % mod << endl; 
  return 0;	
}