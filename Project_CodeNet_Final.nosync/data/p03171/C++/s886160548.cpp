#include <bits/stdc++.h>
using namespace std;
#define ffor(n) for(int i = 0; i < n; i++)
#define fffor(n) for(int j = 0; j < n; j++)
int INF = 1e9 + 7;

long long f(int l, int r, vector <int>& v, vector <vector <long long>>& dp) {
  if (dp[l][r] != -1) return dp[l][r];
  if (l == r) {
    dp[l][r] = v[l];
    return dp[l][r];
  }
  dp[l][r] = max(v[l] - f(l + 1, r, v, dp), v[r] - f(l, r - 1, v, dp));
  return dp[l][r];
}

int main(void) {
  int n;
  cin >> n;
  vector <int> v(n);
  ffor(n) cin >> v[i];
  vector <vector <long long>> dp(n, vector <long long>(n, -1)); // dp[l][r] contains max score over segment
  cout << f(0, n - 1, v, dp) << '\n';
}