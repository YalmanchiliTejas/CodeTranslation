#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const int INF = 1 << 28;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

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

    mint operator-() const { return v ? mint(MOD - v) : mint(v); }

    bool operator==(const mint a) const { return v == a.v; }
    bool operator!=(const mint a) const { return v != a.v; }
    bool operator<(const mint a) const { return v < a.v; }
};

int main() {
    string k;
    cin >> k;
    int d;
    cin >> d;
    int n = k.size();
    vector<vector<mint>> dp1(n + 1, vector<mint>(d, 0));
    vector<vector<mint>> dp2(n + 1, vector<mint>(d, 0));
    dp1[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        int ki = stoi(k.substr(i, 1));
        for (int j = 0; j < d; ++j) {
            dp1[i + 1][(j + ki) % d] += dp1[i][j];
            for (int k = 0; k < ki; ++k) {
                dp2[i + 1][(j + k) % d] += dp1[i][j];
            }
            for (int k = 0; k < 10; ++k) {
                dp2[i + 1][(j + k) % d] += dp2[i][j];
            }
        }
    }
    mint ret = dp1[n][0] + dp2[n][0] - mint(1);
    cout << ret.v << "\n";
    return 0;
}