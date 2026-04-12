#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
  ll n; cin >> n;
  vll s(n); REP(i, n) cin >> s.at(i);
  ll res = 0;
  rep(p, 1, n) {
    if ((n-1) % p == 0) {
      ll tmp = 0, cur = 0;
      ll i = 0, j = n-1;
      for (; i<j; i+=p, j-=p) {
        cur += s.at(i) + s.at(j);
        tmp = max(tmp, cur);
      }
      res = max(res, tmp);
    } else {
      ll tmp = 0, cur = 0;
      ll i = 0, j = n-1;
      for (; i<n-1&&j>p; i+=p, j-=p) {
        cur += s.at(i) + s.at(j);
        tmp = max(tmp, cur);
      }
      res = max(res, tmp);
    }
  }
  cout << res << endl;
  return 0;
}
