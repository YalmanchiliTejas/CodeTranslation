//#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define IN(a, b, x) (a<=x&&x<b)
#define MP make_pair
#define PB push_back
#define INF (1LL<<30)
#define LLINF (1LL<<60)
#define PI 3.14159265359
#define EPS 1e-12
//#define int ll

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int a[205][205], dp[205][205][205];
int h, w;

int func(int sx, int sy, int ex, int ey) {
  if(sx >= w || ex >= w || sy >= h || ey >= h) return -INF;
  if(dp[sx][sy][ex] != -1) return dp[sx][sy][ex];
  int res = 0;
  res = max(res, func(sx, sy+1, ex+1, ey));
  res = max(res, func(sx, sy+1, ex, ey+1));
  res = max(res, func(sx+1, sy, ex+1, ey));
  res = max(res, func(sx+1, sy, ex, ey+1));
  if(sx == ex && sy == ey) res += a[sy][sx];
  else res += a[sy][sx] + a[ey][ex];

  // cout << sx << " " << sy << " " << ex << " " << ey << endl;
  // cout << res << endl;
  return dp[sx][sy][ex] = res;
}

signed main(void)
{
  cin >> h >> w;
  REP(i, h) REP(j, w) cin >> a[i][j];
  REP(i, 205) REP(j, 205) REP(k, 205) dp[i][j][k] = -1;

  cout << func(0, 0, 0, 0) << endl;

  return 0;
}
