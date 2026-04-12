#include <bits/stdc++.h>
using namespace std;
#define SZ(a) ((int)(a).size())
typedef long long int64;
int dp[2222][2222];
int Max[2222], A[6666];
int main() {
#ifdef LOCAL
  freopen(".a.in", "r", stdin);
#endif
  ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < 3 * n; ++i) cin >> A[i], A[i]--;
  for (int i = 0; i < 2222; ++i)
    for (int j = 0; j < 2222; ++j) dp[i][j] = -1e9;
  for (int i = 0; i < 2222; ++i) Max[i] = -1e9;
  dp[A[0]][A[1]] = dp[A[1]][A[0]] = 0;
  Max[A[0]] = Max[A[1]] = 0;
  int tot = 0;
  struct P {
    int x, y, v;
    P(int a = 0, int b = 0, int c = 0) : x(a), y(b), v(c) {}
  };
  for (int i = 2; i + 2 < n * 3; i += 3) {
    if (A[i] == A[i + 1] && A[i + 1] == A[i + 2]) {
      tot++;
      continue;
    }
    vector<P> upd;
    int cMax = -1e9;
    for (int j = 0; j < n; ++j) cMax = max(cMax, Max[j]);
    upd.emplace_back(A[i], A[i + 1], cMax);
    upd.emplace_back(A[i], A[i + 2], cMax);
    upd.emplace_back(A[i + 2], A[i + 1], cMax);
    for (int j = 0; j < n; ++j) upd.emplace_back(A[i], j, Max[j]);
    for (int j = 0; j < n; ++j) upd.emplace_back(A[i + 1], j, Max[j]);
    for (int j = 0; j < n; ++j) upd.emplace_back(A[i + 2], j, Max[j]);
    upd.emplace_back(A[i + 1], A[i + 2], dp[A[i]][A[i]] + 1);
    upd.emplace_back(A[i], A[i + 2], dp[A[i + 1]][A[i + 1]] + 1);
    upd.emplace_back(A[i + 1], A[i], dp[A[i + 2]][A[i + 2]] + 1);
    if (A[i] == A[i + 1] || A[i] == A[i + 2] || A[i + 1] == A[i + 2]) {
      if (A[i] == A[i + 2])
        swap(A[i + 1], A[i + 2]);
      else if (A[i + 1] == A[i + 2])
        swap(A[i], A[i + 2]);
      assert(A[i] == A[i + 1]);
      for (int j = 0; j < n; ++j) upd.emplace_back(j, A[i + 2], dp[A[i]][j] + 1);
    }
    for (auto j : upd) {
      dp[j.x][j.y] = max(dp[j.x][j.y], j.v);
      dp[j.y][j.x] = max(dp[j.y][j.x], j.v);
      Max[j.y] = max(Max[j.y], j.v);
      Max[j.x] = max(Max[j.x], j.v);
    }
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j && i == A[3 * n - 1])
        res = max(res, dp[i][j] + 1);
      else
        res = max(res, dp[i][j]);
    }
  }
  cout << res+tot;
  return 0;
}
//2020.08.22 23:18:22
