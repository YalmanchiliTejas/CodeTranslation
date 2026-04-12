#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

// Begin {{{
using namespace std;

#ifndef DEBUG
#define dump(...)
#endif

template <class A, class B> inline bool chmax(A &a, const B &b) noexcept {
    return b > a && (a = b, true);
}

template <class A, class B> inline bool chmin(A &a, const B &b) noexcept {
    return b < a && (a = b, true);
}

template <class T>
inline vector<T> make_v(const T &initializeValue, size_t sz) {
    return vector<T>(sz, initializeValue);
}

template <class T, class... Args>
inline auto make_v(const T &initializeValue, size_t sz, Args... args) {
    return vector<decltype(make_v<T>(initializeValue, args...))>(sz, make_v<T>(initializeValue, args...));
}

constexpr int INF = 0x3f3f3f3f;
constexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;
// }}} End

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N; cin >> N;

    vector<intmax_t> x(N);
    vector<intmax_t> sorted(N);
    for (size_t i = 0; i < N; ++i) {
        cin >> x[i];
        sorted[i] = x[i];
    }

    sort(sorted.begin(), sorted.end());
    intmax_t Q2_idx = N / 2 - 1;
    intmax_t Q2 = sorted[Q2_idx];
    dump(Q2);

    for (const auto e: x) {
        if (e <= Q2) {
            cout << sorted[Q2_idx + 1] << "\n";
        } else {
            cout << sorted[Q2_idx] << "\n";
        }
    }

    return 0;
}
