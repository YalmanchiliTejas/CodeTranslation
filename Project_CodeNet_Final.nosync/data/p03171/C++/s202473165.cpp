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

V<V<bool> > flag;
vvll dp;
vll a;

ll f(ll l, ll r) {
    if (flag[l][r]) return dp[l][r];
    flag[l][r] = true;
    if (l==r) return dp[l][r] = a[l];
    else return dp[l][r] = max(a[l]-f(l+1, r), a[r]-f(l, r-1));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    a.resize(n); REP(i, n) cin >> a[i];
    flag.resize(n, V<bool>(n, false));
    dp.resize(n, vll(n, 0));
    ll ans = f(0, n-1);
    cout << ans << '\n';
    return 0;
}
