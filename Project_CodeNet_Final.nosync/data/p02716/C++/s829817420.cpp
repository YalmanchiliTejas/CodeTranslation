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
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) for(int sz=0;sz<int(vec.size());sz++) std::cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const long long MOD = 1000000007;
const long long HIGHINF = (long long)1e18;
const int INF = (int)1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vvll dp(6, vll(n + 1, -HIGHINF));
    dp[1][0] = 0;
    for (int i = 0; i < n; i++) {
        dp[0][i + 1] = dp[1][i] + a[i];
        dp[1][i + 1] = dp[0][i];
        dp[2][i + 1] = dp[3][i] + a[i];
        dp[3][i + 1] = max(dp[1][i], dp[2][i]);
        dp[4][i + 1] = dp[5][i] + a[i];
        dp[5][i + 1] = max(dp[3][i], dp[4][i]);
    }

    if (n & 1) cout << max(dp[3][n], dp[4][n]) << '\n';
    else cout << max(dp[1][n], dp[2][n]) << '\n';
    return 0;
}
