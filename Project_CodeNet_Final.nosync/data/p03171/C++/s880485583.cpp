#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e12;

int main() {
  int n;
  cin >> n;
  vector<vector<long long>> dp(n, vector<long long> (n));
  vector<int> v(n);
  for (int &x : v)
    cin >> x;
  for (int i=0; i<n; ++i)
    dp[i][i] = v[i];
  for (int l=n-1; l>=0; --l)
    for (int r=l+1; r<n; ++r)
      dp[l][r] = max(v[l]-dp[l+1][r], v[r]-dp[l][r-1]);
  cout << dp[0][n-1] << '\n';
  return 0;
}
