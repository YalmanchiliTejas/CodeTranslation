#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template <typename T> using V = vector<T>;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

template <int M> class ModInt {
    int x;

  public:
    constexpr ModInt() : x(0) {}
    constexpr ModInt(int64_t y) : x(y >= 0 ? y % M : (M - (-y) % M) % M) {}
    constexpr ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= M) x -= M;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &p) {
        if((x += M - p.x) >= M) x -= M;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % M);
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }
    constexpr ModInt operator-() const { return ModInt(-x); }
    constexpr ModInt operator+(const ModInt &p) const {
        return ModInt(*this) += p;
    }
    constexpr ModInt operator-(const ModInt &p) const {
        return ModInt(*this) -= p;
    }
    constexpr ModInt operator*(const ModInt &p) const {
        return ModInt(*this) *= p;
    }
    constexpr ModInt operator/(const ModInt &p) const {
        return ModInt(*this) /= p;
    }
    constexpr bool operator==(const ModInt &p) const { return x == p.x; }
    constexpr bool operator!=(const ModInt &p) const { return x != p.x; }
    constexpr ModInt inverse() const {
        int a = x, b = M, u = 1, v = 0, t = 0;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }
    constexpr ModInt pow(const int64_t &n) const {
        ModInt ret(1), mul(x);
        int64_t k = n % (M - 1);
        while(k > 0) {
            if(k & 1) ret *= mul;
            mul *= mul;
            k >>= 1;
        }
        return ret;
    }
    constexpr friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }
    constexpr friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t = 0;
        is >> t;
        a = ModInt(t);
        return (is);
    }
};
using modint = ModInt<mod>;

// 組み合わせ、階乗逆元
vector<modint> fact, fact_inv;

void COMinit(const ll &MAX) {
    fact.resize(MAX + 1);
    fact_inv.resize(MAX + 1);
    fact[0] = 1;
    rep(i, MAX) fact[i + 1] = fact[i] * (i + 1);
    fact_inv[MAX] = fact[MAX].inverse();
    for(int i = MAX; i; i--)
        fact_inv[i - 1] = fact_inv[i] * i;
}

modint COM(const ll &n, const ll &k) {
    if(n < k || k < 0) return 0;
    return fact[n] * fact_inv[k] * fact_inv[n - k];
}

modint HCOM(const int &P, const int &Q) {
    return (P == 0 && Q == 0) ? 1 : COM(P + Q - 1, Q);
}

modint permutation(const int &n, const int &k) {
    if(n < k || k < 0) return 0;
    return fact[n] * fact_inv[n - k];
}

modint dp[1100][1100];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    COMinit(N);
    dp[A][0] = 1;
    FOR(i, A, B + 1) rep(j, N + 1) {
        dp[i + 1][j] += dp[i][j];
        FOR(k, C, D + 1) {
            if(i * k > j) break;
            dp[i + 1][j] += dp[i][j - i * k] *
                            permutation(N - j + i * k, i * k) * fact_inv[k] *
                            fact_inv[i].pow(k);
        }
    }
    cout << dp[B + 1][N] << endl;

    return 0;
}