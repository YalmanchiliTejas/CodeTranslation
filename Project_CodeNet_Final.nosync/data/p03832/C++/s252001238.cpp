#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

// mod int struct
// original : https://github.com/beet-aizu/library/blob/master/mod/mint.cpp

struct mint {
    ll v;
    ll mod;
    mint() : v(0) {}
    mint(signed v, ll mod = MOD) : v(v), mod(mod) {}
    mint(ll t, ll mod = MOD) : mod(mod) {
        v = t % mod;
        if (v < 0)
            v += mod;
    }

    mint pow(ll k) {
        mint res(1), tmp(v);
        while (k) {
            if (k & 1)
                res *= tmp;
            tmp *= tmp;
            k >>= 1;
        }
        return res;
    }

    static mint add_identity() { return mint(0); }
    static mint mul_identity() { return mint(1); }

    mint inv() { return pow(mod - 2); }

    mint &operator+=(mint a) {
        v += a.v;
        if (v >= mod)
            v -= mod;
        return *this;
    }
    mint &operator-=(mint a) {
        v += mod - a.v;
        if (v >= mod)
            v -= mod;
        return *this;
    }
    mint &operator*=(mint a) {
        v = 1LL * v * a.v % mod;
        return *this;
    }
    mint &operator/=(mint a) { return (*this) *= a.inv(); }

    mint operator+(mint a) const { return mint(v) += a; };
    mint operator-(mint a) const { return mint(v) -= a; };
    mint operator*(mint a) const { return mint(v) *= a; };
    mint operator/(mint a) const { return mint(v) /= a; };

    mint operator-() const { return v ? mint(mod - v) : mint(v); }

    bool operator==(const mint a) const { return v == a.v; }
    bool operator!=(const mint a) const { return v != a.v; }
    bool operator<(const mint a) const { return v < a.v; }

    // find x s.t. a^x = b
    static ll log(ll a, ll b) {
        const ll sq = 40000;
        unordered_map<ll, ll> dp;
        dp.reserve(sq);
        mint res(1);
        for (int r = 0; r < sq; r++) {
            if (!dp.count(res.v))
                dp[res.v] = r;
            res *= a;
        }
        mint p = mint(a).inv().pow(sq);
        res    = b;
        for (int q = 0; q <= MOD / sq + 1; q++) {
            if (dp.count(res.v)) {
                ll idx = q * sq + dp[res.v];
                if (idx > 0)
                    return idx;
            }
            res *= p;
        }
        assert(0);
        return ll(-1);
    }

    static mint comb(long long n, int k) {
        mint num(1), dom(1);
        for (int i = 0; i < k; i++) {
            num *= mint(n - i);
            dom *= mint(i + 1);
        }
        return num / dom;
    }
};
ostream &operator<<(ostream &os, mint m) {
    os << m.v;
    return os;
}

struct Combination {
    vector<ll> fac, finv, inv;

    Combination(ll maxN) {
        maxN += 100; // for safety
        fac.resize(maxN + 1);
        finv.resize(maxN + 1);
        inv.resize(maxN + 1);
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1]            = 1;
        for (ll i = 2; i <= maxN; ++i) {
            fac[i]  = fac[i - 1] * i % MOD;
            inv[i]  = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }
    ll operator()(ll n, ll k) {
        if (n < k)
            return 0;
        if (n < 0 || k < 0)
            return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
};

template <typename T>
struct Factorial {
    vector<T> facto;
    Factorial(T maxi) : facto(maxi + 1, 1) {
        for (int i = 2; i <= maxi; ++i) {
            facto[i] = facto[i - 1] * i % MOD;
        }
    }
    T operator()(T n) { return facto[n]; }
};

int main() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    vector<vector<mint>> dp(n + 1, vector<mint>(b + 1, 0));
    Combination nCk(n);
    Factorial<ll> facto(n);
    for (int i = 0; i <= b; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = a; j <= b; ++j) {
            dp[i][j] = dp[i][j - 1];
            for (int k = c; k <= d; ++k) {
                ll prev = i - j * k;
                if (prev >= 0) {
                    dp[i][j] +=
                        dp[prev][j - 1] * nCk(n - prev, j * k) * facto(j * k) / mint(facto(j)).pow(k) / facto(k);
                } else {
                    break;
                }
            }
        }
    }
    cout << dp[n][b] << "\n";
    return 0;
}