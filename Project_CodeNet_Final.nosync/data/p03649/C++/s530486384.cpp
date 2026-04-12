#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
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
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
  ll n; cin >> n;
  vll a(n); REP(i, n) cin >> a[i];
  ll ans=0;
  while (true) {
    ll tmp = n-1, maxi=-1;
    REP(i, n) {
      if (a[i] > tmp) {
        tmp = a[i]; maxi = i;
      }
    }
    if (tmp == n-1) break;
    ll c = a[maxi] / n;
    REP(i, n) {
      if (i == maxi) a[i] -= c*n;
      else a[i] += c;
    }
    ans += c;
  }
  cout << ans << endl;
  return 0;
}
