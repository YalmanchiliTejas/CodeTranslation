#include <bits/stdc++.h>
using namespace std;
string s;
int n, k, dp[200][5];

int ways(int n, int r) {
  if (n < r)  return 0;
  int ret = 1, m = 1;
  for (int i = 0; i < r; ++i) {
    ret *= n-i;
    ret /= i+1;
    m *= 9;
  }
  return ret * m;
}

int solve(int x, int rem) {
  if (rem == 0) return 1;
  if (x == n) return 0;
  int &ret = dp[x][rem];
  if (ret != -1)  return ret;
  ret = 0;

  int d = s[x] - '0';
  if (d) ret += ways(n-x-1, rem); 
  for (int i = 1; i < d; ++i)
    ret += ways(n-x-1, rem-1);
  if (d) ret += solve(x+1, rem-1);
  if (!d) ret += solve(x+1, rem);

  return ret;
}

int main() {

  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  memset(dp, -1, sizeof dp);

  cin >> s >> k;
  n = (int)s.size();
  cout << solve(0, k) << '\n';
}