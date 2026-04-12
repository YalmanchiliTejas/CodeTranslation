#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using Pi = pair<int, int>;
using Tapris = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int a, b;
  cin >> a >> b;
  int d[11][11];
  reps(x, 1, a+1) reps(y, 1, b+1) cin >> d[x][y];

  int n[101][101] = {{}};
  rep(l, 101) rep(m, 101) {
    reps(x, 1, a+1) reps(y, 1, b+1) {
      chmax(n[l][m], d[x][y]-l*x-m*y);
    }
  }

  reps(x, 1, a+1) reps(y, 1, b+1) {
    int e = inf;
    rep(l, 101) rep(m, 101) chmin(e, l*x+m*y+n[l][m]);
    if(e != d[x][y]) {
      cout << "Impossible" << endl;
      return 0;
    }
  }

  cout << "Possible" << endl;
  cout << 202 << " " << 200+101*101 << endl;
  rep(i, 100) cout << i+1 << " " << i+2 << " " << 'X' << endl;
  rep(i, 100) cout << i+101+2 << " " << i+101+1 << " " <<  'Y' << endl;
  rep(l, 101) rep(m, 101) cout << l+1 << " " << m+101+1 << " " << n[l][m] << endl;
  cout << 1 << " " << 102 << endl;
  return 0;
}
