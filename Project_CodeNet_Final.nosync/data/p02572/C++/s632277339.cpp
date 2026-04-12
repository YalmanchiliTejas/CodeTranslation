#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007
ll modexpo(ll a,ll b){
    ll res = 1;
    a%=mod;
    while(b){
        if(b&1)
            res = (res*a)%mod;
        b>>=1;
        a = (a * a)%mod;
    }
    return res%mod;
}

void solve(){
    ll n;
    cin>>n;
    ll a[n];
    // ll hash[]
    map<ll,ll> mp;
    vector<ll> arr;
    
    ll sum = 0;
    for(int i =0;i<n;i++){
        cin>>a[i];
        // if(mp[a[i]]==0){
        //     arr.push_back(a[i]);
        // }
        // mp[a[i]]++;
        sum=(sum + a[i])%mod;
    }
    // n = arr.size();
    ll ans = 0;
    for(int i =0;i<n;i++){
        sum = (sum - a[i] + mod)%mod;
        ll p  = ((sum)%mod*(a[i])%mod)%mod;
        ans = (ans + p)%mod;
    }
    cout<<ans<<'\n';
}
int main(){
    IOS
    int tt;
    tt = 1;
    // cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}
