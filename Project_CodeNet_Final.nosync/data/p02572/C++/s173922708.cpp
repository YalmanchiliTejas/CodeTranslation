// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll mod = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
//
//
void solve(){
    int n;
    cin>>n;
    vector<ll> vec(n);
    for(int i = 0; i < n; i++)
        cin>>vec[i];
    vector<ll> suf(n+1, 0);
    for(int i = n-1; i >= 0; i--){
        suf[i] = suf[i+1] + vec[i];
        suf[i] %= mod;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += vec[i]*(suf[i+1]%mod)%mod;
        ans %= mod;
    }
    cout<<ans;
}
int main(){ 
        hs;
        ll t;
        t=1;
        // cin>>t;
        for (int i=1; i<=t; i++){
                //cout<<"Case #"<<i<<": ";
                solve();
         }
        return 0; 
}