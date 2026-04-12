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
ll MOD=1e9+7;
#define INF 2*1e9
#define N 1100000
using namespace std;
ll int inv[N],comb[N],fact[N],factinv[N];
void calc_inv(){
    inv[1]=1;
    rep2(i,2,N){
        inv[i]=((-(MOD/i)*inv[MOD%i])%MOD+MOD)%MOD;
    }
    return;
}
ll modpow(ll x,ll n){
    if(n==0) return 1;
    ll res=modpow(x*x%MOD,n/2);
    if(n&1) res=res*x%MOD;
    return res;
}
ll inverse(int x){
    if(x<N&&inv[x]) return inv[x];
    if(x<N) return inv[x]=modpow(x,MOD-2);
    return modpow(x,MOD-2);
}
void calc_comb(ll int n){
    comb[0]=1;
    rep2(i,1,n){
        comb[i]=comb[i-1]*(n+1-i)*inv[i]%MOD;
    }
    return;
}
ll int combination(int a,int b){
    ll int ans=1;
    rep2(i,1,b){
        ans=ans*(a+1-i)*inv[i]%MOD;
    }
    return ans;
}
void calc_fact(int n){
    fact[0]=fact[1]=1;
    factinv[0]=factinv[1]=1;
    rep2(i,2,n){
        fact[i]=fact[i-1]*i%MOD;
        factinv[i]=factinv[i-1]*inv[i]%MOD;
    }
}
void add(ll* x,int y){
    *x=(*x+y)%MOD;
}
void product(ll *x,ll y){
    *x=(*x*y)%MOD;
}
void add2(ll *x,int y,int n,int i,int j){
    ll ans=fact[n];
    product(&ans,factinv[n-i*j]);
    product(&ans,modpow(factinv[i],j));
    product(&ans,factinv[j]);
    *x=(*x+ans*y)%MOD;
}
main(){
    ll dp[1100][1100]={};
    calc_inv();
    calc_fact(1000);
    int n,a,b,c,d;cin>>n>>a>>b>>c>>d;
    dp[a-1][n]=1;
    rep2(i,a,b){
        dp[i][0]=dp[i-1][0];
        rep2(k,i,n){
            add(&dp[i][k],dp[i-1][k]);
            int j=c;
            while((k-j*i>=i||k-j*i==0)&&j<=d){
                add2(&dp[i][k-j*i],dp[i-1][k],k,i,j);
                j++;
            }
        }
    }
    cout<<dp[b][0];return 0;
}