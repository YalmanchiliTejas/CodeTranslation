#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 2e5 + 5;

ll dp[N][2] = {};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  vector < int > a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  dp[1][0] = 0;
  dp[1][1] = a[1];
  if (n % 2) {
    for (int i = 2; i <= n; i++) {
      if (i % 2) {
        dp[i][0] = max (dp[i - 2][0] + a[i], dp[i - 1][1]);
        dp[i][1] = a[i] + dp[i - 2][1];
      } else {
        dp[i][0] = max (dp[i - 2][0] + a[i], dp[i - 1][0]);
        dp[i][1] = max (dp[i - 2][1] + a[i], dp[i - 1][1]);
      }
    }
  } else {
    for (int i = 1; i <= n; i++) {
      if (i % 2) {
        dp[i][0] = max (dp[i - 2][0] + a[i], dp[i - 1][1]);
        dp[i][1] = a[i] + dp[i - 2][1];
      } else {
        dp[i][0] = max (a[i] + dp[i - 2][0], dp[i - 1][1]);
        dp[i][1] = max (a[i] + dp[i - 2][0], dp[i - 1][1]);
      }
    }
  }

  cout << dp[n][0] << '\n';
}
