#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
const int mx=200010;
const ll mod=1e9+7;

//snuke
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint& operator+=(const mint a) { if ((x += a.x) >= mod) x -= mod; return *this; }
  mint& operator-=(const mint a) { if ((x += mod-a.x) >= mod) x -= mod; return *this; }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
  mint operator+(const mint a) const { mint res(*this); return res+=a; }
  mint operator-(const mint a) const { mint res(*this); return res-=a; }
  mint operator*(const mint a) const { mint res(*this); return res*=a; }
  mint pow(ll t) const { if (!t) return 1; mint a = pow(t>>1); a *= a; if (t&1) a *= *this; return a; }
  // for prime mod
  mint inv() const { return pow(mod-2); }
  mint& operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const { mint res(*this); return res/=a; }
}; 

vector<ll> inv,fact,invfact;
void mod_build(int n){  
  fact.resize(n+1); inv.resize(n+1); invfact.resize(n+1);
  fact[0]=inv[0]=invfact[0]=1; inv[1]=1;
  rep(i,n){
    fact[i+1]=fact[i]*(i+1)%mod;
    if(i>0)inv[i+1]=mod-inv[mod%(i+1)]*(mod/(i+1))%mod;
    invfact[i+1]=invfact[i]*inv[i+1]%mod;
  }
}
ll perm(int n,int k){ if(n<0||k<0||k>n){ return 0; } else { return fact[n]*invfact[n-k]%mod; } }
ll comb(int n,int k){ if(n<0||k<0||k>n){ return 0; } else { return (fact[n]*invfact[n-k]%mod)*invfact[k]%mod; }}
ll powmod(ll n,ll k){
  k%=mod-1; if(k<0)k+=mod-1;
  ll ret=1; while(k){ if(k&1)ret=ret*n%mod; n=n*n%mod; k>>=1; }
  return ret;
}

int main(){  
  mod_build(201010);
  ll n,m,k;
  cin >> n >> m >> k;
  
  mint ans=0;
  rep(i,m){ ans += i*(m-i)*n*n; }
  ans *= comb(n*m-2,k-2);
  
  mint tmp=0;
  rep(i,n){ tmp += i*(n-i)*m*m; }
  tmp *= comb(n*m-2,k-2);
  
  ans += tmp;

  cout << ans.x << endl;
  return 0;
}