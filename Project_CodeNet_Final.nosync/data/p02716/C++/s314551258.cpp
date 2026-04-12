#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <tuple>
#include <string>
#include <algorithm>
#include <functional> // greater など
#include <cmath>      // abs など
#include <numeric>    // accumulate, gcd など
#include <cassert>    // assert
#include <stdexcept>
#include <bitset>
using namespace std;

// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
// typedef int128_t ll;
// typedef cpp_int ll;

// GCC, 配列のアクセスなど
#define _GLIBCXX_DEBUG
// Clang, 配列のアクセスなど
#define _LIBCPP_DEBUG 0

//////////////// //////////////// //////////////// //////////////// ////////////////
//////////////// //////////////// //////////////// //////////////// ////////////////

// constexpr int max_n = 200'000 + 5;
constexpr ll INF = 1000'000'000'000'000LL;

int main()
{
    // 高速な入出力
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15); // 浮動小数の表示の精度

    int n; cin >> n;
    vector<ll> as(n);
    rep(i, n) {
        cin >> as[i];
    }

    // dp[i][j] = asの[0,i)から取る、j回「飛ばす」
    vector<vector<ll>> dp(n+1, vector<ll>(3));
    dp[0][1] = dp[0][2] = -INF;
    rep(i, n) {
        // dp[i+1]
        rep(j, 3) {
            // j を変えない場合 (飛ばさない場合)
            dp[i+1][j] = dp[i][j];
            if (i % 2 == j % 2) {
                dp[i+1][j] += as[i];
            }

            // jを増やす場合
            if (j == 0 || i % 2 != (j-1) % 2) { continue; }
            // j>=1 で j-1のときはiに置く ときしか考えない
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    ll res;
    if (n % 2 == 0) {
        res = max(dp[n][0], dp[n][1]);
    } else {
        res = max(dp[n][1], dp[n][2]);
    }

    cout << res << endl;

    return 0;
}
