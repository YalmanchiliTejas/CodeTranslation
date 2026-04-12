#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
//Combination
long long extGCD(long long a,long long mod,long long &x,long long &y){
    if(mod==0){
        x=1;
        y=0;
        return a;
    }
    long long d=extGCD(mod,a%mod,y,x);
    y-=(a/mod)*x;
    return d;
}
long long invmod(long long a,long long mod){
    long long x,y;
    extGCD(a,mod,x,y);
    x%=mod;
    if(x<0)x+=mod;
    return x;
}
ll fac[2000010],finv[2000010],inv[2000010];
void combinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    REP(i,2,2000010){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=invmod(i,mod);
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}
ll comb(ll n,ll k){
    if(n<k)return 0;
    if(n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}
ll rui(ll a,ll b){
    ll res=1;
    ll x=a;
    while(b){
        if(b&1)res=res*x%inf;
        x=x*x%inf;
        b/=2;
    }
    return res;
}
signed main(){
    ll n,a,b,c,d;cin>>n>>a>>b>>c>>d;
    ll m=b-a+1;
    vector<vector<ll> > dp(m+1,vector<ll>(n+1));
    combinit();
    vector<ll>kai(1010);
    kai[0]=1;
    REP(i,1,1010){
        kai[i]=kai[i-1]*i%inf;
    }
    dp[0][0]=1;
    rep(i,m){
        ll x=a+i;
        rep(j,n+1){
            dp[i+1][j]=(dp[i+1][j]+dp[i][j])%inf;
            ll now=dp[i][j];
            REP(k,1,d+1){
                if(k*x+j>n)break;
                now=now*comb(n-j-(k-1)*x,x)%inf;
                if(k>=c)dp[i+1][j+k*x]=(dp[i+1][j+k*x]+now*rui(kai[k],inf-2)%inf)%inf;
            }
            //cout<<dp[i][j]<<' ';
        }
        //cout<<endl;
    }
    rep(i,n+1){
        //cout<<dp[m][i]<<' ';
    }
    //cout<<endl;
    ll ans=dp[m][n];
    if(ans<0)ans+=inf;
    cout<<ans<<endl;
}