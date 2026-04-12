#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXN = 3009;

pair<ll, ll> dp[MAXN][MAXN];

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j + i - 1 < n; j++) {
      int l = j, r = j + i - 1, turn = (n - i) % 2;
      if (turn == 0) { 
        if (i == 1) {
          dp[l][r].first = a[l];
        } else if (a[l] + dp[l + 1][r].first - dp[l + 1][r].second > a[r] + dp[l][r - 1].first - dp[l][r - 1].second) {
          dp[l][r].first = a[l] + dp[l + 1][r].first;
          dp[l][r].second = dp[l + 1][r].second;
        } else {
          dp[l][r].first = a[r] + dp[l][r - 1].first;
          dp[l][r].second = dp[l][r - 1].second;
        }
      } else {
        if (i == 1) {
          dp[l][r].second = a[l];
        } else if (dp[l + 1][r].first - dp[l + 1][r].second - a[l] < dp[l][r - 1].first - dp[l][r - 1].second - a[r]) {
          dp[l][r].first = dp[l + 1][r].first;
          dp[l][r].second = a[l] + dp[l + 1][r].second;
        } else {
          dp[l][r].first = dp[l][r - 1].first;
          dp[l][r].second = a[r] + dp[l][r - 1].second;
        }
      }
    }
  }
  cout << dp[0][n-1].first - dp[0][n-1].second << endl;
  return 0;
}
