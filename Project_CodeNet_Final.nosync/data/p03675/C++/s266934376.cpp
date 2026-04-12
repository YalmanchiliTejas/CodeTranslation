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
#define MOD 1000000007
#define INF (1LL<<30)
#define LLINF (1LL<<60)
#define PI 3.14159265359
#define EPS 1e-12
//#define int ll

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int a[200010];
signed main(void)
{
  int n;
  cin >> n;
  REP(i, n) cin >> a[i];

  deque<int> q;
  REP(i, n) {
    if(i % 2 == 0) q.PB(a[i]);
    else q.push_front(a[i]);
  }

  if(n%2) {
    for(int i=q.size()-1; i>=0; --i) {
      cout << q[i];
      if(i != 0) cout << " ";
    }
    cout << endl;
  } else {
    REP(i, q.size()) {
      cout << q[i];
      if(i != q.size()) cout << " ";
    }
    cout << endl;
  }

  return 0;
}
