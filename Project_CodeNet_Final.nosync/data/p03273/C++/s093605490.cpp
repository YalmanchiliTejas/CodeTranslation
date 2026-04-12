#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const int INF = 1000000005;
const long double EPS = 1e-10;

int main() {
  int h, w;
  cin >> h >> w;
  char a[h][w];
  rep(i, h) {
    rep(j, w) {
      cin >> a[i][j];
    }
  }

  vector<bool> l(h, false), r(w, false);
  rep(i, h) {
    rep(j, w) {
      if (a[i][j] == '#') {
        l[i] = true;
        r[j] = true;
      }
    }
  }

  rep(i, h) {
    if (!l[i]) continue;
    rep(j, w) {
      if (!r[j]) continue;
      cout << a[i][j];
    }
    cout << endl;
  }


  
  return 0;
}