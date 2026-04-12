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
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cstdint>
#include <cassert>
#include <random>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (size_t i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (size_t i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T iabs(const T& x) { return max(x, -x); }
// #define abs gabs

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

int main() {
    i64 n, m, k;
    cin >> n >> m >> k;
    i64 ans = 0;
    for (int i = 0; i < 2; ++i) {
        i64 c = n * n % mod * conb(n * m - 2, k - 2) % mod;
        for (i64 d = 1; d < m; ++d) {
            (ans += (m - d) * d % mod * c % mod) %= mod;
        }
        swap(n, m);
    }
    cout << ans << endl;
    return 0;
}