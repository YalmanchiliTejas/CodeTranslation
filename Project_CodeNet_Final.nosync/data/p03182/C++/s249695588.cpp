#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

template<typename F, typename G, typename H, typename T, typename S>
struct lazy_segment_tree {
    size_t offset, height;
    vector<T> data, lazy;

    const F f_;
    const G g_;
    const H h_;
    const T unit_;
    const S lazy_unit_;

    lazy_segment_tree(
        size_t size,
        const F f, const G g, const H h,
        const T unit, const S lazy_unit):
        f_(f), g_(g), h_(h), unit_(unit), lazy_unit_(lazy_unit) {
        offset = 1, height = 0;
        while (offset < size) offset <<= 1, height++;
        data.assign(offset << 1, unit);
        lazy.assign(offset << 1, lazy_unit);
        offset--;
    }

    void propagate(size_t i) {
        if (lazy[i] == lazy_unit_) return;
        lazy[i << 1 | 0] = h_(lazy[i << 1 | 0], lazy[i]);
        lazy[i << 1 | 1] = h_(lazy[i << 1 | 1], lazy[i]);
        data[i] = reflect(i);
        lazy[i] = lazy_unit_;
    }

    void thrust(size_t i) {
        for (size_t j = height; j > 0; j--) propagate(i >> j);
    }

    T reflect(size_t i) {
        return lazy[i] == lazy_unit_ ? data[i] : g_(data[i], lazy[i]);
    }

    void recalc(size_t i) {
        while (i >>= 1) data[i] = f_(reflect(i << 1 | 0), reflect(i << 1 | 1));
    }

    void update(size_t l, size_t r, const T x) {
        thrust(l += offset);
        thrust(r += offset - 1);
        for (size_t li = l, ri = r + 1; li < ri; li >>= 1, ri >>= 1) {
            if (li & 1) lazy[li] = h_(lazy[li], x), li++;
            if (ri & 1) ri--, lazy[ri] = h_(lazy[ri], x);
        }
        recalc(l);
        recalc(r);
    }

    T query(size_t l, size_t r) {
        thrust(l += offset);
        thrust(r += offset - 1);
        T lv = unit_, rv = unit_;
        for (size_t li = l, ri = r + 1; li < ri; li >>= 1, ri >>= 1) {
            if (li & 1) lv = f_(lv, reflect(li)), li++;
            if (ri & 1) ri--, rv = f_(reflect(ri), rv);
        }
        return f_(lv, rv);
    }
};

void solve() {
    i64 n, m;
    cin >> n >> m;

    vector<vector<p64>> p(n + 1);
    for (i64 i = 0; i < m; i++) {
        i64 l, r, a;
        cin >> l >> r >> a;
        p[r].emplace_back(l, a);
    }

    auto f = [&](i64 a, i64 b) { return max(a, b); };
    lazy_segment_tree dp(n, f, plus(), plus(), 0l, 0l);
    for (i64 i = 1; i <= n; i++) {
        dp.update(i, i + 1, dp.query(0, i));
        for (auto [ l, a ] : p[i]) dp.update(l, i + 1, a);
    }
    cout << dp.query(1, n + 1) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
