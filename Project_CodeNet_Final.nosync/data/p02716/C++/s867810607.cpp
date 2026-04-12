#include <iostream>
using namespace std;
using ll = long long;
constexpr ll INF = 1LL << 60;

ll n, k, c, a[200010], dp[100010][2];
string s;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i <= n / 2 + 1; ++i) {
    dp[i][0] = -INF;
    dp[i][1] = -INF;
  }

  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    int j = (i - 1) / 2;
    dp[j + 1][0] = max(dp[j + 1][0], dp[j + 1][1]);
    dp[j + 1][1] = dp[j][0] + a[i - 1];

    dp[j][0] = max(dp[j][0], dp[j][1]);
    dp[j][1] = dp[j - 1][0] + a[i - 1];
  }
  cout << max(dp[n / 2][0], dp[n / 2][1]);
  return 0;
}

