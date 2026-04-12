#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> s(n+1, 1);
  vector<ll> p(n+1, 1);
  ll ans = 0;
  rep(i, n) {
    s[i+1] = 2 * s[i] + 3;
    p[i+1] = 2 * p[i] + 1;
  }
  repr(i, n) {
    if (x < s[i]) {
      x--;
      continue;
    }
    ans += p[i];
    x -= s[i];
    if (x) {
      ans++;
      x--;
    }
    i++;
  }
  cout << ans << endl;
}