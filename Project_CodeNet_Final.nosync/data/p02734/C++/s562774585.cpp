#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;
// auto mod int
const int mod = 998244353;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {if ((x += a.x) >= mod) x -= mod; return *this;}
  mint& operator-=(const mint a) {if ((x += mod-a.x) >= mod) x -= mod; return *this;}
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


int main() {
  int n,s;
  cin >> n >> s;

  mint ans;
  vector<mint> dp(s+1);
  rep(_,n){
    int a;
    cin >> a;
    dp[0] += 1;
    vector<mint> temp(s+1);
    rep(i,s+1){
      temp[i] += dp[i];
      if(i+a<=s) temp[i+a] += dp[i];
    }
    dp = temp;
    ans += dp[s];
  }
  cout << ans << endl;
}
