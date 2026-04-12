#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll mod = 1e9 + 7;

template <typename T> inline bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> inline bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

template <int M> class ModInt {
    int x;

  public:
    ModInt() : x(0) {}
    ModInt(int64_t y) : x(y >= 0 ? y % M : (M - (-y) % M) % M) {}
    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= M) x -= M;
        return *this;
    }
    ModInt &operator-=(const ModInt &p) {
        if((x += M - p.x) >= M) x -= M;
        return *this;
    }
    ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
    ModInt inverse() const {
        int a = x, b = M, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }
    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while(n > 0) {
            if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }
    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt(t);
        return (is);
    }
};
using modint = ModInt<mod>;

vector<ll> fact, fact_inv;

template <typename T> T mpow(T x, T n) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n = n >> 1;
    }
    return ret;
}

void COMinit(const ll MAX) {
    fact.resize(MAX + 1);
    fact_inv.resize(MAX + 1);
    fact[0] = 1;
    rep(i, MAX) fact[i + 1] = fact[i] * (i + 1) % mod;
    fact_inv[MAX] = mpow(fact[MAX], mod - 2);
    for(int i = MAX; i; i--)
        fact_inv[i - 1] = fact_inv[i] * i % mod;
}

ll COM(const ll n, const ll k) {
    if(n < k || k < 0) return 0;
    return (fact[n] * fact_inv[k] % mod) * fact_inv[n - k] % mod;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;
    COMinit(N * M);

    modint ans;

    rep(i, N) rep(j, M) {
        modint x((N - i) * (M - j) * (i + j));
        if(i && j) x *= 2;
        ans += x;
    }

    cout << ans * COM(N * M - 2, K - 2) << endl;

    return 0;
}