#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<l_l> vpl;
typedef vector<string> vs;
typedef pair<l_l,ll> lll;
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=1;i<=(n);i++)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=10100100100100100;
const ll dx[4]={1,-1,0,0};
const ll dy[4]={0,0,1,-1};
template<class T> inline bool chmin(T& a,T b){
if(a>b){
a=b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a,T b){
if(a<b){
a=b;
return true;
}
return false;
}
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
mint dp[10010][101][2];
int main(){
    string s;cin>>s;
    ll n=sz(s);
    ll d;cin>>d;
    dp[0][0][1]=1;
    rep(i,n){
        ll now=s[i]-'0';
        rep(j,d){
            rep(k,10){
                dp[i+1][(j+k)%d][0]+=dp[i][j][0];
                if(k<now)dp[i+1][(j+k)%d][0]+=dp[i][j][1];
            }
            dp[i+1][(j+now)%d][1]+=dp[i][j][1];
        }
    }
    mint ans=dp[n][0][0]+dp[n][0][1];
    ans-=1;
    cout<<ans.x<<endl;
    return 0;
}