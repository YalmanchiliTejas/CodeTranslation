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
  ll n, x, m;
  cin >> n >> x >> m;
  vector<bool> used(m);
  ll ans = 0;
  while (!used[x]) {
    used[x] = true;
    ans += x;
    x = x*x%m;
    n--;
    if (!n) {
      cout << ans << endl;
      return 0;
    }
  }
  ll cnt = 1, sum = x, st = x;
  x = x*x%m;
  while (x != st) {
    sum += x;
    cnt++;
    x = x*x%m;
  }
  if (!x) {
    cout << ans << endl;
    return 0;
  }
  ans += n/cnt*sum;
  ll rem = n%cnt;
  rep(i, rem) {
    ans += x;
    x = x*x%m;
  }
  cout << ans << endl;
  return 0;
}