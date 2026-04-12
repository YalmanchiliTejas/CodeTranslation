#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007LL;

string k;
int d;
int n;

ll dp[10005][105][2];

ll solve(int index, int total, bool skip) {
  if (index == n) {
    return (total == 0) ? 1LL : 0LL;
  }
  ll& res = dp[index][total][skip];
  if (res != -1LL) {
    return res;
  }
  int cur = k[index] - '0';
  res = 0;
  for (int i = 0; i < 10; i++) {
    bool stop = skip && (i > cur);
    if (stop) {
      break;
    }
    bool keepSkip = skip && (i == cur);
    res = (res + solve(index + 1, (total + i) % d, keepSkip)) % MOD;
  }
  return res;
}

int main() {
  fill(&dp[0][0][0], &dp[0][0][0] + 10005 * 105 * 2, -1LL);
  cin >> k >> d;
  n = k.size();
  ll res = MOD - 1;
  int cur = k[0] - '0';
  for (int i = 0; i < cur; i++) {
    res = (res + solve(1, i % d, false)) % MOD;
  }
  res = (res + solve(1, cur % d, true)) % MOD;
  cout << res << '\n';
  return 0;
}
