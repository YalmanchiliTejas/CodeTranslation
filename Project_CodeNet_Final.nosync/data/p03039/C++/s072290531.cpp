#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=1e9+7;
ll extGCD(long long a,long long mod,long long &x,long long &y){
    if(mod==0){
        x=1;
        y=0;
        return a;
    }
    ll d=extGCD(mod,a%mod,y,x);
    y-=(a/mod)*x;
    return d;
}
ll invmod(long long a,long long mod){
    long long x,y;
    extGCD(a,mod,x,y);
    x%=mod;
    if(x<0)x+=mod;
    return x;
}
ll fac[200010],finv[200010],inv[200010];
void combinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    REP(i,2,200010){
        fac[i]=fac[i-1]*i%inf;
        inv[i]=invmod(i,inf);
        finv[i]=finv[i-1]*inv[i]%inf;
    }
}
ll comb(ll n,ll k){
    if(n<k)return 0;
    if(n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%inf)%inf;
}
int main(){
    combinit();
    ll n,m,k;cin>>n>>m>>k;
    ll d=comb(n*m-2,k-2)%inf;
    ll cntn=0,cntm=0;
    REP(i,1,n+1)cntn=(cntn+(2*i-n-1)%inf*i%inf)%inf;
    REP(i,1,m+1)cntm=(cntm+(2*i-m-1)%inf*i%inf)%inf;
    ll ans=((m*m%inf)*d%inf*cntn%inf+(n*d%inf)*n%inf*cntm%inf)%inf;
    cout<<ans<<endl;
}