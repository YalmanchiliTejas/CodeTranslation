#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <functional>
#include <cstring>
#include <regex>
#include <random>
#include <cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define revrepr(i, s, n) for (int i = (n) - 1; i >= s; i--)
#define debug(x) cerr << #x << ": " << x << "\n"
#define popcnt(x) __builtin_popcount(x)

using ll = long long;
using P = pair<int, int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

template<class T>
istream& operator >>(istream &is, vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) cin >> v.at(i);
    return is;
}

template<class T, class U>
ostream& operator <<(ostream &os, pair<T, U> p) {
    cout << '(' << p.first << ", " << p.second << ')';
    return os;
}

template<class T>
void print(const vector<T> &v, const string &delimiter) { rep(i, v.size()) cout << (0 < i ? delimiter : "") << v.at(i); cout << endl; }

template<class T>
void print(const vector<vector<T>> &vv, const string &delimiter) { for (const auto &v: vv) print(v, delimiter); }

#include <cstdint>
template <std::uint_fast64_t Modulus>
class modint {
    using u64 = std::uint_fast64_t;

public:
    using value_type = u64;

    static constexpr u64 mod = Modulus;

private:
    static_assert(mod < static_cast<u64>(1) << 32,
                  "Modulus must be less than 2**32");

    u64 v;

    constexpr modint &negate() noexcept {
        if (v != 0) v = mod - v;
        return *this;
    }

public:
    constexpr modint(const u64 x = 0) noexcept : v(x % mod) {}
    constexpr u64 &value() noexcept { return v; }
    constexpr const u64 &value() const noexcept { return v; }
    constexpr modint operator+() const noexcept { return modint(*this); }
    constexpr modint operator-() const noexcept {
        return modint(*this).negate();
    }
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
    constexpr modint &operator+=(const modint rhs) noexcept {
        v += rhs.v;
        if (v >= mod) v -= mod;
        return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept {
        if (v < rhs.v) v += mod;
        v -= rhs.v;
        return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept {
        v = v * rhs.v % mod;
        return *this;
    }
    constexpr modint &operator/=(modint rhs) noexcept {
        u64 exp = mod - 2;
        while (exp != 0) {
            if (exp % 2 != 0) *this *= rhs;
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
};
template <std::uint_fast64_t Modulus>
constexpr typename modint<Modulus>::u64 modint<Modulus>::mod;

modint<998244353> dp[3001][3001][3];

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    cin >> a;

    dp[0][0][0] = 1;
    rep(i, n) rep(x, s + 1) {
        rep(t, 3) dp[i + 1][x][t] += dp[i][x][t];
        rep(t, 2) dp[i + 1][x][t + 1] += dp[i][x][t];
        dp[i + 1][x][2] += dp[i][x][0];
        if (x + a[i] <= s) {
            rep(t, 2) dp[i + 1][x + a[i]][t + 1] += dp[i][x][t];
            dp[i + 1][x + a[i]][1] += dp[i][x][1];
            dp[i + 1][x + a[i]][2] += dp[i][x][0];
        }
    }
    cout << dp[n][s][2].value() << endl;
}