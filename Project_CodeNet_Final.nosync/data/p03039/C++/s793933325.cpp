#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
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
int main(){
    ll n,m,k;cin>>n>>m>>k;
    mint ans=0;
    combination c(220000);
    rep(i,m){
        ans+=i*(m-i)*n*n;
    }
    rep(i,n){
        ans+=i*(n-i)*m*m;
    }
    ans*=c(n*m-2,k-2);
    cout<<ans.x<<endl;
    return 0;
}