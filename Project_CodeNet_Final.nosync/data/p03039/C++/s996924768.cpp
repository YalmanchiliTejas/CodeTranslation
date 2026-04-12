#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template<typename T, T MOD>
struct ModType {
    using Int = T;
    static constexpr Int mod = MOD;
    Int v;

    ModType(long long _v = 0) : v(set(_v)) {}
    ModType(const ModType &r) : v(set(r.v)) {}

    inline static Int set(const Int x) { return x < 0 ? (x % mod) + mod : x % mod; }
    inline void set() { v = set(v); }

    bool operator<(ModType r) const { return v < r.v; }
    bool operator>(ModType r) const { return r.v < v; }
    bool operator==(ModType r) const { return v == r.v; }
    bool operator!= (ModType r) const { return v != r.v; }
    bool operator<=(ModType r) const { return v <= r.v; }

    ModType operator-() const { return ModInt(v ? mod - v : v); }
    ModType &operator=(const ModType &r) { if (this != &r) v = set(r.v); return *this; }
    ModType &operator+=(ModType r) { (v += r.v) %= mod; return *this; }
    ModType &operator-=(ModType r) { (v -= r.v - mod) %= mod; return *this; }
    // ModType &operator*=(ModType r) { v = (__uint128_t(v) * r.v) % mod; return *this; }
    ModType &operator*=(ModType r) { v = 1ULL * v * r.v % mod; return *this; }
    ModType &operator/=(ModType r) { *this *= r.inv(); return *this; }
    ModType operator+(ModType r) const { return ModType(*this) += r; }
    ModType operator-(ModType r) const { return ModType(*this) -= r; }
    ModType operator*(ModType r) const { return ModType(*this) *= r; }
    ModType operator/(ModType r) const { return ModType(*this) /= r; }

    ModType inv() const {
        long long a = v, b = mod, u = 1, w = 0;
        while (b) {
            long long t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * w, w);
        }
        return ModType(u);
    }

    ModType pow(Int e) {
        ModType a = *this, x(1);
        for ( ; 0 < e; e >>= 1) { if (e & 1) x *= a; a *= a; }
        return x;
    }
    inline ModType pow(ModType &e) { return pow(e.v); }

    friend std::ostream &operator<<(std::ostream &os, const ModType &r) { return os << r.v; }
    friend std::istream &operator>>(std::istream &is, ModType &r) {
        is >> r.v; r.set();return is;
    }

    static std::vector<ModType> Inverse(const Int n = mod - 1) {
        std::vector<ModType> inv(n + 1);
        inv[1].v = 1;
        for (Int a = 2; a <= n; ++a)
            inv[a] = inv[mod % a] * T(mod - mod / a);
        return inv;
    }
};

using ModInt = ModType<int, 1000000007>;

struct Combination {
    const ModInt::Int mod = ModInt::mod, N;
    std::vector<ModInt> fact, inv_f;

    // MultiChoose を使用する場合は N = 2 * _n とする
    explicit Combination(int _n) : N(_n < mod ? _n : mod - 1), fact(N + 1), inv_f(N + 1) {
        fact[0] = 1;
        for (int i = 1; i <= N; ++i) fact[i] = fact[i - 1] * i;
        inv_f[N] = fact[N].inv();
        for (int i = N; 1 <= i; --i) inv_f[i - 1] = inv_f[i] * i;
    }

    ModInt choose(const int n, const int k) const {
        if (n < 0 || k < 0 || n < k) return ModInt(0);
        else return fact[n] * inv_f[k] * inv_f[n - k];
    }
};

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    // cout << setprecision(8) << setiosflags(ios::fixed);

    ModInt n, m, k;
    cin >> n >> m >> k;

    Combination c(n.v * m.v + 1);
    ModInt res, nm = c.choose(n.v * m.v - 2, k.v - 2);
    for (ModInt d(1); d <= n; d += 1) {
        res += d * nm * (n - d) * m * m;
    }
    for (ModInt d(1); d <= m; d += 1) {
        res += d * nm * (m - d) * n * n;
    }

    cout << res << endl;

    return 0;
}
