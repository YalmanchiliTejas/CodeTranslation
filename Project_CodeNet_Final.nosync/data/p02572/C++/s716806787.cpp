#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (int i = 0; i < sz(v); i++) {
        os << v[i];
        if (i < sz(v) - 1) os << " ";
    }
    return os;
}
struct modint {
    ll x;
    modint(ll x = 0) : x((x % MOD + MOD) % MOD) {
    }
    ll value() const {
        return x;
    }
    modint operator-() const {
        return modint(-x);
    }
    modint& operator+=(const modint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    modint& operator-=(const modint a) {
        if ((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }
    modint& operator*=(const modint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    modint operator+(const modint a) const {
        modint res(*this);
        return res += a;
    }
    modint operator-(const modint a) const {
        modint res(*this);
        return res -= a;
    }
    modint operator*(const modint a) const {
        modint res(*this);
        return res *= a;
    }
    modint pow(ll t) const {
        if (t == 0) return 1;
        modint a = pow(t >> 1);
        a *= a;
        if (t % 2 == 1) a *= *this;
        return a;
    }
    modint inv() const {
        return pow(MOD - 2);
    }
    modint& operator/=(const modint a) {
        return (*this) *= a.inv();
    }
    modint operator/(const modint a) const {
        modint res(*this);
        return res /= a;
    }
};
ostream& operator<<(ostream& os, const modint& x) {
    os << x.value();
    return os;
}
struct combination {
    vector<modint> fact, ifact;
    combination(int n) : fact(n + 1), ifact(n + 1) {
        assert(n < MOD);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; i--) {
            ifact[i - 1] = ifact[i] * i;
        }
    }
    modint operator()(int n, int k) {
        if (n < k || k < 0) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
    modint h(int n, int k) {
        n += k - 1;
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
} comb(2002002);
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    modint ans = 0;
    rep(i, n) ans += modint(a[i]);
    ans *= ans;
    rep(i, n) ans -= modint(a[i] * a[i]);
    ans /= 2;
    cout << ans << endl;
}