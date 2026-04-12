#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <deque>
#include <iterator>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

vll a(3000);
vvll dp(3000, vll(3000, 0));
V<V<bool> > flag(3000, V<bool>(3000, false));

ll f(ll l, ll r) {
  if (flag.at(l).at(r)) return dp.at(l).at(r);
  flag.at(l).at(r) = true;
  if (l == r) return dp.at(l).at(r) = a.at(l);
  return dp.at(l).at(r) = max(a.at(l)-f(l+1, r), a.at(r)-f(l, r-1));
}

int main() {
  ll n; cin >> n;
  REP(i, n) cin >> a.at(i);
  ll ans = f(0, n-1);
  cout << ans << endl;
  return 0;
}
