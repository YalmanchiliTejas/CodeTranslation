#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
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
  vector<int> s(n);
  rep(i, n) cin >> s[i];
  ll ans = 0;
  for (int c = 1; c < n-1; c++) {
    ll sum = 0;
    set<int> used;
    for (int i = 0; c*i < n-1; i++) {
      int a = n-1-c*i;
      int b = a-c;
      if (!(a > b && a < n && b > 0))
        break;
      if (used.find(c*i) != used.end() || used.find(n-1-c*i) != used.end() || c*i == n-1-c*i)
        break;
      sum += s[c*i];
      sum += s[n-1-c*i];
      used.insert(c*i);
      used.insert(n-1-c*i);
      chmax(ans, sum);
    }
  }
  cout << ans << endl;
  return 0;
}