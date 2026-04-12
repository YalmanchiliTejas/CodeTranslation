// 6/20 解き直し
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

const int mod = 998244353;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

mint dp[3010][3010][4];

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    // dp初期化
    rep(i, n + 1) {
        rep(j, s + 1) {
            rep(k, 3) {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][0] = 1;

    rep(i, n) {
        for (int j = 0; j <= s; j++) {
            // A[i]を使わない場合
            // dp[i + 1][j] += dp[i][j] * 2;
            // if (j >= a[i]) dp[i+1][j] += dp[i][j-a[i]];

            // L, Rが決まっていない時
            dp[i+1][j][0] += dp[i][j][0];

            // Lが決まっている時
            dp[i+1][j][1] += (dp[i][j][0] + dp[i][j][1]);

            // L, Rが決まっている時
            dp[i+1][j][2] += (dp[i][j][1] + dp[i][j][2]);

            // a[i]を使う時
            if (j >= a[i]) {
                dp[i+1][j][1] += (dp[i][j-a[i]][0] + dp[i][j-a[i]][1]);
                dp[i+1][j][2] += (dp[i][j-a[i]][0] + dp[i][j-a[i]][1]);  // L=Rもあるので、0, 1両方から遷移する
            }
        }
    }

    cout << dp[n][s][2] << endl;
}