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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  while (true) {
    bool flag = true;
    rep(i, n) {
      if (a[i] > n-1) {
        rep(j, n) {
          if (j == i)
            continue;
          a[j] += a[i]/n;
        }
        ans += a[i]/n;
        a[i] %= n;
        flag = false;
      }
    }
    if (flag)
      break;
  }
  cout << ans << endl;
  return 0;
}