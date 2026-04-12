#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

const ll mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  V<ll> a(n);
  rep(i, n) cin >> a[i];

  ll sum = 0;
  rep(i, n) sum += a[i];

  V<ll> s(n);
  rep(i, n) {
    sum -= a[i];
    s[i] = sum;
  }

  ll ans = 0;
  rep(i, n) {
    ll wa = s[i] % mod;
    ll se = wa * a[i] % mod;
    ans += se;
    ans %= mod;
  }
  cout << ans << endl;
}
