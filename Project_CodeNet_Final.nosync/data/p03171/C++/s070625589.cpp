

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
#define SortAsc(c) std::sort(c.begin(), c.end())
#define SortDesc(c) std::sort(c.rbegin(), c.rend())
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int main() {
  int N;
  cin >> N;
  vector<ll> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
  for (int i = 0; i <= N; i++) {
    dp[i][i] = 0;
  }

  for (int len = 1; len <= N; len++) {
    for (int i = 0; i + len <= N; i++) {
      int j = i + len;

      if ((N - len) % 2 == 0) {
        dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
      } else {
        dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
      }
    }
  }

  cout << dp[0][N] << endl;
}