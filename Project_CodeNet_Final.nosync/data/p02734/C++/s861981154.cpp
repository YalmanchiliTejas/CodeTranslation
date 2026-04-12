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

const int MOD = 998244353;
using modint = ModInt<MOD>;

const int MAX = 3e3+10;

int N, S, A[MAX];

modint dp[MAX][MAX];

modint solve() {
    dp[0][0] = modint(1);

    REP (i, N) {
        dp[i+1][0] += 1;
        REP (k, S+1) {
            dp[i+1][k] += dp[i][k];
            if (k >= A[i]) dp[i+1][k] += dp[i][k-A[i]];
        }
    }

    modint ans(0);
    FOR (i, 1, N+1) ans += dp[i][S];
    return ans;
}

int main() {
    cin >> N >> S;
    REP (i, N) cin >> A[i];
    cout << solve() << endl;
}