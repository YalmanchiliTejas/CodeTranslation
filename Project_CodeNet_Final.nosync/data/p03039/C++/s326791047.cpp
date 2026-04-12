#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
//https://drken1215.hatenablog.com/entry/2019/06/15/111500
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
 mint& operator*=(const mint a) {
(x *= a.x) %= mod;
return *this;
}
mint operator+(const mint a) const {
mint res(*this);
return res+=a;
}
mint operator-(const mint a) const {
mint res(*this);
return res-=a;
}
 mint operator*(const mint a) const {
mint res(*this);
return res*=a;
}
mint pow(ll t) const {
if (!t) return 1;
mint a = pow(t>>1);
a *= a;
if (t&1) a *= *this;
return a;
}
 mint inv() const {
return pow(mod-2);
 }
  mint& operator/=(const mint a) {
return (*this) *= a.inv();
 }
mint operator/(const mint a) const {
mint res(*this);
return res/=a;
 }
};
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
  };
int main() {
ios::sync_with_stdio(false);
cin.tie(0);
ll n,m,k;
cin>>n>>m>>k;
combination c(n*m-2);
mint ans=0;
rep(i,n)rep(j,m){
    mint cur=mint(n-i)*mint(m-j)*mint(i+j);
    if(i*j!=0)cur*=2;
    ans+=cur;
}
ans*=c(n*m-2,k-2);
cout<<ans.x<<endl;

return 0;
}