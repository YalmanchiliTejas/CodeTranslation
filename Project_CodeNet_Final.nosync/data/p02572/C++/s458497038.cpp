#include <bits/stdc++.h>
#define For(i, a, b) for (int(i) = (int)(a); (i) < (int)(b); ++(i))
#define rFor(i, a, b) for (int(i) = (int)(a)-1; (i) >= (int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T div_floor(T a, T b) {
    if (b < 0) a *= -1, b *= -1;
    return a >= 0 ? a / b : (a + 1) / b - 1;
}
template <class T>
T div_ceil(T a, T b) {
    if (b < 0) a *= -1, b *= -1;
    return a > 0 ? (a - 1) / b + 1 : a / b;
}

constexpr lint mod = 1000000007;
constexpr lint INF = mod * mod;
constexpr int MAX = 200010;

template <int_fast64_t MOD>
struct modint {
    using i64 = int_fast64_t;
    i64 a;
    modint(const i64 a_ = 0) : a(a_) {
        if (a > MOD)
            a %= MOD;
        else if (a < 0)
            (a %= MOD) += MOD;
    }
    modint inv() {
        i64 t = 1, n = MOD - 2, x = a;
        while (n) {
            if (n & 1) (t *= x) %= MOD;
            (x *= x) %= MOD;
            n >>= 1;
        }
        modint ret(t);
        return ret;
    }
    bool operator==(const modint x) const { return a == x.a; }
    bool operator!=(const modint x) const { return a != x.a; }
    modint operator+(const modint x) const { return modint(*this) += x; }
    modint operator-(const modint x) const { return modint(*this) -= x; }
    modint operator*(const modint x) const { return modint(*this) *= x; }
    modint operator/(const modint x) const { return modint(*this) /= x; }
    modint operator^(const lint x) const { return modint(*this) ^= x; }
    modint &operator+=(const modint &x) {
        a += x.a;
        if (a >= MOD) a -= MOD;
        return *this;
    }
    modint &operator-=(const modint &x) {
        a -= x.a;
        if (a < 0) a += MOD;
        return *this;
    }
    modint &operator*=(const modint &x) {
        (a *= x.a) %= MOD;
        return *this;
    }
    modint &operator/=(modint x) {
        (a *= x.inv().a) %= MOD;
        return *this;
    }
    modint &operator^=(lint n) {
        i64 ret = 1;
        while (n) {
            if (n & 1) (ret *= a) %= MOD;
            (a *= a) %= MOD;
            n >>= 1;
        }
        a = ret;
        return *this;
    }
    modint operator-() const { return modint(0) - *this; }
    modint &operator++() { return *this += 1; }
    modint &operator--() { return *this -= 1; }
    bool operator<(const modint x) const { return a < x.a; }
};

using mint = modint<1000000007>;

vector<mint> fact;
vector<mint> revfact;

void setfact(int n) {
    fact.resize(n + 1);
    revfact.resize(n + 1);
    fact[0] = 1;
    rep(i, n) fact[i + 1] = fact[i] * mint(i + 1);

    revfact[n] = fact[n].inv();
    for (int i = n - 1; i >= 0; i--) revfact[i] = revfact[i + 1] * mint(i + 1);
}

mint getC(int n, int r) {
    if (n < r) return 0;
    return fact[n] * revfact[r] * revfact[n - r];
}

int main() {
    int n;
    scanf("%d", &n);
    mint a[n];
    mint sum = 0, sqsum = 0;
    rep(i, n) {
        scanf("%lld", &a[i]);
        sum += a[i];
        sqsum += a[i] * a[i];
    }
    printf("%lld\n", ((sum * sum - sqsum) / mint(2)).a);
}