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
    ll n, x; int m;
    cin >> n >> x >> m;
    int LOG = 40;
    auto to = make_vec<int>({LOG, m});
    auto sum = make_vec<ll>({LOG, m});

    for (ll i = 0; i < m; ++i) {
        to[0][i] = i * i % m;
        sum[0][i] = i;
    }

    rep(i, LOG - 1) {
        rep(j, m) {
            to[i+1][j] = to[i][to[i][j]];
            sum[i+1][j] = sum[i][j] + sum[i][to[i][j]];
        }
    }

    ll ans = 0;
    rep(i, LOG) {
        if (n >> i & 1) {
            ans += sum[i][x];
            x = to[i][x];
        }
    }
    cout << ans << '\n';
}