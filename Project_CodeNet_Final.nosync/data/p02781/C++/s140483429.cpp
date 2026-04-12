#include <bits/stdc++.h>
using namespace std;

// Define
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <class T> using pvector = vector<pair<T, T>>;
template <class T>
using rpriority_queue = priority_queue<T, vector<T>, greater<T>>;
constexpr const ll dx[4] = {1, 0, -1, 0};
constexpr const ll dy[4] = {0, 1, 0, -1};
constexpr const ll MOD = 1e9 + 7;
constexpr const ll mod = 998244353;
constexpr const ll INF = 1LL << 60;
constexpr const ll inf = 1 << 30;
constexpr const char rt = '\n';
constexpr const char sp = ' ';
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define elif else if
#define all(a, v, ...)                                                         \
    ([&](decltype((v)) w) { return (a)(begin(w), end(w), ##__VA_ARGS__); })(v)
#define rall(a, v, ...)                                                        \
    ([&](decltype((v)) w) { return (a)(rbegin(w), rend(w), ##__VA_ARGS__); })(v)
#define fi first
#define se second

template <class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

// Debug
#define debug(...)                                                             \
    {                                                                          \
        cerr << __LINE__ << ": " << #__VA_ARGS__ << " = ";                     \
        for (auto &&X : {__VA_ARGS__}) cerr << "[" << X << "] ";               \
        cerr << rt;                                                            \
    }

#define dump(a, h, w)                                                          \
    {                                                                          \
        cerr << __LINE__ << ": " << #a << " = [" << rt;                        \
        rep(_i, h) {                                                           \
            rep(_j, w) cerr << a[_i][_j] << sp;                                \
            cerr << rt;                                                        \
        }                                                                      \
        cerr << "]" << rt;                                                     \
    }

#define vdump(a, n)                                                            \
    {                                                                          \
        cerr << __LINE__ << ": " << #a << " = [";                              \
        rep(_i, n) if (_i) cerr << sp << a[_i];                                \
        else cerr << a[_i];                                                    \
        cerr << "]" << rt;                                                     \
    }

// Loop
#define inc(i, a, n) for (ll i = (a), _##i = (n); i <= _##i; ++i)
#define dec(i, a, n) for (ll i = (a), _##i = (n); i >= _##i; --i)
#define rep(i, n) for (ll i = 0, _##i = (n); i < _##i; ++i)
#define each(i, a) for (auto &&i : a)

// Stream
#define fout(n) cout << fixed << setprecision(n)
struct io {
    io() { cin.tie(nullptr), ios::sync_with_stdio(false); }
} io;

// Speed
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

// Math
inline constexpr ll gcd(const ll a, const ll b) {
    return b ? gcd(b, a % b) : a;
}
inline constexpr ll lcm(const ll a, const ll b) { return a / gcd(a, b) * b; }

inline constexpr ll modulo(const ll n, const ll m = MOD) {
    ll k = n % m;
    return k + m * (k < 0);
}
inline constexpr ll chmod(ll &n, const ll m = MOD) {
    n %= m;
    return n += m * (n < 0);
}
inline constexpr ll mpow(ll a, ll n, const ll m = MOD) {
    ll r = 1;
    rep(i, 64) {
        if (n & (1LL << i)) r *= a;
        chmod(r, m);
        a *= a;
        chmod(a, m);
    }
    return r;
}
inline ll inv(const ll n, const ll m = MOD) {
    ll a = n, b = m, x = 1, y = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        x -= t * y;
        swap(x, y);
    }
    return modulo(x, m);
}

template <ull mod = MOD> struct mi {
    inline constexpr ll modulo(const ll n, const ll m) const noexcept {
        ll k = n % m;
        return k + m * (k < 0);
    }

    ll num;
    inline constexpr mi() noexcept : num() { num = 0; }
    inline constexpr mi(const int n) noexcept : num() { num = modulo(n, mod); }
    inline constexpr mi(const ll n) noexcept : num() { num = modulo(n, mod); }

    inline constexpr mi<mod> inv() const noexcept {
        ll a = num, b = mod, x = 1, y = 0;
        while (b) {
            ll t = a / b;
            a -= t * b;
            swap(a, b);
            x -= t * y;
            swap(x, y);
        }
        return mi<mod>(x);
    }
    inline constexpr mi<mod> inv(ll n) const noexcept {
        ll a = n, b = mod, x = 1, y = 0;
        while (b) {
            ll t = a / b;
            a -= t * b;
            swap(a, b);
            x -= t * y;
            swap(x, y);
        }
        return mi<mod>(x);
    }
    inline constexpr mi<mod> inv(const mi<mod> m) const noexcept {
        return inv(m.num);
    }

    inline constexpr mi<mod> operator+() const noexcept { return mi(num); }
    inline constexpr mi<mod> operator+(const int n) const noexcept {
        return mi<mod>(num + n);
    }
    inline constexpr mi<mod> operator+(const ll n) const noexcept {
        return mi<mod>(num + n);
    }
    inline constexpr mi<mod> operator+(const mi<mod> m) const noexcept {
        return mi<mod>(num + m.num);
    }
    inline constexpr mi<mod> operator-() const noexcept { return -num; }
    inline constexpr mi<mod> operator-(const int n) const noexcept {
        return mi<mod>(num - n);
    }
    inline constexpr mi<mod> operator-(const ll n) const noexcept {
        return mi<mod>(num - n);
    }
    inline constexpr mi<mod> operator-(const mi<mod> m) const noexcept {
        return mi<mod>(num - m.num);
    }
    inline constexpr mi<mod> operator*(const int n) const noexcept {
        return mi<mod>(num * n);
    }
    inline constexpr mi<mod> operator*(const ll n) const noexcept {
        return mi<mod>(num * n);
    }
    inline constexpr mi<mod> operator*(const mi<mod> m) const noexcept {
        return mi<mod>(num * m);
    }
    inline constexpr mi<mod> operator/(const int n) const noexcept {
        return mi<mod>(num * (ll) inv(n));
    }
    inline constexpr mi<mod> operator/(const ll n) const noexcept {
        return mi<mod>(num * (ll) inv(n));
    }
    inline constexpr mi<mod> operator/(const mi<mod> m) const noexcept {
        return mi<mod>(num * (ll) inv(m));
    }
    inline constexpr mi<mod> &operator=(const int n) noexcept {
        num = modulo(n, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator=(const ll n) noexcept {
        num = modulo(n, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator=(const mi<mod> m) noexcept {
        num = m.num;
        return *this;
    }
    inline constexpr mi<mod> &operator+=(const int n) noexcept {
        num = modulo(num + n, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator+=(const ll n) noexcept {
        num = modulo(num + n, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator+=(const mi<mod> m) noexcept {
        num = modulo(num + m.num, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator++() noexcept {
        num = modulo(num + 1, mod);
        return *this;
    }
    inline constexpr mi<mod> operator++(int) noexcept {
        mi &pre = *this;
        num = modulo(num + 1, mod);
        return pre;
    }
    inline constexpr mi<mod> &operator-=(const int n) noexcept {
        num = modulo(num - n, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator-=(const ll n) noexcept {
        num = modulo(num - n, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator-=(const mi<mod> m) noexcept {
        num = modulo(num - m.num, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator--() noexcept {
        num = modulo(num - 1, mod);
        return *this;
    }
    inline constexpr mi<mod> operator--(int) noexcept {
        mi &pre = *this;
        num = modulo(num - 1, mod);
        return pre;
    }
    inline constexpr mi<mod> &operator*=(const int n) noexcept {
        num = modulo(num * n, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator*=(const ll n) noexcept {
        num = modulo(num * n, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator*=(const mi<mod> m) noexcept {
        num = modulo(num * m.num, mod);
        return *this;
    }
    inline constexpr mi<mod> &operator/=(const int n) noexcept {
        num = modulo(num * (ll) inv(n), mod);
        return *this;
    }
    inline constexpr mi<mod> &operator/=(const ll n) noexcept {
        num = modulo(num * (ll) inv(n), mod);
        return *this;
    }
    inline constexpr mi<mod> &operator/=(const mi<mod> m) noexcept {
        num = modulo(num * (ll) inv(m), mod);
        return *this;
    }
    inline constexpr bool operator==(const int n) const noexcept {
        return num == modulo(n, mod);
    }
    inline constexpr bool operator==(const ll n) const noexcept {
        return num == modulo(n, mod);
    }
    inline constexpr bool operator==(const mi<mod> m) const noexcept {
        return num == m.num;
    }
    inline constexpr bool operator!=(const int n) const noexcept {
        return num != modulo(n, mod);
    }
    inline constexpr bool operator!=(const ll n) const noexcept {
        return num != modulo(n, mod);
    }
    inline constexpr bool operator!=(const mi<mod> m) const noexcept {
        return num != m.num;
    }
    constexpr operator int() const noexcept { return num; }
    constexpr operator ll() const noexcept { return num; }
    friend std::istream &operator>>(std::istream &, const mi<> &);
    friend std::ostream &operator<<(std::ostream &, const mi<> &);
};

template <ull mod = MOD>
inline constexpr mi<mod> operator+(const int n, const mi<mod> m) noexcept {
    return mi<mod>(n + m.num);
}
template <ull mod = MOD>
inline constexpr mi<mod> operator+(const ll n, const mi<mod> m) noexcept {
    return mi<mod>(n + m.num);
}
template <ull mod = MOD>
inline constexpr mi<mod> operator-(const int n, const mi<mod> m) noexcept {
    return mi<mod>(n - m.num);
}
template <ull mod = MOD>
inline constexpr mi<mod> operator-(const ll n, const mi<mod> m) noexcept {
    return mi<mod>(n - m.num);
}
template <ull mod = MOD>
inline constexpr mi<mod> operator*(const int n, const mi<mod> m) noexcept {
    return mi<mod>(n * m.num);
}
template <ull mod = MOD>
inline constexpr mi<mod> operator*(const ll n, const mi<mod> m) noexcept {
    return mi<mod>(n * m.num);
}
template <ull mod = MOD>
inline constexpr mi<mod> operator/(const int n, const mi<mod> m) noexcept {
    return mi<mod>(n * (ll) m.inv());
}
template <ull mod = MOD>
inline constexpr mi<mod> operator/(const ll n, const mi<mod> m) noexcept {
    return mi<mod>(n * (ll) m.inv());
}
inline constexpr mi<MOD> operator""_m(ull n) { return mi<MOD>((ll) n); }

template <ull mod = MOD>
inline constexpr mi<mod> pow(mi<mod> m, ll n) noexcept {
    mi<mod> r = mi<mod>(1);
    rep(i, 64) {
        if (n & (1LL << i)) r *= m;
        m *= m;
    }
    return r;
}
template <ull mod> istream &operator>>(istream &is, mi<mod> &m) {
    is >> m.num;
    return is;
}
template <ull mod> ostream &operator<<(ostream &is, mi<mod> &m) {
    is << (ll) m;
    return is;
}

signed main() {
    string S;
    ll K;
    cin >> S >> K;
    ll N = S.size(), DP[N + 1][K + 1][2];
    rep(i, N + 1) rep(j, K + 1) rep(k, 2) DP[i][j][k] = 0;
    DP[0][0][0] = 1;
    rep(i, N) rep(j, K + 1) rep(k, 10) {
        ll D = S[i] - '0';
        if (D == k and j + (k != 0) <= K) {
            DP[i + 1][j + (k != 0)][0] += DP[i][j][0];
            DP[i + 1][j + (k != 0)][1] += DP[i][j][1];
        }
        if (D > k and j + (k != 0) <= K) {
            DP[i + 1][j + (k != 0)][1] += DP[i][j][0];
            DP[i + 1][j + (k != 0)][1] += DP[i][j][1];
        }
        if (D < k and j + (k != 0) <= K) {
            DP[i + 1][j + (k != 0)][1] += DP[i][j][1];
        }
    }
    cout << DP[N][K][0] + DP[N][K][1] << rt;
}

// -g -D_GLIBCXX_DEBUG -fsanitize=undefined
