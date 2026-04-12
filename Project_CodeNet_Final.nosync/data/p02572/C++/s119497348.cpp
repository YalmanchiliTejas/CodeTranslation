#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

template<int64_t MOD> class ModInt {
public:
    int64_t x;
    constexpr ModInt() : x(0) {}
    constexpr ModInt(int64_t v) : x((v % MOD + MOD) % MOD) {}
    constexpr ModInt operator - () const noexcept { return x ? MOD - x : 0;}
    constexpr ModInt operator + (const ModInt a) const noexcept { return ModInt(*this) += a;}
    constexpr ModInt operator - (const ModInt a) const noexcept { return ModInt(*this) -= a;}
    constexpr ModInt operator * (const ModInt a) const noexcept { return ModInt(*this) *= a;}
    constexpr ModInt operator / (const ModInt a) const noexcept { return ModInt(*this) /= a;}
    constexpr ModInt operator / (const int64_t a) const noexcept { return ModInt(*this) /= a;}
    constexpr ModInt operator += (const ModInt a) noexcept {
        x += a.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    constexpr ModInt operator += (const int64_t a) noexcept {
        auto hs = ModInt<MOD>(a);
        (*this) += hs;
        return *this;
    }
    constexpr ModInt operator -= (const ModInt a) noexcept {
        if (x < a.x) x += MOD;
        x -= a.x;
        return *this;
    }
    constexpr ModInt operator -= (const int64_t a) noexcept {
        auto hs = ModInt<MOD>(a);
        (*this) -= hs;
        return *this;
    }
    constexpr ModInt operator *= (const ModInt a) noexcept {
        x = x * a.x % MOD;
        return *this;
    }
    constexpr ModInt operator *= (const int64_t a) noexcept {
        auto hs = ModInt<MOD>(a);
        (*this) *= hs;
        return *this;
    }
    constexpr ModInt &operator /= (ModInt a) noexcept {
        int64_t exp = MOD - 2;
        while (exp > 0) {
            if (exp & 1ul) *this *= a;
            a *= a;
            exp >>= 1ul;
        }
        return *this;
    }
    constexpr ModInt &operator /= (int64_t a) noexcept {
        auto hs = ModInt<MOD>(a);
        (*this) /= hs;
        return *this;
    }
    constexpr ModInt &operator ++ () noexcept {
        return *this;
    }
    constexpr ModInt operator ++ (int) noexcept {
        if (++x >= MOD) x -= MOD;
        return *this;
    }
    constexpr ModInt &operator -- () noexcept {
        return *this;
    }
    constexpr ModInt operator -- (int) noexcept {
        if (x-- == 0) x += MOD;
        return *this;
    }
    constexpr bool operator < (const ModInt a) const noexcept { return x < a.x;}
    constexpr bool operator == (const ModInt a) const noexcept { return this->x == a.x;}
    constexpr bool operator != (const ModInt a) const noexcept { return !(*this == a);}
    friend istream &operator >> (istream &in, ModInt &m) {
        in >> m.x;
        if (m.x < 0) m.x += MOD;
        m.x %= MOD;
        return in;
    }
    friend ostream &operator << (ostream &out, const ModInt &p) { return out << p.x;}
    constexpr ModInt pow(int64_t p) const {
        ModInt ret(1);
        ModInt mul(x);
        while (p > 0) {
            if (p & 1ul) ret *= mul;
            mul *= mul;
            p >>= 1ul;
        }
        return ret;
    }
};

const int64_t MOD = 1000000007LL;
using mint = ModInt<MOD>;

int main() {
    int N; cin >> N;
    vector<mint> A(N);
    for(auto &e : A) cin >> e;
    mint all = 0;
    rep(i, N) all += A[i];
    all *= all;
    rep(i, N) all -= (A[i] * A[i]);
    all /= 2;
    cout << all << '\n';
    return 0;
}
