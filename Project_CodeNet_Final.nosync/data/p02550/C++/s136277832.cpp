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
    ll sum = 0;
    auto nxt = [](ll x, ll m) {
        return (x * x) % m;
    };
    vector<ll> a;
    set<ll> s;
    int cnt = 0;
    int num = 0;
    for (int i = 0; i < n; ++i) {
        a.push_back(x);
        s.insert(x);
        sum += x;
        cnt++;        
        x = nxt(x, m);
        if (s.count(x)) {
            num = x;
            break;
        }
    }
    if (cnt == n) {
        cout << sum << '\n';
        return 0;
    }
    ll nokori = n - cnt;
    ll psum = 0;
    ll plen = 0;
    bool flag = false;
    rep(i, a.size()) {
        if (flag) {
            plen++;
            psum += a[i];
        } else {
            if (a[i] == num) {
                flag = true;
                plen++;
                psum += a[i];
            }
        }
    }
    ll block = nokori / plen;
    ll amari = nokori % plen;
    sum += block * psum;
    int cntt = 0;
    flag = false;
    rep(i, a.size()) {
        if (cntt == amari) break;
        if (flag) {
            cntt++;
            sum += a[i];
        } else {
            if (a[i] == num) {
                cntt++;
                sum += a[i];
                flag = true;
            }
        }
    }
    cout << sum << '\n';
}