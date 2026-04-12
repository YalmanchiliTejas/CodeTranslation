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
typedef pair<l_l,ll> lll;
typedef vector<string> vs;
const ll dx[4]={1,-1,0,0};
const ll dy[4]={0,0,1,-1};
#define pb push_back
#define sz(x) (int)(x).size()
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
int main(){
    ll n,m;cin>>n>>m;
    vector<ll> dp1(n+1,LINF),dp2(n+1,LINF);
    vector<mint> patS(n+1),patT(n+1);
    ll s,t;cin>>s>>t;
    dp1[s]=0;dp2[t]=0;
    vector<l_l> g[n+1];
    rep(i,m){
        ll u,v,d;cin>>u>>v>>d;
        g[u].pb({v,d});
        g[v].pb({u,d});
    }
    auto dijkstra=[&](ll st,vector<ll> &dp,vector<mint> &pat){
        priority_queue<l_l,vector<l_l>,greater<l_l>> pq;
        pq.push({0,st});
        dp[st]=0;
        pat[st]=1;
        ll nowp,nowd;
        while(sz(pq)){
            tie(nowd,nowp)=pq.top();pq.pop();
            if(dp[nowp]<nowd)continue;
            //cout<<nowp<<" "<<nowd<<endl;
            for(auto next:g[nowp]){
                ll nextp=next.fi,nextd=next.se+nowd;
                if(dp[nextp]>nextd){
                    dp[nextp]=nextd;
                    pat[nextp]=pat[nowp];
                    pq.push({nextd,nextp});
                }else if(dp[nextp]==nextd){
                    pat[nextp]+=pat[nowp];
                }
            }
        }
    };
    dijkstra(s,dp1,patS);
    dijkstra(t,dp2,patT);
    ll len=dp1[t];
    mint ans=patS[t]*patT[s];
    rrep(i,n){
        for(auto p:g[i]){
            int j=p.fi,c=p.se;
            if(len==dp1[i]+dp2[j]+c){
                if(dp1[i]*2<len&&dp2[j]*2<len) ans-=patS[i]*patT[j]*patS[i]*patT[j];
            }
        }
    }
    rrep(i,n){
        if(dp1[i]+dp2[i]==len&&dp1[i]*2==len){
            ans-=patS[i]*patT[i]*patS[i]*patT[i];
        }
    }
    cout<<ans.x<<endl;
    return 0;
}