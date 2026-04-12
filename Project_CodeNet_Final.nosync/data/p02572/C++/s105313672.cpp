#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> P;
typedef string str;
typedef vector<P> vp;
typedef vector<string> vs;
typedef vector<bool> vb;

const ll mod=1e9+7;
const ll inf=1e16;

#define rep(i,m,n) for(ll i=m;i<n;i++)
#define repr(i,m,n) for(ll i=m-1;i>=n;i--)
#define fi first
#define se second
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define eb(x) emplace_back(x)
#define pb(x) pop_back(x)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define sum(x) accumulate(all(x),0)
#define pc(x) __builtin_popcount(x)
#define gll greater<ll>()
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
 
ll modpow(ll a,ll n){
 long long pow=1;
  while(n){
   if(n&1) pow=pow*a%mod;
   a=a*a%mod;
   n>>=1;    
}  
 return pow;
}

//a^(-1)

ll modinv(ll a){
 return modpow(a,mod-2);
}

void solve(){
  ll n;
  cin >> n;
  vll a(n);
  mint  s=0;
  rep(i,0,n) {
    cin >> a[i];
    s+=a[i];
  }
  s*=s;
  
  rep(i,0,n) s-=a[i]*a[i];


  s*=modinv(2);
  
 cout << s << endl;
}
int main(){
   cin.tie(nullptr);
  ios::sync_with_stdio(false);
  solve();
}
