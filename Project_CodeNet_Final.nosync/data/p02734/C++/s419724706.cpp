#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define eb emplace_back
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll MOD = 998244353LL;
template <class T>
void chmin(T &a, T b) { a = min(a, b); }
template <class T>
void chmax(T &a, T b) { a = max(a, b); }
void ok() { cerr << "ok" << endl; }
template <std::uint_fast64_t Modulus>
class modint {
    using u64 = std::uint_fast64_t;

  public:
    u64 a;
    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
    constexpr u64 &value() noexcept { return a; }
    constexpr const u64 &value() const noexcept { return a; }
    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }
    constexpr modint operator^(const u64 rhs) const noexcept {
        return modint(*this) ^= rhs;
    }
    constexpr modint &operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept {
        if (a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint &operator/=(modint rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
    constexpr modint &operator^=(u64 exp) {
        modint rhs = modint(*this);
        a = 1;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
};
using mint = modint<MOD>;
vector<mint> f, fi;
void comb(int n) {
    f.resize(n + 1);
    fi.resize(n + 1);
    f[0] = 1;
    for (ll i = 1; i <= n; i++) {
        f[i] = f[i - 1] * mint(i);
    }
    fi[n] = mint(1) / f[n];
    for (ll i = n - 1; i >= 0; i--) {
        fi[i] = fi[i + 1] * mint(i + 1LL);
    }
}
mint ncr(ll n, ll r) {
    if (n < r) {
        return mint(0);
    }
    if (r == 0) {
        return mint(1);
    }
    return f[n] * fi[n - r] * fi[r];
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<mint>> dp(n + 1, vector<mint>(s + 1));
    dp[0][0] = 1;
    mint res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            if (j == a[i]) {
                dp[i + 1][j] += dp[i][0] * (i + 1LL);
            } else if (j > a[i]) {
                dp[i + 1][j] += dp[i][j - a[i]];
            }
            dp[i + 1][j] += dp[i][j];
        }
        res += dp[i + 1][s];
    }
    cout << res.a << endl;
}