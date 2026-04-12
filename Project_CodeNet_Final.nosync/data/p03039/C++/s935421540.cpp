

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF=1e18;


// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;

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


// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&feature=youtu.be&t=1619
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
}comb(200005);


//nPk
 mint f(int n, int k) {
    if (n < 0) return 0;
    // nPk = nCk * k!
    mint res = comb(n,k);
    res *= comb.fact[k];
    return res;
}




//組み合わせの数nCrを計算
   int calcNumOfCombination(int n, int r){
       int num = 1;
       for(int i = 1; i <= r; i++){
           num = num * (n - i + 1) / i;
       }
       return num;
   }




int main() {
  ll n,m,k;
  cin >> n >> m >>k;
  mint ans=0;
  for(ll i=1;i<n;i++){
  //  cout<<"i"<<i<<endl;
    mint c=comb(n*m-2,k-2);
    mint c1=(n-i)*m;
    c1*=m;
    c*=c1;
    c*=i;
    //cout<<c<<endl;
    ans+=c;
  }
  for(ll i=1;i<m;i++){
  //  cout<<"i"<<i<<endl;

    mint c=comb(n*m-2,k-2);
    mint c1=(m-i)*n;
    c1*=n;
    c*=c1;
    c*=i;
    ans+=c;
  //  cout<<c<<endl;

  }
  cout<<ans;
}
