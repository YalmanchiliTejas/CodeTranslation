#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#include <chrono>
#include <random>
#include <time.h>
#include <fstream>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define all(c) begin(c),end(c)
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
void print(vec v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}
ll MOD=998244353;
#define N 11000000

ll int inv[N],comb[N],prd[N],invprd[N];
void calc_inv(){
    inv[1]=1;
    rep2(i,2,N-1){
        inv[i]=((-(MOD/i)*inv[MOD%i])%MOD+MOD)%MOD;
    }
    return;
}
void calc_comb(ll int n){
    comb[0]=1;
    rep2(i,1,n){
        comb[i]=comb[i-1]*(n+1-i)*inv[i]%MOD;
    }
    return;
}
void calc_product(){
    prd[0]=prd[1]=1;
    invprd[0]=invprd[1]=1;
    rep2(i,2,N-1){
        prd[i]=i*prd[i-1]%MOD;
        invprd[i]=inv[i]*invprd[i-1]%MOD;
    }
    return ;
}
ll cmb(int a,int b){
    if(a<b)return 0;
    if(a<0||b<0)return 0;
    return prd[a]*invprd[b]%MOD*invprd[a-b]%MOD;
}
ll modpow(ll x,ll n){
    if(n==0) return 1;
    ll res=modpow(x*x%MOD,n/2);
    if(n&1) res=res*x%MOD;
    return res;
}
ll p[N+100],a[N],b[N];
main(){
    calc_inv();
    calc_product();
    p[0]=1;
    rep(i,N){
      p[i+1]=p[i]*2ll%MOD;
    }
    ll n=in();
    rep(i,n/2+1){
      a[i]=p[i]*cmb(n/2,i)%MOD;
      //cout<<a[i]<<endl;
    }
    ll t=0;
    ll ans=1;
    rep(i,n)ans=ans*3ll%MOD;
    rep(i,n/2){
      t=(t+a[i])%MOD;
      ans=(ans+MOD-t*a[n/2-1-i]%MOD*2ll%MOD)%MOD;
    }
    cout<<ans<<endl;
}
