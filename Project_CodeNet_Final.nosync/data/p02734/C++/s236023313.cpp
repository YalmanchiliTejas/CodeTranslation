#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <bitset>
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
#include <functional>
#include <cassert>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) REP(sz, vec.size()) std::cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const long long MOD = 998244353;
const long long HIGHINF = (long long)1e18;
const int INF = (int)1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, s; cin >> n >> s;
    vll a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    vvll dp(n + 1, vll(s + 1, 0));
    dp[0][0] = 1;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j <= s; j++) {
            (dp[i + 1][j] += dp[i][j]) %= MOD;
            if (j + a[i] <= s) {
                if (j == 0) {
                    if (a[i] == s) (dp[i + 1][s] += (i + 1) * (n - i) % MOD) %= MOD;
                    else (dp[i + 1][a[i]] += i + 1) %= MOD;
                } else if (j + a[i] == s) (dp[i + 1][s] += (dp[i][j] * (n - i) % MOD)) %= MOD;
                else (dp[i + 1][j + a[i]] += dp[i][j]) %= MOD;
            }
        }
    }

    // for (ll i = 1; i <= n; i++) DEBUG_VLL(dp[i])
    cout << dp[n][s] << '\n';
    return 0;
}
