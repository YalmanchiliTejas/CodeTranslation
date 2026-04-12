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

const i64 mod = 1e9 + 7;
i64 ipow(i64 a, i64 b) {
    i64 x = a, y = 1;
    for (; b > 0; b >>= 1) {
        if (b & 1) (y *= x) %= mod;
        (x *= x) %= mod;
    }
    return y;
}
i64 inv(i64 x) {
    return ipow(x, mod - 2);
}
i64 fact(i64 x) {
    static vector<i64> f;
    i64 i = f.size();
    if (x >= i) {
        f.resize(x + 1);
        for (; i <= x; ++i) {
            f[i] = i == 0 ? 1 : i * f[i - 1] % mod;
        }
    }
    return f[x];
}
i64 perm(i64 n, i64 k) {
    return k <= n ? fact(n) * inv(fact(n - k)) % mod : 0;
}
i64 conb(i64 n, i64 k) {
    return k <= n ? fact(n) * inv(fact(k) * fact(n - k) % mod) % mod : 0;
}

i64 dp[102][2][5];
string s;
int k, n;
i64 f(int i, bool b, int c) {
    if (c == 0) return 1;
    if (i == n) return 0;
    if (dp[i][b][c] > 0) return dp[i][b][c];
    int d = s[i] - '0';
    i64 res = 0;
    if (b) {
        if (d == 0) {
            res = f(i + 1, true, c);
        } else {
            res = f(i + 1, true, c - 1) + (d - 1) * f(i + 1, false, c - 1) + f(i + 1, false, c);
        }
    } else {
        res = 9 * f(i + 1, false, c - 1) + f(i + 1, false, c);
    }
    return dp[i][b][c] = res;
}

int main() {
    /*
    i64 r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    */
    cin >> s >> k;
    n = s.size();
    i64 ans = f(0, true, k);
    cout << ans << endl;
    return 0;
}