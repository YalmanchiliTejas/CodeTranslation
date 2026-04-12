#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD;
#define INF 2*1e9
#define N 3100
using namespace std;

ll modpow(ll x,ll n){
    if(n==0) return 1;
    ll res=modpow(x*x%MOD,n/2);
    if(n&1) res=res*x%MOD;
    return res;
}
ll modpow2(ll x,ll n){
    if(n==0) return 1;
    ll res=modpow2(x*x%(MOD-1),n/2);
    if(n&1) res=res*x%(MOD-1);
    return res;
}
ll modpow3(ll x,ll n){
    return modpow(x,modpow2(x,n));
}
ll inv[4000],comb[4000];
void calc_inv(){
    inv[1]=1;
    rep2(i,2,N){
        inv[i]=((-(MOD/i)*inv[MOD%i])%MOD+MOD)%MOD;
    }
    return;
}
void calc_comb(ll int n){
    comb[0]=1;
    rep2(i,1,n){
        comb[i]=comb[i-1]*(ll)(n+1-i)%MOD*inv[i]%MOD;
    }
    return;
}
void add(ll *x,ll y){
    *x=(*x+y%MOD+MOD)%MOD;return;
}
void subtract(ll *x,ll y){
    *x=(*x+MOD-(y%MOD))%MOD;
}
main(){
    ll n;
    cin>>n>>MOD;
    ll dp[N][N]={};
    dp[1][0]=1;
    dp[1][1]=1;
    rep2(i,1,n-1){
        rep2(j,0,i){
            add(&dp[i+1][j],dp[i][j]*(ll)(j+1));
            add(&dp[i+1][j+1],dp[i][j]);
        }
    }
    ll ans=0;
    calc_inv();calc_comb(n);
    ans=modpow3(2,n);
    ll s=-1;
    rep2(i,1,n){
        ll t=comb[i]*modpow3(2,n-i)%MOD*s;
        t=(t+MOD)%MOD;
        rep(j,i+1){
            add(&ans,t*dp[i][j]);
            t=t*modpow(2,n-i)%MOD;
        }
        s*=-1;
    }
    cout<<ans;
    return 0;
}