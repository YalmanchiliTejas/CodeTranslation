#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; cin >> n;
  vector<int> a(n * 3); REP(i, n * 3) cin >> a[i], --a[i];
  vector dp(n, vector(n, -INF));
  vector mx(n, -INF);
  dp[a[0]][a[1]] = dp[a[1]][a[0]] = 0;
  mx[a[0]] = mx[a[1]] = 0;
  int tmp = 0;
  for (int i = 2; i + 1 < n * 3; i += 3) {
    if (a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
      ++tmp;
      continue;
    }
    vector<pair<pair<int, int>, int>> nx;
    function<void(int, int, int)> emp = [&](int k1, int k2, int val) {
      nx.emplace_back(make_pair(k1, k2), val);
    };
    int max = *max_element(ALL(mx));
    emp(a[i], a[i + 1], max);
    emp(a[i + 1], a[i + 2], max);
    emp(a[i + 2], a[i], max);
    REP(j, n) {
      emp(a[i], a[i + 1], dp[a[i + 2]][a[i + 2]] + 1);
      emp(a[i + 1], a[i + 2], dp[a[i]][a[i]] + 1);
      emp(a[i + 2], a[i], dp[a[i + 1]][a[i + 1]] + 1);
    }
    REP(j, n) {
      emp(a[i], j, mx[j]);
      emp(a[i], j, dp[j][a[i + 1]] + (a[i + 1] == a[i + 2]));
      emp(a[i + 1], j, mx[j]);
      emp(a[i + 1], j, dp[j][a[i + 2]] + (a[i + 2] == a[i]));
      emp(a[i + 2], j, mx[j]);
      emp(a[i + 2], j, dp[j][a[i]] + (a[i] == a[i + 1]));
    }
    for (auto [pr, val] : nx) {
      auto [x, y] = pr;
      chmax(dp[x][y], val);
      chmax(dp[y][x], val);
      chmax(mx[x], val);
      chmax(mx[y], val);
    }
  }
  int ans = 0;
  REP(i, n) {
    chmax(ans, dp[i][i] + (i == a[n * 3 - 1]));
    FOR(j, i + 1, n) chmax(ans, dp[i][j]);
  }
  cout << ans + tmp << '\n';
  return 0;
}
