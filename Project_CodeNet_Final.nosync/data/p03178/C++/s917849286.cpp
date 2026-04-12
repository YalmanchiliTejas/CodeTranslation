#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string num;
int k[10005];
int d;
ll dp[10005][105][2];
ll MOD = 1e9 + 7;
ll solve(int pos, int sum, int f) {
  if (dp[pos][sum][f] != -1)
    return dp[pos][sum][f];
  if (pos == num.size())
    return dp[pos][sum][f] = (sum == 0);
  ll nsum = 0, up = (f ? k[pos] : 9);
  for (int i = 0; i <= up; i++) {
    nsum += solve(pos + 1, (sum + i) % d, f && (i == up));
    nsum %= MOD;
  }
  return dp[pos][sum][f] = nsum;
}
int main() {
  cin >> num >> d;
  for (int i = 0; i < num.size(); i++) {
    k[i] = num[i] - '0';
  }
  memset(dp, -1, sizeof dp);
  cout << (solve(0, 0, 1) - 1 + MOD) % MOD << endl;
}