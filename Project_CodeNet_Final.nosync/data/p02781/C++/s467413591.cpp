#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const int inf = 2e9;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
  string n;
  cin >> n;
  int k;
  cin >> k;

  int m = n.size();
  if (m < k) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 0;
  if (k == 1) {
    ans += (m - 1) * 9;
    ans += n[0] - '0';
  }
  else if (k == 2) {
    ans += (m - 1) * (m - 2) / 2 * 9 * 9;
    ans += (n[0] - '1') * (m - 1) * 9;
    int idx = 1;
    while (idx < m && n[idx] == '0') idx++;
    if (idx < m) ans += (m - 1 - idx) * 9 + (n[idx] - '0');
  }
  else {
    ans += (m - 1) * (m - 2) * (m - 3) / 6 * 9 * 9 * 9;
    ans += (n[0] - '1') * (m - 1) * (m - 2) / 2 * 9 * 9;
    int idx = 1;
    while (idx < m && n[idx] == '0') idx++;
    if (idx < m - 1) {
      ans += (m - 1 - idx) * (m - 2 - idx) / 2 * 9 * 9 + (n[idx] - '1') * (m - 1 - idx) * 9;
      idx++;
      while (idx < m && n[idx] == '0') idx++;
      if (idx < m) {
        ans += (m - 1 - idx) * 9 + (n[idx] - '0');
      }
    }
  }
  cout << ans << endl;





  
  return 0;
}