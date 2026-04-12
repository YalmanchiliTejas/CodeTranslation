#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int INF = 1 << 27;
const ll LLINF = (ll)1 << 60;
const ll MOD = 1e9+7;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  vector<ll> sum(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i-1] + a[i-1];
  }

  vector<ll> dp(n + 1, 0);
  for (int len = 1; len <= n; len++) {
    for (int i = 0; i <= n; i++) {
      int j = i + len;
      if (j > n) {
        dp[i] = 0;
      } else {
        dp[i] = max(
          a[i] + sum[j] - sum[i+1] - dp[i+1],
          a[j - 1] + sum[j-1] - sum[i] - dp[i]);
      }
    }
  }

  printf("%lld\n", 2 * dp[0] - sum[n]);
}
