// C - Sum of product of pairs
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define loop(i,x,n) for(ll i = x;i<n;i++)
#define loopr(i,x,n) for(ll i = n-1;i>=x;i--)
#define S(v) sort(v.begin(), v.end());
#define ff first
#define ss second
const ll mod = 1E9+7;
ll f(ll a, ll b){
    ll ans = 0;
    a %= mod;
    while(b){
        if(b%2)ans = (ans+a)%mod;
        a = (2*a)%mod;
        b = b/2;        
    }
    return ans;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n), suffixsum(n, 0);
    loop(i,0,n)cin>>v[i];
    loopr(i,0,n){
        if(i == n-1)suffixsum[i] = v[i];
        else suffixsum[i] = v[i] + suffixsum[i+1];
    }
    ll ans = 0;
    loop(i,0, n-1){
        ans += f(v[i], suffixsum[i+1])%mod;
    }
    cout<<ans%mod<<endl;
}