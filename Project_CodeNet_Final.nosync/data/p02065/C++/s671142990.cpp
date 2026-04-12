#include <bits/stdc++.h>
using namespace std;

long long n, k, m;
vector<vector<vector<long long>>> dp;

long long solve();

int main() {
  cin >> n >> k >> m;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  dp.assign(2 * n + 1,
            vector<vector<long long>>(
                n + 1, vector<long long>(1LL << k, 0)));
  dp[1][1][1] = 1;
  for(int i = 1; i < 2 * n; ++i) {
    for(int j = 1; j <= n; ++j) {
      for(int s = 0; s < (1LL << k); ++s)
        if(j >= i - j && j - (i - j) <= k) {
          int up = -100, upright = -1, down = 1, id = j;
          for(int l = 0; l < min(k, (long long)i); ++l) {
            if(!(s >> l & 1) && down == 1) down = i - l;
            if(s >> l & 1) {
              if(upright == -1) upright = i - l;
              if(id == i - j + 1) up = i - l;
              --id;
            }
          }
          if(i + 1 - upright <= k && j < n)
            (dp[i + 1][j + 1][(s << 1) % (1LL << k) + 1] +=
             dp[i][j][s]) %= m;
          if(i + 1 - min(up, down) <= k)
            (dp[i + 1][j][(s << 1) % (1LL << k)] +=
             dp[i][j][s]) %= m;
        }
    }
  }
  long long res = 0;
  for(int i = 0; i < (1LL << k); ++i)
    (res += dp[2 * n][n][i]) %= m;
  return res;
}
