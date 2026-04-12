#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <utility>
#include <tuple>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
using namespace std;
using ll = long long int;
using P = pair<ll, ll>;

// clang-format off
#ifdef _DEBUG_
#define dump(...) do{ cerr << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; PPPPP(__VA_ARGS__); cerr << endl; } while(false)
template<typename T> void PPPPP(T t) { cerr << t; }
template<typename T, typename... S> void PPPPP(T t, S... s) { cerr << t << ", "; PPPPP(s...); }
#else
#define dump(...) do{ } while(false)
#endif
template<typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template<typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v(ts...))>(a, make_v(ts...)); }
template<typename T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }
template<typename T> bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false; }
template<typename T> void print(T a) { cout << a << endl; }
template<typename T, typename... Ts> void print(T a, Ts... ts) { cout << a << ' '; print(ts...); }
template<typename T> istream &operator,(istream &in, T &t) { return in >> t; }
// clang-format on

template<ll MOD = 1000000007>
class ModInt {
    ll n;
    ModInt constexpr inverse() const {
        return ModInt::pow(*this, MOD - 2);
    }

public:
    ModInt()
        : n(0) {}
    ModInt(ll _n)
        : n(((_n % MOD) + MOD) % MOD) {}
    ModInt operator+=(const ModInt &m) {
        n += m.n;
        if (n >= MOD) n -= MOD;
        return *this;
    }
    ModInt operator-=(const ModInt &m) {
        n -= m.n;
        if (n < 0) n += MOD;
        return *this;
    }
    ModInt operator*=(const ModInt &m) {
        n *= m.n;
        if (n >= MOD) n %= MOD;
        return *this;
    }
    ModInt operator/=(const ModInt &m) {
        (*this) *= m.inverse();
        return *this;
    }
    friend ModInt operator+(ModInt t, const ModInt &m) {
        return t += m;
    }
    friend ModInt operator-(ModInt t, const ModInt &m) {
        return t -= m;
    }
    friend ModInt operator*(ModInt t, const ModInt &m) {
        return t *= m;
    }
    friend ModInt operator/(ModInt t, const ModInt &m) {
        return t /= m;
    }
    ModInt operator=(const ll l) {
        n = l % MOD;
        if (n < 0) n += MOD;
        return *this;
    }
    friend ostream &operator<<(ostream &out, const ModInt &m) {
        out << m.n;
        return out;
    }
    friend istream &operator>>(istream &in, ModInt &m) {
        ll l;
        in >> l;
        m = l;
        return in;
    }
    static constexpr ModInt pow(const ModInt x, ll p) {
        ModInt<MOD> ans = 1;
        for (ModInt<MOD> m = x; p > 0; p /= 2, m *= m) {
            if (p % 2) ans *= m;
        }
        return ans;
    }
};
using mint = ModInt<>;
mint operator"" _m(unsigned long long m) {
    return mint(m);
}

class Combination {
    vector<mint> factor, rfactor;

public:
    Combination(int n) {
        factor.resize(n, 1);
        rfactor.resize(n, 1);
        for (int i = 1; i < n; i++) {
            factor[i] = i * factor[i - 1];
        }
        rfactor[n - 1] = 1 / factor[n - 1];
        for (int i = n - 1; i > 0; i--) {
            rfactor[i - 1] = rfactor[i] * i;
        }
    }
    mint nCr(int n, int r) {
        return factor[n] * rfactor[r] * rfactor[n - r];
    }
    mint nPr(int n, int r) {
        return factor[n] * rfactor[n - r];
    }
    mint nSr(ll n, int r) {
        mint ans = 0;
        for (int i = r, s = 1; i >= 0; i--, s *= -1) {
            ans += s * nCr(r, i) * mint::pow(i, n);
        }
        return ans * rfactor[r];
    }
    mint factorial(int n) {
        return factor[n];
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m, k;
    cin, n, m, k;
    Combination comb(n * m + 1);
    cout << comb.nCr(n * m, k) * comb.nCr(k, 2) / comb.nCr(n * m, 2) * n * m * (n + m) * (n * m - 1) / 6 << endl;
    return 0;
}
