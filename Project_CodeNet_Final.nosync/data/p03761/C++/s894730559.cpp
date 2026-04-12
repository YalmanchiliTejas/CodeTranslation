#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
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
  vll c(26, HIGHINF);
  REP(_, n) {
    string s; cin >> s;
    vll tmp(26, 0);
    REP(i, s.size()) tmp[s[i] - 'a']++;
    REP(i, 26) chmin(c[i], tmp[i]);
  }
  REP(i, 26) {
    REP(j, c[i]) {
      cout << (char)('a' + i);
    }
  }
  cout << endl;
  return 0;
}
