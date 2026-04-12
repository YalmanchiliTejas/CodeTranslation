// #include <atcoder/all>
// using namespace atcoder;
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define rrep(i, n) for (int i = (int)n-1; i >= 0; --i)
using namespace std;
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

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    
    vector<int> id(m, -1);
    vector<int> a;
    int len = 0;
    ll tot = 0;
    while (id[x] == -1) {
        id[x] = len++;
        tot += x;
        a.push_back(x);
        x = (x * x) % m;
    }
    int cycle = len - id[x];
    ll cycle_sum = 0;
    for (int i = id[x]; i < len; ++i) cycle_sum += a[i];

    ll ans = 0;
    if (n <= len) {
        rep(i, n) ans += a[i];
    } else {
        ans += tot;
        n -= len;
        ans += cycle_sum * (n / cycle);
        n %= cycle;
        rep(i, n) ans += a[id[x] + i];
    }
    cout << ans << '\n';
}