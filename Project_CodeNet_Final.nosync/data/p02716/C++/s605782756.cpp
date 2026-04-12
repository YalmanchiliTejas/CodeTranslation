#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 2 * 100000 + 5;
typedef long long ll;

const ll NEG_INF = ll(-1e17);

ll dp[maxn][2], arr[maxn];
int n;

inline int cal(int i, int j) {
  return ((i + 1) >> 1) - j;
}

inline bool check(int i, int j, int need) {
  return need == cal(i, j);
}

ll solve() {
  dp[1][0] = arr[1];
  dp[1][1] = 0LL;
  dp[2][0] = arr[2];
  dp[2][1] = 0LL;
  int bd = min(n, 5);
  for (int i = 3; i <= bd; i++) {
    if (i == 3) {
      dp[3][0] = arr[1] + arr[3];
      dp[3][1] = arr[3];
    }
    else if (i == 4) {
      dp[4][0] = arr[4] + max(dp[2][0], dp[1][0]);
      dp[4][1] = arr[4];
    }
    else if (i == 5) {
      dp[5][0] = arr[5] + arr[3] + arr[1];
      dp[5][1] = arr[5] + max(arr[1], max(arr[2], arr[3]));
    }
  }
  for (int i = 6; i <= n; i++) {
    dp[i][0] = dp[i][1] = arr[i];
    
    int need = cal(i, 0) - 1;
    ll buf = NEG_INF;
    for (int j = i - 4; j <= i - 2; j++)
      for (int k = 0; k <= 1; k++)
        if (check(j, k, need))
          buf = max(buf, dp[j][k]);
    dp[i][0] += buf;
    
    need = cal(i, 1) - 1;
    buf = NEG_INF;
    for (int j = i - 4; j <= i - 2; j++)
      for (int k = 0; k <= 1; k++)
        if (check(j, k, need))
          buf = max(buf, dp[j][k]);
    dp[i][1] += buf;
  }
  ll ans = NEG_INF;
  int need = (n >> 1);
  for (int i = n; (i > 0) && (i > (n - 4)); --i)
    for (int j = 0; j <= 1; j++)
      if (check(i, j, need))
        ans = max(ans, dp[i][j]);
  return ans;
}

int main() {
  //freopen("input.txt", "r", stdin);
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
    printf("%lld\n", solve());
  }
  return 0;
}
