#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}

    mint operator-() const { return mint(-x); }

    mint &operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }

    mint &operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }

    mint &operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }

    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }

    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }

    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }

    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(mod - 2);
    }

    mint &operator/=(const mint a) {
        return (*this) *= a.inv();
    }

    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }
};

mint dp[10010][2][101];

int main() {
    string K;
    int D;
    cin >> K >> D;
    dp[0][0][0] = 1;
    rep(i, K.size()) {
        rep(k, D) {
            int cur = K[i] - '0';
            int nd = (k + cur) % D;
            dp[i + 1][0][nd] += dp[i][0][k];

            rep(d, cur) {
                nd = (k + d) % D;
                dp[i + 1][1][nd] += dp[i][0][k];
            }

            rep(d, 10) {
                nd = (k + d) % D;
                dp[i + 1][1][nd] += dp[i][1][k];
            }
        }
    }

//    rep(i, K.size() + 1) {
//        rep(j, 2) {
//            cout << "i:" << i << " j:" << j << endl;
//            rep(k, D) cout << dp[i][j][k].x  << " ";
//            cout << endl;
//        }
//        cout << "----------" << endl;
//    }
    cout << (dp[K.size()][0][0] + dp[K.size()][1][0] - 1).x << endl;
}
