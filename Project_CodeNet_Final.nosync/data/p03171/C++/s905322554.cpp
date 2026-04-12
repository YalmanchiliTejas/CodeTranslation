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

ll solve(ll l, ll r, vector<ll>& a) {
  if (dp[l][r] != -INF) {
    return dp[l][r];
  }
  if (l == r) return dp[l][r] = a[l];
  return dp[l][r] = max(a[l] - solve(l + 1, r, a), a[r] - solve(l, r - 1, a));
}

int main() {
  ll N;
  cin >> N;
  vector<ll> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < N_MAX; i++) {
    for (int j = 0; j < N_MAX; j++) {
      dp[i][j] = -INF;
    }
  }
  ll ans = solve(0, N - 1, a);
  cout << ans << endl;
  return 0;
}