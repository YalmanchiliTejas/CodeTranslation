#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858    (129)
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize    (130)
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division    (133)
const int mod = 1000000007;

struct mint {
  ll x;
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

// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&feature=youtu.be&t=1619       (133)
struct combination {//nCkを求めている(二項係数を計算する関数)
  vector<mint> fact, ifact;//階乗と階乗の逆元
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);//これがないと落ちる(式が真であることを表明する)
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();//逆元(nCk=(n+k)!/(n)!(k)!)
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;//これで階乗の逆元が求まっているらしい
  }
  mint operator()(int n, int k) {//nCk=n!/k!(n-K)!のmod版
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
};

int main() {
  int N,M,K;
  cin >> N >> M >> K;
  combination ans = combination(N*M-2);
  mint co=ans(N*M-2,K-2);
  ll n=(ll)N,m=(ll)M;
  ll ans1=0ll;
  ll MOD = (ll)mod;
  for(ll i=0ll;i<n;i++) {ans1+=((i*(n-i))%MOD * (m*m)%MOD)%MOD;ans1=ans1%MOD;}
  for(ll i=0ll;i<m;i++) {ans1+=((i*(m-i))%MOD * (n*n)%MOD)%MOD;ans1=ans1%MOD;}
  mint ANS(ans1);
  ANS *= co;
  cout << ANS << endl;
  return 0;
}