#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll LINF = (1LL << 60) - 1LL;
constexpr double eps = 1e-9;
constexpr ll MOD = 1000000007LL;
template <typename T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
};
template <typename T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
};
template <typename T> ostream &operator<<(ostream &os, vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << (i + 1 == v.size() ? "\n" : " ");
    }
    return os;
}
template <typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template <typename T, typename... Ts> auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type fill_v(T &t, const V &v) {
    t = v;
}
template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type fill_v(T &t, const V &v) {
    for (auto &e : t) {
        fill_v(e, v);
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= -1LL;
    }
    vector<ll> dp(n + 1, INF);
    dp[0] = -INF;
    for (int i = 0; i < n; i++) {
        int id = upper_bound(all(dp), a[i]) - dp.begin();
        chmin(dp[id], a[i]);
    }
    for (int i = n; i >= 0; i--) {
        if (dp[i] != INF) {
            cout << i << endl;
            return 0;
        }
    }
}
