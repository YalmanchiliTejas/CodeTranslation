#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll INF = (1LL << 30) - 1;
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
}
template <ll mod>
struct modint {
    ll val;
    inline ll extgcd(ll a, ll b, ll& x, ll& y) {
        if(a < b) {
            return extgcd(b, a, y, x);
        }
        if(b == 0) {
            x = 1, y = 0;
            return a;
        }
        ll d = extgcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
    inline ll minv(ll k) {
        ll x = 0, y = 0;
        extgcd(k, mod, x, y);
        if(x < 0) {
            x += mod;
        } else if(x == mod) {
            x = 0;
        }
        return x;
    }
    inline ll mpow(ll n) {
        ll res = 1, x = val;
        while(n > 0) {
            if(n & 1) {
                res *= x;
                res %= mod;
            }
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }
    constexpr modint() : val(0) {}
    constexpr modint(ll x) { val = (x + mod) % mod; }
    modint inv() { return modint(minv(val)); }
    modint operator+(const modint& to) const { return modint(val + to.val); }
    modint operator-(const modint& to) const { return modint(val - to.val); }
    modint operator*(const modint& to) const { return modint(val * to.val); }
    modint operator/(const modint& to) const {
        return modint(val * minv(to.val));
    }
    template <class T>
    explicit operator T() {
        return T(val);
    }
    template <typename T>
    modint operator+(const T& to) const {
        return modint(val + to);
    }
    template <typename T>
    modint operator-(const T& to) const {
        return modint(val - to);
    }
    template <typename T>
    modint operator*(const T& to) const {
        return modint(val * to);
    }
    template <typename T>
    modint operator/(const T& to) const {
        return modint(val * minv(to));
    }
    modint& operator++() { return *this = modint(val + 1); }
    modint& operator--() { return *this = modint(val - 1); }
    template <typename T>
    modint& operator+=(const T& to) {
        return *this = *this + to;
    }
    template <typename T>
    modint& operator-=(const T& to) {
        return *this = *this - to;
    }
    template <typename T>
    modint& operator*=(const T& to) {
        return *this = *this * to;
    }
    template <typename T>
    modint& operator/=(const T& to) {
        return *this = *this / to;
    }
    bool operator==(const modint& to) const { return val == to.val; }
    bool operator!=(const modint& to) const { return val != to.val; }
    bool operator>(const modint& to) const { return val > to.val; }
    bool operator>=(const modint& to) const { return val >= to.val; }
    bool operator<(const modint& to) const { return val < to.val; }
    bool operator<=(const modint& to) const { return val <= to.val; }
};
using mint = modint<MOD>;
vector<mint> f, fi;
void comb(int n) {
    f.resize(n + 10);
    fi.resize(n + 10);
    f[0] = 1;
    for(ll i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i;
    }
    fi[n] = f[n].inv();
    for(ll i = n - 1; i >= 0; i--) {
        fi[i] = fi[i + 1] * (i + 1LL);
    }
}
mint ncr(ll n, ll r) {
    if(n < r || n < 0 || r < 0) {
        return 0;
    }
    return f[n] * fi[r] * fi[n - r];
}
inline mint mpow(mint x, ll n) {
    mint res = 1;
    while(n > 0) {
        if(n & 1) {
            res *= x;
        }
        x = x * x;
        n >>= 1;
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;
    comb(n * m + 10);
    vector<mint> s1(n + 10), s2(m + 10);
    for(ll i = 1; i <= n; i++) {
        s1[i] = s1[i - 1] + mint(i * m * m);
    }
    for(ll i = 1; i <= m; i++) {
        s2[i] = s2[i - 1] + mint(i * n * n);
    }
    mint ans = 0;
    for(ll i = 1; i <= n; i++) {
        ans += s1[n - i];
    }
    for(ll i = 1; i <= m; i++) {
        ans += s2[m - i];
    }
    ans *= ncr(n * m - 2, k - 2);
    cout << ans.val << endl;
}
