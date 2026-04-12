#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

static const long long mod = 1000000007;
struct mint {
  long long x;
  mint(ll x = 0):x(x%mod) {}
  mint& operator+=(const mint a) {
    (x += a.x) %= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    (x += mod-a.x) %= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint ret(*this);
    return ret += a;
  }
  mint operator-(const mint a) const {
    mint ret(*this);
    return ret -= a;
  }
  mint operator*(const mint a) const {
    mint ret(*this);
    return ret *= a;
  }
  mint pow(ll t) const {
    if(t==0) return mint(1);
    mint a = pow(t>>1);
    a *= a;
    if(t&1) a *= *this;
    return a;
  }
  
  //for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint ret(*this);
    return ret /= a;
  }
};
ostream &operator<<(ostream& os, const mint& x) {
  os << x.x;
  return os;
}
class modutils {
  vector<mint> fact, invfact;
public:
  modutils(int n = 200005):fact(n+1),invfact(n+1) {
    fact[0] = 1;
    for(int i=1; i<=n; i++) fact[i] = fact[i-1] * i;
    invfact[n] = fact[n].inv();
    for(int i=n; i>=1; i--) invfact[i-1] = invfact[i] * i;
  }
  mint pow(mint x, ll n) {
    return x.pow(n);
  }
  mint comb(ll n, ll k) {
    if(n<0 || k<0 || n<k) return 0;
    return fact[n] * invfact[k] * invfact[n-k];
  }
  mint perm(ll n, ll k) {
    if(n<0 || k<0 || n<k) return 0;
    return fact[n] * invfact[n-k];
  }
  mint fac(ll n) {
    return fact[n];
  }
};
modutils mutil;


int main(){
  ll N, M, K;
  cin >> N >> M >> K;

  mint X = 0, Y = 0, Z = 0;
  rep(i,N){
    X += (i * (N-i)) % mod;
  }
  X *= M;
  X *= M-1;

  {
    mint base = 0;
    rep(i,N-1){
      base += i+1;
      Y += base;
    }
  }
  Y *= M;
  {
    mint base = 0;
    rep(i,M-1){
      base += i+1;
      Z += base;
    }
  }

  mint W = mutil.comb(N*M-2, K-2);

  mint NN = N*N;
  
  mint ret = (Y + Z * NN + X) * W;
  //cout << Y << " " << Z << " " << NN << " " << X << " " << W << endl;
  cout << ret << endl;
  
  return 0;
}

