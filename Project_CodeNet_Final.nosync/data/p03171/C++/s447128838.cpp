#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3e3 + 7;

long long dp[MAXN][MAXN][2], a[MAXN], n;

long long solve(int l, int r, int p) {
  if(l == r) return a[l];
  long long &ans = dp[l][r][p];
  if (~ans) return ans;
  ans = max(a[l] - solve(l + 1, r, !p), a[r] - solve(l, r - 1, !p));
  return ans;
}

int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << solve(0, n-1, 0);
  return 0;
}