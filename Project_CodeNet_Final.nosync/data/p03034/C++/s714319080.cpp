// 2020-07-17 00:56:53
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (ll i = (ll)(n); i < (ll)(m); i++)
#define REPC(i, n, m) for (ll i = (ll)(n); i <= (ll)(m); i++)
#define REPCM(i, n, m) for (ll i = (ll)(n); i >= (ll)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  ll n;
  cin >> n;
  vector<ll> s(n);
  rep(i, n) {
    cin >> s[i];
  }
  ll ans = 0;
  REP(i, 1, n/2) {
    ll cur = 0, c = i;
    vector<int> used(n, 0);
    for(ll k = 0; k*c < n-1; k++) {
      ll l = k*c, r = n-1-k*c;
      if(used[l] || used[r] || l == r || r < c) break;
      used[l] = used[r] = 1;
      cur += s[l] + s[r];
      chmax(ans, cur);
    }
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}