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
void print(vecll v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}


#define INF 1e9+7
#define LLINF 1e18+7
#define N 2500000
ll MOD=1e9+7;

ll modpow(ll a,ll n){
    if(n%2) return a*modpow(a*a%MOD,n/2)%MOD;
    else if(n==0) return 1ll;
    else modpow(a*a%MOD,n/2);
}

main(){
    ll n=in();
    vecll v;
    v.pb(1);
    rep(i,n)v.pb(in());
    vecll w=v;
    sort(all(w));
    vecll dp2;
    dp2.pb(0);dp2.pb(0);
    ll dp1=1;
    map<int,int> mp;
    vecll rev(n+2);
    int now=1;
    rep(i,n+1){
        if(mp[w[i]]==0) {
            mp[w[i]]=now;
            rev[now]=w[i];
            now++;
        }
    }
    rep(i,n){
        vecll newdp2(n+2);
        int a=mp[v[i]],b=mp[v[i+1]];
        if(v[i]<=v[i+1]){
            rep2(j,1,a){
                dp2[j]=(dp2[j]*modpow(2,v[i+1]-v[i]))%MOD;
            }
            rep2(j,a+1,b){
                dp2.pb(dp1*2%MOD*(modpow(2,v[i+1]-rev[j-1])-modpow(2,v[i+1]-rev[j])+MOD)%MOD);
            }
            dp1=dp1*2%MOD;
        }
        else{
            dp1=dp1*2%MOD;
            rep2(j,b+1,a){
                dp1=(dp1+2*dp2[j])%MOD;
            }
            dp2.erase(dp2.begin()+b+1,dp2.end());
        }
        // cout<<dp1<<" "; print(dp2);
        // cout<<endl;
        
    }
    ll ans=0;
    rep(i,dp2.size())ans=(ans+dp2[i])%MOD;
    cout<<(ans+dp1)%MOD<<endl;
}