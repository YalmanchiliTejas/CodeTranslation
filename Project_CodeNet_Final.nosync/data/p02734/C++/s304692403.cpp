#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dump(...)
#endif
#define endl '\n'
//#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((int)(x)); i > 0; i--)
#define INF 2147483647
#define LLINF 9223372036854775807LL
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define BIT(n) (1LL << (n))
#define TOUPPER(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define TOLOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define FILLZERO(s, n)                      \
    do {                                    \
        ostringstream os;                   \
        os << setw(n) << setfill('0') << s; \
        s = os.str();                       \
    } while (0);
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてからつかうこと
#define INIT                               \
    std::cin.tie(nullptr);                 \
    std::ios_base::sync_with_stdio(false); \
    cout << std::fixed << std::setprecision(10);

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pi = pair<int, int>;
template <typename T>
using Pq = priority_queue<T>;
template <typename T>
using pQ = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
vector<T> make_vec(size_t a, T n) { return vector<T>(a, n); }
template <typename T, typename... Ts>
auto make_vec(size_t a, Ts... ts) { return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...)); }
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec)
        is >> x;
    return is;
}

constexpr ll MOD = 1e9 + 7;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
ll A, B, C, D, E, F, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;
ll ans = 0;

class Fp {
public:
    ll val;
    static ll mod;

    Fp() { val = 0; }
    Fp(ll v) : val(v % mod) {
        if (val < 0)
            val += mod;
    }
    Fp operator+=(const Fp &in) {
        val += in.val;
        calc_mod(val);
        return *this;
    }
    Fp operator+(const Fp &in) const {
        return Fp(*this) += in;
    }
    Fp &operator-=(const Fp &in) {
        val -= in.val;
        calc_mod(val);
        if (val < 0)
            val += mod;
        return *this;
    }
    Fp operator-(const Fp &in) const {
        return Fp(*this) -= in;
    }
    Fp &operator*=(const Fp &in) {
        val = val * in.val % mod;
        return *this;
    }
    Fp operator*(const Fp &in) const {
        return Fp(*this) *= in;
    }
    Fp &operator/=(const Fp &in) {
        *this *= in.modpow(mod - 2);
        return *this;
    }
    Fp operator/(const Fp &in) const {
        return Fp(*this) /= in;
    }
    bool operator==(const Fp &in) const {
        return val == in.val;
    }
    bool operator!=(const Fp &in) const {
        return val != in.val;
    }
    Fp modpow(ll n) const {
        if (n == 0)
            return 1;
        if (n & 1) {
            return (*this) * ((*this) * (*this)).modpow(n / 2);
        } else {
            return ((*this) * (*this)).modpow(n / 2);
        }
    }
    friend istream &operator>>(istream &is, Fp &fp) {
        is >> fp.val;
        return is;
    }
    friend ostream &operator<<(ostream &os, Fp &fp) {
        os << fp.val;
        return os;
    }
    friend ostream &operator<<(ostream &os, Fp &&fp) {
        os << fp.val;
        return os;
    }

private:
    void calc_mod(ll &v) {
        if (v >= mod)
            v -= mod;
    }
};

Fp modpow(const Fp &in, const ll n) {
    return in.modpow(n);
}
Fp modpow(const ll a, const ll n) {
    return Fp(a).modpow(n);
}

using mint = Fp;
ll mint::mod = MOD;

class Factorial {
public:
    vector<mint> fact, finv;
    Factorial(ll n) : fact(n + 1, mint(1)), finv(n + 1, mint(1)) {
        for (int i = 2; i <= n; i++) {
            mint tmp(i);
            fact[i] = fact[i - 1] * tmp;
            finv[i] = finv[i - 1] / tmp;
        }
    }
    mint perm(const ll &n, const ll &k) {
        return fact[n] * finv[n - k];
    }
    mint com(const ll &n, const ll &k) {
        if (n < k || n < 0 || k < 0)
            return mint(0);
        return fact[n] * finv[k] * finv[n - k];
    }
};

int main() {
    INIT;
    cin >> N >> K;
    vi a(N);
    cin >> a;
    mint::mod = 998244353;
    auto dp = make_vec<mint>(N + 1, K + 1, mint(0));
    mint ans = 0;
    dp[0][0] = 1;
    REP(i, N) {
        REP(j, K + 1) {
            dp[i + 1][j] += dp[i][j];
            if (j + a[i] <= K) {
                if (j == 0) {
                    dp[i + 1][j + a[i]] += dp[i][j] * (i + 1);
                } else
                    dp[i + 1][j + a[i]] += dp[i][j];
            }
        }
        ans += dp[i + 1][K];
    }
    cout << ans << endl;
}