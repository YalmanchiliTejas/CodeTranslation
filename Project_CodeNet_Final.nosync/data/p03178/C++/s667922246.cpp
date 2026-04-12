#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string k;
  int d;
  cin >> k >> d;

  int n = k.size();

  vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(10, vector<ll>(d)));
  vector<ll> prev(d);
  
  ll total = 0;
  for (int len = 1; len <= n; ++len) {
    total = prev[0];
    for (int i = 0; i < 10; ++i) {
      for (int dig = 0; dig < d; ++dig) {
        dp[len][i][(dig + i) % d] += prev[dig];
      }
      ++dp[len][i][i % d];
    }
    for (int dig = 0; dig < d; ++dig) {
      for (int i = 1; i < 10; ++i) {
        dp[len][i][dig] %= mod;
        prev[dig] += dp[len][i][dig];
      }
      prev[dig] %= mod;
    }
  }

  ll offset = 0;
  for (int i = 0; i < n; ++i) {
    for (int digit = i == 0; digit < k[i] - '0'; ++digit) {
      total += dp[n - i][digit][((-offset) % d + d) % d];
    }
    total = (total + mod) % mod;
    offset += k[i] - '0';
  }
  if (offset % d == 0) {
    ++total;
  }
  cout << total % mod << '\n';

  return 0;
}
