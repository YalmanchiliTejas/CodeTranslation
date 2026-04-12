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
        if(k < 0) k += M - 1;
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
using modint = ModInt<Mod>;

modint dp[3030][3030][3];
int a[3030];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, s;
    cin >> n >> s;
    rep(i, n) cin >> a[i];
    dp[0][0][0] = 1;
    rep(i, n) rep(j, s + 1) {
        dp[i + 1][j][0] += dp[i][j][0];
        dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1];
        dp[i + 1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
        if(j + a[i] <= s) {
            dp[i + 1][j + a[i]][1] += dp[i][j][0] + dp[i][j][1];
            dp[i + 1][j + a[i]][2] += dp[i][j][0] + dp[i][j][1];
        }
    }
    cout << dp[n][s][2] << endl;

    return 0;
}