#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <climits>
#include <cstdint>
using namespace std;

inline namespace atcoder {
    template <typename T, size_t Depth>
    struct vector_helper { using type = vector<typename vector_helper<T, Depth - 1>::type>; };
    template <typename T>
    struct vector_helper<T, 0> { using type = T; };
    template <typename T, size_t Depth>
    using vector_t = typename vector_helper<T, Depth>::type;

    template <typename T> using vec = vector_t<T, 1>;
    template <typename T> using vvec = vector_t<T, 2>;
    template <typename T> using vvvec = vector_t<T, 3>;
}

int main() {
    constexpr int mod = 1000000000 + 7;

    int n; cin >> n;
    vec<int64_t> a(n);
    for (auto &e : a) cin >> e;

    vec<int64_t> sum(n, 0); sum[0] = a[0];
    for (int i = 0; i < n - 1; ++i) {
        sum[i + 1] = (sum[i] + a[i + 1]) % mod;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto subsum = sum.back() - sum[i];
        if (subsum < 0) {
            subsum += mod;
        }

        ans = (ans + ((a[i] * subsum) % mod)) % mod;
    }

    cout << ans << endl;
}

