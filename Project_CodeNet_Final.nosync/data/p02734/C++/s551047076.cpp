#line 2 "../../library/template.hpp"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
#define rep(i, n) for(ll i = 0; i < (ll)n; i++)
#define rep3(i, l, r) for(ll i = l; i < (ll)r; i++)
#define per(i, n) for(ll i = n-1; i >= 0; i--)
#define per3(i, l, r) for(ll i = r-1; i >= (ll)l; i--)
#define all(v) begin(v), end(v)
template<class T, class U>
inline void cmax(T& a, U b) { if (a < b) a = b; }
template<class T, class U>
inline void cmin(T& a, U b) { if (a > b) a = b; }

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(15);
  }
} io_setup;

constexpr char el = '\n';
#line 2 "f2.cpp"

constexpr ll mod = 998244353;

int main() {
  ll n, s;
  cin >> n >> s;
  vl a(n);
  rep(i, n) {
    cin >> a[i];
  }

  ll ans = 0;
  vl dp(s+1);
  vl next(s+1);

  rep(i, n) {
    dp[0]++;
    dp[0] %= mod;
    next.assign(s+1, 0);

    rep(j, s+1) {
      next[j] += dp[j];
      next[j] %= mod;
      if (j+a[i] <= s) {
        next[j+a[i]] += dp[j];
        next[j+a[i]] %= mod;
      }
    }

    copy(all(next), dp.begin());
    ans += dp[s];
    ans %= mod;
  }
  cout << ans << endl;
}
