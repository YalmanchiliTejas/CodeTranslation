#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

// auto mod int
const int mod = 1000000007;
// const int mod = 998244353;
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
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

mint dp[10010][2][110];
string K;
int D;

int main() {
    cin >> K >> D;
    int klen = K.length();
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    for(int i = 0; i < klen; ++i) {
        int limit = K.at(i) - '0';
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k < D; ++k) {
                for(int d = 0; d <= (j ? 9 : limit); ++d) {
                    dp[i+1][j || (d<limit)][(k+d)%D] += dp[i][j][k];
                }
            }
        }
    }

    mint ans = dp[klen][0][0] + dp[klen][1][0];
    ans -= (mint)1;
    cout << ans << endl;
}