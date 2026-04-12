#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define rrep(i, n) for (int i = (int)n-1; i >= 0; --i)
using namespace std;
using namespace atcoder;
using ll = long long;
template<typename T>
inline bool chmax(T& a, const T& b) {
    if (a < b){
        a = b;
        return true;
    }
    return false;
}
template<typename T>
inline bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
/**
 * @brief 多次元 vector の作成
 * @author えびちゃん
 */
namespace detail {
    template<typename T, int N>
    auto make_vec(vector<int>& sizes, T const& x) {
        if constexpr (N == 1) {
            return vector(sizes[0], x);
        } else {
            int size = sizes[N-1];
            sizes.pop_back();
            return vector(size, make_vec<T, N-1>(sizes, x));
        }
    }
}
template<typename T, int N>
auto make_vec(int const(&sizes)[N], T const& x = T()) {
    vector<int> s(N);
    for (int i = 0; i < N; ++i) s[i] = sizes[N-i-1];
    return detail::make_vec<T, N>(s, x);
}
__attribute__((constructor))
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int op(int a, int b) { return max(a, b); }
int e() { return -1; }

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    segtree<int, op, e> seg(a);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1 || t == 3) {
            int x, v;
            cin >> x >> v;
            x--;
            if (t == 1) {
                seg.set(x, v);
            } else {
                auto f = [&](int a) { return a < v; };
                cout << seg.max_right<decltype(f)>(x, f) + 1 << '\n';
            }
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << seg.prod(l, r+1) << '\n';
        }
    }
}
