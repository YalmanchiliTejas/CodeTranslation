#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <memory>
#include <string>
#include <cstdlib>
#include <set>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <regex>
#include <cmath>
#include <map>
#include <iterator>
#include <climits>
#include <numeric>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <array>
#include <valarray>
#include <complex>
#include <random>
#include <functional>
#include <cassert>
#include <chrono>
#include <memory>

using namespace std;

#define int long long
//region TEMPLATE
////@formatter:off
#define double long double
typedef long long ll;
typedef unsigned long long ull;
template<typename T>void __read(T &a) { cin >> a; }
template<typename T, typename ... Args> void __read(T &a, Args &... args) { cin >> a;__read(args...);}
#define make(t, ...) t __VA_ARGS__; __read(__VA_ARGS__)
#define makev(a, n) VI a(n); FOR(n) cin >> a[i];
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define FORIT(p) for(auto it = p.begin(); it != p.end(); it++)
#define FOR(b) for(signed i = 0; i <(b); i++)
#define FORE(i, l, r) for(int i = (l); i < (r); i++)
#define NFOR(i, n) for(int i = (((int) n)-1); i >= 0; i--)
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef pair<int, int> PII;
typedef pair<pair<int, int>, int> PPII;
constexpr ll M7 = 1000000007ll;
constexpr ll M9 = 1000000009ll;
constexpr ll MFFT = 998244353ll;
template<class T> void outv(T &a) { for (auto &x : a) cout << x << ' '; }
static mt19937 rnd(static_cast<unsigned>(chrono::steady_clock::now().time_since_epoch().count())); // NOLINT(cert-err58-cpp)
auto __fast_io__ = (ios_base::sync_with_stdio(false), cin.tie(nullptr)); // NOLINT(cert-err58-cpp,cppcoreguidelines-interfaces-global-init)
////@formatter:on
//endregion



int32_t main() {
    make(int, n);
    makev(a, n);
    VVI dp(n, VI(4, LLONG_MIN / 2));
    dp[0][0] = a[0];
    dp[1][0] = a[1];
    if (n % 2 == 1){
        dp[2][1] = a[2];
    }
    for(int i = 2; i < n; ++i){
        for(int j = 0; j < dp[i].size(); ++j){
            dp[i][j] = max(dp[i][j], dp[i - 2][j] + a[i]);
        }
        if (i >= 3) {
            dp[i][1] = max(dp[i][1], dp[i - 3][0] + a[i]);
            dp[i][2] = max(dp[i][2], dp[i - 3][1] + a[i]);
        }
        if (n % 2 == 1 && i >= 4){
            dp[i][3] = max(dp[i][3], dp[i - 4][0] + a[i]);
        }
    }
    if (n % 2 == 0){
        cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 2][0]});
    } else {
        cout << max({dp[n - 1][1], dp[n - 1][2], dp[n - 1][3], dp[n - 2][1], dp[n - 2][0], dp[n - 3][0]});
    }


    return 0;
}