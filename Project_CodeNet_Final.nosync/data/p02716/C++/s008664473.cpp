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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vll a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (!(n & 1)) {  // n: even
        vll evena(n + 1, 0), odda(n + 1, 0);
        for (ll i = 0; i < n; i++) {
            evena[i + 1] = evena[i];
            odda[i + 1] = odda[i];
            if (i & 1) odda[i + 1] += a[i];
            else evena[i + 1] += a[i];
        }
        ll ans = odda.back();
        for (int i = 0; i < n; i += 2) {
            ll tmp = evena[i + 1] + (odda.back() - odda[i + 2]);
            chmax(ans, tmp);
        }
        cout << ans << '\n';
    } else {
        vvll dp(8, vll(n + 1, -HIGHINF));
        dp[2][0] = 0;
        for (ll i = 0; i < n; i++) {
            dp[1][i + 1] = dp[2][i] + a[i];
            dp[2][i + 1] = max(dp[0][i], dp[1][i]);
            dp[3][i + 1] = dp[4][i] + a[i];
            dp[4][i + 1] = max(dp[2][i], dp[3][i]);
            dp[5][i + 1] = dp[6][i] + a[i];
            dp[6][i + 1] = max(dp[4][i], dp[5][i]);
        }

        // for (int i = 0; i < 8; i++) DEBUG_VLL(dp[i])
        cout << max(dp[4][n], dp[5][n]) << '\n';
    }
    return 0;
}
