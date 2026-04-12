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

    vector<i64> f(s + 1);
    f[0] = 1;
    i64 ans = 0;
    for (i64 k : a) {
        vector<i64> g = f;
        for (i64 i = 0; i <= s - k; ++i) {
            (g[i + k] += f[i]) %= mod;
        }
        (g[0] += 1) %= mod;
        f = g;
        ans += f[s];
    }
    ans %= mod;
    cout << ans << endl;
    return 0;
}