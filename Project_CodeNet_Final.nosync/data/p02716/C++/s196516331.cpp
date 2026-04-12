#include <bits/stdc++.h>
using namespace std;

const long long INF = (long long) 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector< map<int, long long> > dp(n + 1);
  dp[1][1] = a[1];
  vector<long long> mx(n + 1, -INF);
  mx[0] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = i / 2; j <= (i + 1) / 2; j++) {
      dp[i][j] = mx[j - 1] + a[i];
    }
    for (auto& p : dp[i - 1]) {
      mx[p.first] = max(mx[p.first], p.second);
    }
  }
  for (auto& p : dp[n]) {
    mx[p.first] = max(mx[p.first], p.second);
  }
  cout << mx[n / 2] << '\n';
  return 0;
}