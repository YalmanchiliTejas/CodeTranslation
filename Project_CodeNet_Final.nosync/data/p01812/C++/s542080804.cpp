//#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
// #define int ll
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
#ifdef int
const ll INF = (1LL<<60);
#else
const int INF = (1LL<<30);
#endif
const double PI = 3.14159265359;
const double EPS = 1e-12;
const int MOD = 1000000007;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int d[20], v[105][105], ord[105], D[1LL<<17];
signed main(void)
{
  int n, m, k;
  cin >> n >> m >> k;
  REP(i, m) cin >> d[i], d[i]--;
  REP(i, n) REP(j, k) {
    cin >> v[i][j], v[i][j]--;
  }

  REP(i, n) ord[i] = INF;
  REP(i, m) ord[d[i]] = i;

  REP(i, 1LL<<m) D[i] = INF;
  D[(1LL<<m)-1] = 0;
  queue<int> que;
  que.push((1LL<<m)-1);
  while(que.size()) {
    int t = que.front(); que.pop();
    // cout << t << endl;
    // ???i??§????§?
    REP(i, k) {
      int nxt = 0;
      // j?????????1???????¬????????§???????bit????????????
      REP(j, m) {
        if(t & (1<<j)) {
          // ????§??????????????????¨?±?
          if(ord[v[d[j]][i]] == INF) continue;
          nxt |= (1LL << ord[v[d[j]][i]]);
        }
      }
      // cout << "i:" << i << " " << nxt << " " << D[nxt] << " " << D[t] << endl;
      if(D[nxt] > D[t] + 1) {
        D[nxt] = D[t] + 1;
        que.push(nxt);
        if(nxt == 0) {
          cout << D[0] << endl;
          return 0;
        }
      }
    }
  }

  assert(false);
  return 0;
}