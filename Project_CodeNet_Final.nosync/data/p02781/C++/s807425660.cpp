#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

typedef int64_t ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);

int dp[105][4][2];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  int n = s.size();
  int K;
  cin >> K;

  dp[0][0][0] = 1;

  rep(i, n) rep(j, 4) rep(k, 2) {
    int nd = s[i] - '0';  // Nの桁
    rep(d, 10) {          // 候補の桁
      int ni = i + 1, nj = j, nk = k;
      if (d != 0) nj++;   // 非ゼロを追加するなら j を加算
      if (nj > K) continue;  // 非ゼロをもう使えないなら skip
      if (k == 0) {
        if (d > nd) continue;  // Nよりも大きくなったら skip
        if (d < nd) nk = 1;    // N 以下であることが確定
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }

  int ans = dp[n][K][0] + dp[n][K][1];

  cout << ans << endl;

  return 0;
}
