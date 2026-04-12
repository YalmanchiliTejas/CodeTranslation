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
using P = pair<int, int>;

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

template<ll MOD = 998244353>
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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, s;
    cin, n, s;
    vector<int> a(n);
    REP(i, 0, n) {
        cin, a[i];
    }
    auto dp = make_v(n + 1, s + 1, 0_m);
    dp[0][0] = 1;
    mint ans = 0;
    REP(i, 0, n) {
        REP(j, 0, s + 1) {
            dp[i + 1][j] += dp[i][j];
            if (j + a[i] > s) continue;
            if (j == 0) {
                dp[i + 1][j + a[i]] += (i + 1) * dp[i][j];
            } else {
                dp[i + 1][j + a[i]] += dp[i][j];
            }
        }
        ans += dp[i + 1][s];
    }
    cout << ans << endl;

    return 0;
}
