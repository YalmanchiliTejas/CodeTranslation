#include <bits/stdc++.h>  // clang-format off
using namespace std;
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (int i = (a), lim_i = (b); i < lim_i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sun Mar 22 21:12:27 JST 2020
 **/

template <class T> T pow(T x, int n, const T UNION = 1) {
    T ret = UNION;
    while (n) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

template <int MD> struct ModInt {
    int x;
    static unordered_map<int, int> to_inv;
    ModInt() : x(0) {}
    ModInt(long long x_) {
        if ((x = x_ % MD + MD) >= MD) x -= MD;
    }

    ModInt& operator+=(ModInt that) {
        if ((x += that.x) >= MD) x -= MD;
        return *this;
    }
    ModInt& operator*=(ModInt that) {
        x = (unsigned long long)x * that.x % MD;
        return *this;
    }
    ModInt& operator-=(ModInt that) {
        if ((x -= that.x) < 0) x += MD;
        return *this;
    }
    ModInt& operator/=(ModInt that) {
        x = (unsigned long long)x * that.inv().x % MD;
        return *this;
    }
    ModInt operator-() const { return -x < 0 ? MD - x : -x; }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt inv() const { return to_inv.count(this->x) ? to_inv[this->x] : (to_inv[this->x] = pow(*this, MD - 2).x); }

    friend ostream& operator<<(ostream& s, ModInt<MD> a) {
        s << a.x;
        return s;
    }
    friend istream& operator>>(istream& s, ModInt<MD>& a) {
        long long tmp;
        s >> tmp;
        a = ModInt<MD>(tmp);
        return s;
    }
    friend string to_string(ModInt<MD> a) { return to_string(a.x); }
};
template <int MD> unordered_map<int, int> ModInt<MD>::to_inv;
using mint = ModInt<998244353>;

vector<mint> fact, fact_inv;
void init_factorial(int n) {
    fact = vector<mint>(n + 1, 1);
    fact_inv = vector<mint>(n + 1);
    for (int i = 0; i < n; i++) fact[i + 1] = fact[i] * (i + 1);
    fact_inv[n] = mint(1) / fact[n];
    for (int i = n - 1; i >= 0; i--) fact_inv[i] = fact_inv[i + 1] * (i + 1);
    // for (int i = 0; i < n + 1; i++) assert(fact[i] * fact_inv[i] == 1);
}
mint comb(int n, int r) { return fact[n] * fact_inv[r] * fact_inv[n - r]; }

template <class T, class S> vector<T> make_vec(size_t n, S x) { return vector<T>(n, x); }
template <class T, class... Ts> auto make_vec(size_t n, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(n, make_vec<T>(ts...));
}

signed main() {
    Int n, S;
    cin >> n >> S;
    vector<Int> a(n);
    REP(i, n) cin >> a[i];
    vector<mint> dp(S + 1);
    mint ans = 0;
    REP(i, n) {
        for (Int j = S; j >= 0; j--) {
            if (j - a[i] >= 0) dp[j] += dp[j - a[i]];
        }
        if (a[i] <= S) dp[a[i]] += i + 1;
        ans += dp[S];
    }
    cout << ans << endl;
}
