#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
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
#define ALL(v) v.begin(),v.end()
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

const ll MAX = 200005;
vll fac(MAX, 0), finv(MAX, 0), inv(MAX, 0);

void initCombTable() {
  fac.at(0) = 1; fac.at(1) = 1;
  finv.at(0) = 1; finv.at(1) = 1;
  inv.at(1) = 1;
  rep(i, 2, MAX) {
    fac.at(i) = fac.at(i-1) * i % MOD;
    inv.at(i) = MOD - inv.at(MOD%i) * (MOD / i) % MOD;
    finv.at(i) = finv.at(i-1) * inv.at(i) % MOD;
  }
}

ll nCk(ll n, ll k) {
  if (n < 0 || k < 0 || n < k) return 0;
  return fac.at(n) * (finv.at(k) * finv.at(n-k) % MOD) % MOD;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    initCombTable();
    ll n, m, k; cin >> n >> m >> k;
    ll ans = 0;
    rep(i, 1, n) {
        ll tmp = i*(((n-i)*m%MOD)*m%MOD)%MOD;
        tmp = (tmp * nCk(n*m-2, k-2)) % MOD;
        ans += tmp;
        if (ans >= MOD) ans -= MOD;
    }
    rep(i, 1, m) {
        ll tmp = i*(((m-i)*n%MOD)*n%MOD)%MOD;
        tmp = tmp*nCk(n*m-2, k-2)%MOD;
        ans += tmp;
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
    return 0;
}
