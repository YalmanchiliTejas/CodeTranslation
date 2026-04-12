#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int MAX = 200010;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = INF;
  rep(i, MAX) {
    int sum = c*i;
    sum += max(x-i/2, 0)*a;
    sum += max(y-i/2, 0)*b;
    chmin(ans, sum);
  }
  cout << ans << endl;
  return 0;
}