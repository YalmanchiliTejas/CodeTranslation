#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph= vector<vector<int>>; 
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define fi first 
#define se second
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
// ミント
const int mod = 1e9+7 ;
  //998244353;

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
//昆布
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
  mint p(int n,int k){
    return fact[n]*ifact[n-k] ;
  }
  }  c(4000005);
 
mint modpow(ll a,ll b){
 if(b==0) return 1 ;
 mint c= modpow(a,b/2) ;
 if(b%2==1) return c*c*a ;
 else return c*c ;
}

mint komb(ll n,ll m){
  mint x=1 ;mint y=1 ;
  rep(i,m){
    x*= n-i ;
    y*= i+1 ;
  }
  return x/y ;
}

 map<ll,ll> factor(ll n){  //素因数とオーダーをマップで管理
  map <ll,ll> ord ;  
  for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            int res=0;
            while(n%i==0){
                n/=i;
                res++;
            }
            ord[i]=res;
        }
    }
   if(n!=1) ord[n]++;
   return ord ;
 }
 
  
 
int main(){
   ll n; cin>>n ;
   vector<ll> A(n) ;
   rep(i,n) cin>>A[i] ;
   mint sum=0ll ;
   rep(i,n) sum+=mint(A[i]) ;
   mint ans= sum*sum ;
   rep(i,n){
     ans-= mint(A[i]*A[i]) ;
   }

   mint bns= ans/mint(2) ;
   cout<<bns<<endl ;

     return 0;
  }
   

