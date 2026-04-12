#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long long ll;

#define INF 1000000009LL
#define MOD 1000000007LL

ll dp[3000][3000][2];//dp[i][j][k]:左i, 右j，　手番kのときのX - Yの最大値
int H, W;

int main() {
  int N; cin >> N;
  vector<ll> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];

  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j < N; j++) {
      if (j < i) {
        dp[i][j][0] = dp[i][j][1] = 0LL;
      } else if (i == j) {
        dp[i][j][0] = a[i];
        dp[i][j][1] = -a[i];
      } else {
        dp[i][j][0] = max(dp[i+1][j][1] + a[i], dp[i][j-1][1] + a[j]);
        dp[i][j][1] = min(dp[i+1][j][0] - a[i], dp[i][j-1][0] - a[j]);
      }
    }
  }

  cout << dp[0][N-1][0] << endl;
  return 0;
}