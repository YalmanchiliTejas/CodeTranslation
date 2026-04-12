#include<bits/stdc++.h>
using namespace std;
int main () {
  const int INF = 1e15;
  int N;
  cin >> N;
  vector<long long>que(N);
  for (int i = 0; i < N; i ++) cin >> que[i];
  long long dp[3030][3030];
  for (int n = 0; n <= N; n ++) {
    for (int l = 0; l <= N - n; l ++) {
      int r = l + n;
      int tore = (N - n + 1) % 2;
      if (!n) {
        dp[l][r] = 0;
        continue;
      }
      if (tore) {
        dp[l][r] = max(dp[l + 1][r] + que[l],
                       dp[l][r - 1] + que[r - 1]);
      }
      else {
        dp[l][r] = min(dp[l + 1][r] - que[l],
                       dp[l][r - 1] - que[r - 1]);
      }
    }
  }
  cout << dp[0][N] << endl;
}
