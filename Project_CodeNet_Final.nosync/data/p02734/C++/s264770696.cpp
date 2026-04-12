#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <complex>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <bitset>
#include <cstdint>
#include <cassert>
#include <random>
#include <iterator>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;

int main() {
    const i64 mod = 998244353;
    i64 n, s;
    cin >> n >> s;
    vector<i64> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<i64> dp(s + 1);
    i64 ans = 0, i = 1;
    for (i64 x : a) {
        for (i64 i = s - x; i > 0; --i) {
            dp[i + x] += dp[i];
            dp[i + x] %= mod;
        }
        if (x <= s) {
            dp[x] += i;
            dp[x] %= mod;
        }
        ans += dp[s];
        ans %= mod;
        ++i;
    }
    cout << ans << endl;
    return 0;
}