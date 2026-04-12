#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 998244353;
const ll LINF = 1e18;
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
struct modint {
    ll x;
    constexpr modint(ll x = 0) : x((x % MOD + MOD) % MOD) {
    }
    ll value() const {
        return x;
    }
    constexpr modint operator-() const {
        return modint(-x);
    }
    constexpr modint& operator+=(const modint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    constexpr modint& operator-=(const modint a) {
        if ((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }
    constexpr modint& operator*=(const modint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    constexpr modint operator+(const modint a) const {
        modint res(*this);
        return res += a;
    }
    constexpr modint operator-(const modint a) const {
        modint res(*this);
        return res -= a;
    }
    constexpr modint operator*(const modint a) const {
        modint res(*this);
        return res *= a;
    }
    constexpr modint pow(ll t) const {
        if (t == 0) return 1;
        modint a = pow(t >> 1);
        a *= a;
        if (t % 2 == 1) a *= *this;
        return a;
    }
    constexpr modint inv() const {
        return pow(MOD - 2);
    }
    constexpr modint& operator/=(const modint a) {
        return (*this) *= a.inv();
    }
    constexpr modint operator/(const modint a) const {
        modint res(*this);
        return res /= a;
    }
};

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    auto dp = make_vec<modint>(3300, 3300, 3);
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i + 1][j][0] += dp[i][j][0];
            dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1];
            dp[i + 1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];

            if (j - a[i] >= 0) {
                dp[i + 1][j][1] += dp[i][j - a[i]][0] + dp[i][j - a[i]][1];
                dp[i + 1][j][2] += dp[i][j - a[i]][0] + dp[i][j - a[i]][1];
            }
        }
    }
    cout << dp[n][s][2].value() << endl;
}