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

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

ll a[55], b[55];
signed main(void)
{
  ll n;
  cin >> n;
  REP(i, n) cin >> a[i];

  ll ret = 0;
  while(true) {
    ll tmp = 0;
    REP(i, n) {
      b[i] = 0;
      if(a[i] > 7*n) {
        b[i] = (a[i] - 6*n) / n;
        tmp += (a[i] - 6*n) / n;
        a[i] -= (a[i] - 6*n) / n * n;
      }
    }
    if(tmp == 0) break;
    REP(i, n) a[i] += tmp - b[i];
    ret += tmp;
  }

  while(true) {
    ll tmp = 0;
    REP(i, n) {
      b[i] = 0;
      if(a[i] >= n) {
        b[i] = (a[i]) / n;
        tmp += (a[i]) / n;
        a[i] -= (a[i]) / n * n;
      }
    }
    if(tmp == 0) break;
    REP(i, n) a[i] += tmp - b[i];
    ret += tmp;
  }
  // REP(i, n) cout << a[i] << " "; cout << endl;
  cout << ret << endl;

  return 0;
}
