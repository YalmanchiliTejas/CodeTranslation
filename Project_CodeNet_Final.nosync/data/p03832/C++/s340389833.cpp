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
#define rt(i, n) (i == n - 1 ? rt : sp)
#define len(x) ((ll)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define ifn(x) if (not(x))
#define elif else if
#define elifn else ifn
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
            rep(_j, w) {                                                       \
                if (abs(a[_i][_j]) >= INF / 2 and a[_i][_j] <= -INF / 2)       \
                    cerr << '-';                                               \
                if (abs(a[_i][_j]) >= INF / 2)                                 \
                    cerr << "∞" << sp;                                         \
                else                                                           \
                    cerr << a[_i][_j] << sp;                                   \
            }                                                                  \
            cerr << rt;                                                        \
        }                                                                      \
        cerr << "]" << rt;                                                     \
    }

#define vdump(a, n)                                                            \
    {                                                                          \
        cerr << __LINE__ << ": " << #a << " = [";                              \
        rep(_i, n) {                                                           \
            if (_i) cerr << sp;                                                \
            if (abs(a[_i]) >= INF / 2 and a[_i] <= -INF / 2) cerr << '-';      \
            if (abs(a[_i]) >= INF / 2)                                         \
                cerr << "∞" << sp;                                             \
            else                                                               \
                cerr << a[_i];                                                 \
        }                                                                      \
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
#pragma GCC optimize("Ofast,unroll-loops")
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

const ll mo = 1e9 + 7;
struct mint {
    ll x;
    mint(ll x = 0) : x((x % mo + mo) % mo) {}
    mint operator-() const { return mint(-x); }
    mint &operator+=(const mint &a) {
        if ((x += a.x) >= mo) x -= mo;
        return *this;
    }
    mint &operator-=(const mint &a) {
        if ((x += mo - a.x) >= mo) x -= mo;
        return *this;
    }
    mint &operator*=(const mint &a) {
        (x *= a.x) %= mo;
        return *this;
    }
    mint operator+(const mint &a) const { return mint(*this) += a; }
    mint operator-(const mint &a) const { return mint(*this) -= a; }
    mint operator*(const mint &a) const { return mint(*this) *= a; }
    bool operator==(const mint &a) const { return x == a.x; }
    bool operator!=(const mint &a) const { return x != a.x; }
    bool operator<=(const mint &a) { return x <= a.x; }
    bool operator<(const mint &a) { return x < a.x; }
    friend ll abs(const mint &a) { return a.x; }

    friend mint pow(const mint &a, ll n) {
        if (!n) return 1;
        mint b = pow(a, n >> 1);
        b *= b;
        if (n & 1) b *= a;
        return b;
    }

    mint inv() const { return pow(*this, mo - 2); }
    mint &operator/=(mint a) { return (*this) *= a.inv(); }
    mint operator/(mint a) const { return mint(*this) /= a; }

    friend istream &operator>>(istream &is, mint &a) {
        ll t;
        is >> t;
        a = mint(t);
        return is;
    }
    friend ostream &operator<<(ostream &os, mint a) {
        os << a.x;
        return os;
    }
};
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wliteral-suffix"
mint operator"" M(const ull n) { return mint(n); }
#pragma GCC diagnostic pop

struct modmath {
    vector<mint> fac, inv;

    modmath(ll n = 1 << 20) : fac(n + 1), inv(n + 1) {
        fac[0] = 1;
        rep(i, n) fac[i + 1] = fac[i] * (i + 1);
        inv[n] = fac[n].inv();
        dec(i, n - 1, 0) inv[i] = inv[i + 1] * (i + 1);
    }

    mint F(ll n) {
        if (n < 0) return 0;
        return fac[n];
    }
    mint P(ll n, ll r) {
        if (r < 0 || n < r || n < 0) return 0;
        return fac[n] * inv[n - r];
    }
    mint C(ll n, ll r) {
        if (r < 0 || n < r || n < 0) return 0;
        return fac[n] * inv[r] * inv[n - r];
    }
    mint c(ll n) {
        if (n < 0) return 0;
        return fac[2 * n] * inv[n] * inv[n + 1];
    }
    mint H(ll n, ll r) { return C(n + r - 1, n - 1); }
} math;

signed main() {
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    mint DP[B - A + 2][N + 1];
    DP[0][N] = 1;
    dec(i, B, A) {
        inc(j, C, D) {
            inc(k, i * j, N) {
                mint p = math.C(k, i * j) * math.fac[i * j] *
                         pow(math.inv[i], j) * math.inv[j];
                DP[B + 1 - i][k - i * j] += DP[B - i][k] * p;
            }
        }
        rep(j, N + 1) DP[B + 1 - i][j] += DP[B - i][j];
    }
    cout << DP[B - A + 1][0] << rt;
}
