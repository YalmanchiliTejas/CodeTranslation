//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL
#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

#ifdef LOCAL
struct PrettyOS {
    ostream& os;
    bool first;
    template <class T> auto operator<<(T&& x) {
        if (!first) os << ", ";
        first = false;
        os << x;
        return *this;
    }
};
template <class... T> void dbg0(T&&... t) {
    (PrettyOS{cerr, true} << ... << t);
}
#define dbg(...)                                            \
    do {                                                    \
        cerr << __LINE__ << " : " << #__VA_ARGS__ << " = "; \
        dbg0(__VA_ARGS__);                                  \
        cerr << endl;                                       \
    } while (false);
#else
#define dbg(...)
#endif

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}

template <uint MD> struct ModInt {
    using M = ModInt;
    const static M G;
    uint v;
    ModInt(ll _v = 0) { set_v(_v % MD + MD); }
    M& set_v(uint _v) {
        v = (_v < MD) ? _v : _v - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M() - *this; }
    M operator+(const M& r) const { return M().set_v(v + r.v); }
    M operator-(const M& r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M& r) const { return M().set_v(ull(v) * r.v % MD); }
    M operator/(const M& r) const { return *this * r.inv(); }
    M& operator+=(const M& r) { return *this = *this + r; }
    M& operator-=(const M& r) { return *this = *this - r; }
    M& operator*=(const M& r) { return *this = *this * r; }
    M& operator/=(const M& r) { return *this = *this / r; }
    bool operator==(const M& r) const { return v == r.v; }
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    M inv() const { return pow(MD - 2); }
    friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }
};
using Mint = ModInt<998244353>;
// template<> const Mint Mint::G = Mint(3);
const int MN = TEN(7) + TEN(3);
V<Mint> fact(MN), iFac(MN);

Mint C(int n, int k) {
    if (n < k || k < 0) return Mint(0);
    return fact[n] * iFac[k] * iFac[n - k];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    fact[0] = Mint(1);
    for (int i = 1; i < MN; i++) {
        fact[i] = fact[i - 1] * Mint(i);
    }
    iFac[MN - 1] = fact[MN - 1].inv();
    for (int i = MN - 1; i >= 1; i--) {
        iFac[i - 1] = iFac[i] * Mint(i);
    }
    V<Mint> p2(MN);
    p2[0] = Mint(1);
    for (int i = 1; i < MN; i++) {
        p2[i] = p2[i - 1] * Mint(2);
    }

    assert((fact[25] * iFac[25]).v == 1);
    int n;
    cin >> n;
    int m = n / 2;
    Mint ans = Mint(3).pow(n);
    for (int a = m + 1; a <= n; a++) {
        ans -= Mint(2) * C(n, a) * p2[n - a];
    }
/*    for (int a = 0; a <= m; a++) {
        for (int b = 0; b <= m; b++) {
            ans += C(n, a) * C(n - a, b);
        }
    }*/
    cout << ans << endl;
    return 0;
}
