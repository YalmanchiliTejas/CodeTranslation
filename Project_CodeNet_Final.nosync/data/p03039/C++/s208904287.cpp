#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define FORI(i,v) for (auto i = v.begin(); i != v.end(); i++)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)

template<int mod> struct ModInt {
    int64_t x;
    ModInt() : x(0) {}
    ModInt(int64_t y) : x(y >= 0 ? y % mod : (y % mod + mod) % mod) {}

    ModInt &operator+=(const ModInt &a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &a) {
        x = 1LL * x * a.x % mod;
        return *this;
    }

    ModInt &operator/=(const ModInt &a) {
        *this *= a.inverse();
        return *this;
    }

    ModInt operator-() const {
        return ModInt(-x);
    }

    ModInt operator+(const ModInt a) const {
        return ModInt(*this) += a;
    }

    ModInt operator-(const ModInt a) const {
        return ModInt(*this) -= a;
    }

    ModInt operator*(const ModInt a) const {
        return ModInt(*this) *= a;
    }

    ModInt operator/(const ModInt a) const {
        return ModInt(*this) /= a;
    }

    bool operator==(const ModInt a) const {
        return x == a.x;
    }

    bool operator!=(const ModInt a) const {
        return x != a.x;
    }

    ModInt pow(int64_t k) const {
        ModInt ret(1), mul(x);
        while (k > 0) {
            if (k & 1) ret *= mul;
            mul *= mul;
            k >>= 1;
        }
        return ret;
    }

    ModInt inverse() const {
        return pow(mod - 2);
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }
};

const int MOD = 1e9+7;
using modint = ModInt<MOD>;

const int MAX = 2e5+10;

modint fac[MAX<<2];
modint finv[MAX<<2];
modint inv_[MAX<<2];

void init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv_[1] = 1;
    FOR (i, 2, MAX<<2) {
        fac[i] = fac[i-1]*modint(i);
        inv_[i] = -inv_[MOD%i]*modint(MOD/i);
        finv[i] = finv[i-1]*inv_[i];
    }
}

modint nCk (int n, int k) {
    if (n < k || k < 0 || n < 0) return 0;
    return fac[n]*finv[k]*finv[n-k];
}

modint comb(int n, int k) {
    modint ret(1);
    FOR (i, 1, k+1) ret *= i;
    ret = ret.inverse();
    FOR (i, n-k+1, n+1) ret *= i;
    return ret;
}

modint nHk (int n, int k) {
    return nCk(n-1+k, n-1);
}

ll N, M, K;

modint sub(ll h, ll w) {
    modint ret(0);
    REP (d, w) {
        ret += modint(d) * modint(w-d) * modint(h).pow(2) * nCk(h*w-2, K-2);
    }
    return ret;
}

modint solve() {
    init();
    return sub(N, M) + sub(M, N);
}

int main() {
    cin >> N >> M >> K;
    cout << solve() << endl;
}