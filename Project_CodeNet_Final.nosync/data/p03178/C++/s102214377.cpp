#include <iostream>
#include <string>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll=long long;

// mint
const int mod = 1e9 + 7;
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
//istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main(int argc, const char * argv[]) {
    string A;
    cin >> A;
    ll n = A.length();
    int d;
    cin >> d;
    mint dp[n+1][2][d+1]; // dp[桁][Aより小さいことが1:確定 0:未定][mod d]
    dp[0][0][0]=1;
    for(ll i=0;i<n;i++){
        rep (j, 2)rep(l,d) {
            int lim=9;
            if (j==0) lim=A[i]-'0';
            rep (now, lim + 1) {
                dp[i + 1][j || now < lim][(l+now)%d] += dp[i][j][l];
            }
        }
    }
    mint ans= -1;
    rep (j, 2)rep(l,d) if(l==0) ans+=dp[n][j][l];
    cout << ans << endl;
    return 0;
}
