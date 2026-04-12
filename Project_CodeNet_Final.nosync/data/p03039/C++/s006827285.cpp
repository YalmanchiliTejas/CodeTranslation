#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll inf=1000000000000000000;
#define rep(i,m,n) for(int i=m;i<n;i++)
#define rrep(i,n,m) for(int i=n;i>=m;i--)
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll gya[200010];
ll kai[200010];
ll beki(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k%2==1){
            ret*=now;
            ret%=mod;
        }
        now*=now;
        now%=mod;
        k/=2;
    }
    return ret;
}
ll gyaku(ll n){
    return beki(n,mod-2);
}
void nckinit(ll n){
    kai[0]=1;
    kai[1]=1;
    for(int i=2;i<=n;i++){
        kai[i]=kai[i-1]*i;
        kai[i]%=mod;
    }
    gya[n]=gyaku(kai[n]);
    for(int i=n-1;i>=1;i--){
        gya[i]=gya[i+1]*i;
        gya[i]%=mod;
    }
    gya[0]=1;
}
ll nck(ll n,ll k){
    if(k<0)return 0;
    if(k==0||n==k)return 1;
    ll ret=1;
    rep(i,0,k){
        ret*=(n-i);
        ret%=mod;
        ret*=gyaku(i+1);
        ret%=mod;
    }
    return ret;
}
ll npk(ll n,ll k){
    if(k<0)return 0;
    if(k==0)return 1;
    ll ret=kai[n];
    ret*=gya[n-k];
    ret%=mod;
    return ret;
}
int main(){
    ll n,m,k;cin>>n>>m>>k;
    nckinit(200010);
    ll ans=n*n*(m*(m-1)*(m+1))/3+m*m*(n*(n-1)*(n+1))/3;
    ans%=mod;
    //cout<<ans<<endl;
    ans*=nck(n*m-2,k-2);
    //cout<<nck(20,2)<<endl;
    ans%=mod;
    //cout<<ans<<endl;
    ans*=gyaku(2);
    ans%=mod;
    cout<<ans<<endl;
}
