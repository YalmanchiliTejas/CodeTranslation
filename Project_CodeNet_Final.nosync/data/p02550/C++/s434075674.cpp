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
private:
    long long val;

public:
    static long long mod;

    Fp() { val = 0; }
    Fp(long long v) : val(v % mod) {
        if (val < 0)
            val += mod;
    }
    ll getVal() { return val; }
    Fp operator+=(const Fp &in) {
        val += in.val;
        if (val >= mod)
            val -= mod;
        return *this;
    }
    Fp operator+(const Fp &in) const {
        return Fp(*this) += in;
    }
    Fp &operator-=(const Fp &in) {
        val -= in.val;
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
    friend Fp operator*(const long long n, const Fp &in) {
        return in * n;
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
    Fp modpow(long long n) const {
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
};

Fp modpow(const Fp &in, const long long n) {
    return in.modpow(n);
}
Fp modpow(const ll a, const long long n) {
    return Fp(a).modpow(n);
}

using mint = Fp;
long long mint::mod = MOD;

class Factorial {
public:
    vector<mint> fact, finv;
    Factorial(long long n) : fact(n + 1, mint(1)), finv(n + 1, mint(1)) {
        for (int i = 2; i <= n; i++) {
            mint tmp(i);
            fact[i] = fact[i - 1] * tmp;
            finv[i] = finv[i - 1] / tmp;
        }
    }
    mint perm(const long long n, const long long k) {
        return fact[n] * finv[n - k];
    }
    mint com(const long long n, const long long k) {
        if (n < k || n < 0 || k < 0)
            return mint(0);
        return fact[n] * finv[k] * finv[n - k];
    }
};

signed main() {
    INIT;
    cin >> N >> X >> M;
    mint::mod = M;
    vi mem(M);
    vector<mint> v;
    mint now = X;
    while (!mem[now.getVal()]) {
        v.push_back(now);
        mem[now.getVal()] = 1;
        now *= now;
    }
    int start = 0;
    REP(i, v.size()) {
        if (v[i] == now.getVal()) {
            start = i;
            break;
        }
    }
    if (N <= start) {
        REP(i, N) {
            ans += v[i].getVal();
        }
    } else {
        N -= start;
        REP(i, start) {
            ans += v[i].getVal();
        }
        ll sum = 0;
        vector<mint> vv(v.begin() + start, v.end());
        REP(i, vv.size()) {
            sum += vv[i].getVal();
        }
        ll n = N / vv.size();
        ll amari = N % vv.size();
        REP(i, amari) {
            ans += vv[i].getVal();
        }
        ans += sum * n;
    }
    cout << ans << endl;
}