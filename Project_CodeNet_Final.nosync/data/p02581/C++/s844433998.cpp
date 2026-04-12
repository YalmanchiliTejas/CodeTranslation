#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                             \
  cerr << __LINE__ << ": " << #x << " = {";          \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) { \
    cerr << ((hoge) ? "," : "") << x[hoge];          \
  }                                                  \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int A[3 * N];
  for (int i = 0; i < 3 * N; i++) cin >> A[i], A[i]--;
  const int INF = INT_MAX / 10;
  int dp[N][N];
  int dp_max[N];
  int dp_maxx = 0;
  for (int i = 0; i < N; i++) fill(dp[i], dp[i] + N, -INF);
  fill(dp_max, dp_max + N, -INF);
  dp[A[0]][A[1]] = 0;
  dp[A[1]][A[0]] = 0;
  dp_max[A[0]] = 0;
  dp_max[A[1]] = 0;
  int ans = 0;
  for (int i = 1; i < N; i++) {
    int a = A[3 * i - 1], b = A[3 * i], c = A[3 * i + 1];
    if (a == b && b == c) {
      ans++;
      continue;
    }
    vector<tuple<int, int, int>> upd;
    for (int _ = 0; _ < 3; _++) {
      int tmp = a;
      a = b;
      b = c;
      c = tmp;
      if (a == b) {
        for (int k = 0; k < N; k++) {
          upd.emplace_back(c, k, dp[a][k] + 1);
        }
      }
    }
    for (int _ = 0; _ < 3; _++) {
      int tmp = a;
      a = b;
      b = c;
      c = tmp;
      for (int k = 0; k < N; k++) {
        upd.emplace_back(a, k, dp_max[k]);
      }
    }
    for (int _ = 0; _ < 3; _++) {
      int tmp = a;
      a = b;
      b = c;
      c = tmp;
      upd.emplace_back(b, c, dp_maxx);
    }
    for (int _ = 0; _ < 3; _++) {
      int tmp = a;
      a = b;
      b = c;
      c = tmp;
      upd.emplace_back(b, c, dp[a][a] + 1);
    }
    for (auto tmp : upd) {
      int x, y, val;
      tie(x, y, val) = tmp;
      dp[x][y] = dp[y][x] = max(dp[x][y], val);
      dp_max[x] = max(dp_max[x], dp[x][y]);
      dp_max[y] = max(dp_max[y], dp[x][y]);
      dp_maxx = max(dp_maxx, dp[x][y]);
    }
  }
  int mx = 0;
  for (int k = 0; k < N; k++) {
    for (int l = 0; l < N; l++) {
      int tmp = dp[k][l];
      if (k == l && l == A[3 * N - 1]) tmp++;
      mx = max(mx, tmp);
    }
  }
  ans += mx;
  cout << ans << endl;
  return 0;
}
