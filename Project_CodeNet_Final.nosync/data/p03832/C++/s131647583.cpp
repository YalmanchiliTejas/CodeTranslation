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

const long long MOD = 1000000007;
const long long HIGHINF = (long long)1e18;
const int INF = (int)1e9;

ll modpow(ll m, ll p) {
    if (p == 0) return 1;
    ll tmp = modpow(m, p / 2);
    if (p & 1) return (tmp * tmp % MOD) * m % MOD;
    else return tmp * tmp % MOD;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, a, b, c, d; cin >> n >> a >> b >> c >> d;

    vll fac(n + 1, 1), invfac(n + 1, 1);
    for (ll i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        invfac[i] = invfac[i - 1] * modpow(i, MOD - 2) % MOD;
    }

    // dp[i][j]: i 人以下のグループだけで j 人使う時の分け方
    vvll dp(b + 1, vll(n + 1, 0));
    dp[0][0] = 1;
    // i 人グループを g 個追加
    // 遷移: dp[i][j + i * g] = dp[i - 1][j] * {n-j}_C_{i * g} * (i * g)! / (i!) ^ g / g!
    for (ll i = 1; i <= b; i++) {
        if (i < a) {
            dp[i] = dp[i - 1];
            continue;
        }
        for (ll j = 0; j <= n; j++) {
            (dp[i][j] += dp[i - 1][j]) %= MOD;
            for (ll g = c; g <= d; g++) {
                if (j + i * g > n) break;
                ll tmp = dp[i - 1][j] * (fac[n - j] * (invfac[i * g] * invfac[n - j - i * g] % MOD) % MOD) % MOD;
                (tmp *= fac[i * g]) %= MOD;
                (tmp *= modpow(modpow(fac[i], g), MOD - 2)) %= MOD;
                (tmp *= invfac[g]) %= MOD;
                (dp[i][j + i * g] += tmp) %= MOD;
            }
        }
    }
    // for (ll i = 0; i <= b; i++) DEBUG_VLL(dp[i])
    cout << dp[b][n] << '\n';
    return 0;
}
