#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, s;
  cin >> n >> s;
  long dp[s+1] {};
  long res = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a <= s) for (int x = s; x; --x) {
      int y = x-a;
      if (y) {
        dp[x] += dp[y];
        dp[x] %= M;
      } else {
        dp[x] += i+1;
        dp[x] %= M;
        break;
      }
    }
    res += dp[s];
    res %= M;
  }
  cout << res << endl;
}
