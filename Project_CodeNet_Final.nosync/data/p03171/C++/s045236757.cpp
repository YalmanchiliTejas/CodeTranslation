#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;
ll const N_MAX = 3010;
ll dp[N_MAX][N_MAX];

int main() {
  ll N;
  cin >> N;
  vector<ll> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < N_MAX; i++) {
    for (int j = 0; j < N_MAX; j++) {
      dp[i][j] = 0;
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    for (int j = i; j < N; j++) {
      if ((N - 1 - j - i) % 2 == 0) {
        dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j]);
      } else {
        dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j]);
      }
    }
  }
  ll ans = dp[0][N - 1];
  cout << ans << endl;
  return 0;
}