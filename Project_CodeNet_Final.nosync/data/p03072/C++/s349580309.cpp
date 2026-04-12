#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
using ll=long long;
const ll MOD=100000007;
#define rep(i,a,b) for(ll i=a;i<b;i++)
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline constexpr int intpow(ll a,ll b){
    if(b==0) return 1;
    ll ans=intpow(a,b/2);
    return ans*ans%MOD*(b&1?a:1)%MOD;
}
inline constexpr int modf(ll n){
    ll ans=1;
    rep(i,0,n) {ans=ans*(n-i)%MOD;}
    return ans;
}
int main(){
    ll n;
    cin>>n;
    vector<ll> h(n);
    rep(i,0,n) cin>>h[i];
    ll cnt=1;
    rep(i,1,n){
        bool f=1;
        rep(j,0,i){
            if(h[j]>h[i]) f=0;
        }
        if(f) cnt++; 
    }    
    cout<<cnt;
}