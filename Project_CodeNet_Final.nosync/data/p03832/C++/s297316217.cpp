#include <iostream>
#include <utility>
#include <tuple>
#include <string>
#include <cstdint>
#include <vector>
#include <array>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;
using i64 = int64_t;
const i64 mod = 1e9 + 7;
i64 fact_memo[10000];
i64 fact(i64 x) {
    if (fact_memo[x] > 0) return fact_memo[x];
    return fact_memo[x] = x > 0 ? x * fact(x - 1) % mod : 1;
}
i64 powi(i64 x, i64 k) {
    i64 y = 1, z = x;
    while (k > 0) {
        if (k & 1) y = y * z % mod;
        k >>= 1;
        z = z * z % mod;
    }
    return y;
}
i64 inv(i64 x) {
    return powi(x, mod - 2);
}
i64 perm(i64 a, i64 b) {
    return fact(a) * inv(fact(a - b)) % mod; 
}
i64 conb(i64 a, i64 b) {
    return perm(a, b) * inv(fact(b)) % mod;
}
i64 n, a, b, c, d;
int main() {
    cin >> n >> a >> b >> c >> d;
    vector<i64> dp(n + 1);
    dp[0] = 1;
    for (i64 i = a; i <= b; ++i) {
        for (i64 j = n; j >= 0; --j) {
            i64 y = dp[j];
            for (i64 k = 1; k <= d; ++k) {
                i64 x = j + k * i;
                if (x > n) break;
                y = y * conb(n - (x - i), i) % mod * inv(k) % mod;
                if (k >= c) {
                    (dp[x] += y) %= mod;
                }
            }
        }
        /*
        cerr << i << endl;
        for (int j = 0; j <= n; ++j) cerr << dp[j] << ' ';
        cerr << endl;
        */
    }
    cout << dp[n] << endl;
    return 0;
}