#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const int mod = 1000 * 1000 * 1000 + 7;

vector<vector<vector<int>>> dp;
int solve(const vector<int> &v, int current, bool is_top, int sum, int d) {
  sum = (sum + d) % d;

  if (current == -1) {
    return sum == 0;
  }

  int& ret = dp[current][is_top][sum];
  if (ret == -1) {
    ret = 0;
    int limit = is_top ? v[current] : 9;

    for (int digit = 0; digit <= limit; ++digit) {
      ret += solve(v, current - 1, is_top && digit == limit, sum + digit, d);
      ret %= mod;
    }
  }

  return ret;
}

int main() { IO;
  string k;
  int d;
  cin >> k >> d;

  vector<int> v(k.size());
  transform(k.begin(), k.end(), v.begin(), [](char c) { return c - '0'; });
  reverse(v.begin(), v.end());

  dp.resize(v.size());
  for (auto &g : dp) {
    g.resize(2);
    for (auto &v : g) {
      v.resize(d + 1);
      fill(v.begin(), v.end(), -1);
    }
  }

  int ans = solve(v, v.size() - 1, true, 0, d);
  ans = (ans - 1 + mod) % mod;
  cout << ans << endl;

  return 0;
}
