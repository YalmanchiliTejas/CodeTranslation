#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int inf = 1e9;
constexpr ll linf = 1e18;

template <ll mod> class modint
{
private:
    ll x;

public:
    modint(ll x = 0) : x(x >= 0 ? x % mod : (x % mod) + mod) {}
    modint &operator+=(const modint rhs) {
        if ((x += rhs.x) >= mod) x -= mod;
        return *this;
    }
    modint &operator-=(const modint rhs) {
        if ((x += mod - rhs.x) >= mod) x -= mod;
        return *this;
    }
    modint &operator*=(const modint rhs) {
        (x *= rhs.x) %= mod;
        return *this;
    }
    modint &operator/=(const modint rhs) {
        *this *= rhs.inv();
        return *this;
    }
    modint operator+(const modint rhs) const { return modint(*this) += rhs; }
    modint operator-(const modint rhs) const { return modint(*this) -= rhs; }
    modint operator*(const modint rhs) const { return modint(*this) *= rhs; }
    modint operator/(const modint rhs) const { return modint(*this) /= rhs; }

    modint operator-() const { return modint(-x); }

    modint pow(ll n) const {
        modint e = *this, ret = modint(1);
        while (n) {
            if (n & 1) ret *= e;
            e *= e, n >>= 1;
        }
        return ret;
    }

    modint inv() const { return pow(mod - 2); }

    friend ostream &operator<<(ostream &os, const modint &m) {
        os << m.x;
        return os;
    }

    friend istream &operator>>(istream &is, modint &m) {
        ll in;
        is >> in;
        m = modint(in);
        return is;
    }
};
using mint = modint<1000000007>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s; cin >> s;
    int D; cin >> D;
    const int n = s.length();

    mint dp[n + 1][D][2] = {};
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        int nd = s[i] - '0';
        for (int j = 0; j < D; j++) {
            for (int k = 0; k < 2; k++) {
                for (int d = 0; d <= (k ? 9 : nd); d++) {
                    dp[i + 1][(j + d) % D][k || (d < nd)] += dp[i][j][k];
                } 
            }
        }
    }

    mint ans = dp[n][0][0] + dp[n][0][1] - 1;

    cout << ans << endl;
    return 0;
}