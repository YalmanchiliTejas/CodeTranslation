#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll LINF = (1LL << 60) - 1LL;
constexpr double eps = 1e-9;
constexpr ll MOD = 1000000007LL;
template <typename T>
bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
};
template <typename T>
bool chmax(T& a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
};
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for(int i = 0; i < v.size(); i++) {
        os << v[i] << (i + 1 == v.size() ? "\n" : " ");
    }
    return os;
}
template <typename T>
vector<T> make_v(size_t a) {
    return vector<T>(a);
}
template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type fill_v(T& t, const V& v) {
    t = v;
}
template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type fill_v(T& t, const V& v) {
    for(auto& e : t) {
        fill_v(e, v);
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = a[n - 1];
    for(int c = 1; c < n; c++) {
        ll s1 = 0, s2 = a[n - 1];
        for(int k = 1; k * c < n - 1; k++) {
            s1 += a[k * c];
            ll t = n - 1 - k * c;
            s2 += a[t];
            if(t % c == 0 && k * c >= t) {
                break;
            }
            if(c < t) {
                chmax(ans, s1 + s2);
            }
        }
    }
    cout << ans << endl;
}
