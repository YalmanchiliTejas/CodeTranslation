#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  int h, w;
  cin >> h >> w;
  vector<vector<bool>> a(h + 1, vector<bool>(w + 1, false));
  rep(i, h) {
    rep(j, w) {
      char c;
      cin >> c;
      if (c == '#') a[i][j] = true;
    }
  }

  int cnt = 0;
  rep(i, h) {
    rep(j, w) {
      cnt += a[i][j];
    }
  }
  if (cnt != h + w - 1) {
    cout << "Impossible\n";
    return 0;
  }
  int y = 0, x = 0;
  while (y != h - 1 || x != w - 1) {
    if (a[y + 1][x] ^ a[y][x + 1] == 0) {
      cout << "Impossible" << '\n';
      return 0;
    }
    if (a[y + 1][x]) y++;
    if (a[y][x + 1]) x++;
  }
  cout << "Possible" << '\n';
  

  






  
  return 0;
}