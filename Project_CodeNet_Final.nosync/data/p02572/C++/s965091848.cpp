#include<bits/stdc++.h>
#include <iostream>
#define ll long long
#define MOD (int)1e9+7

using namespace std;

int main() {
    ll n;cin>>n;
    vector<ll> vt(n,0),sf_sum(n,0);
    for(int i=0;i<n;i++) cin>>vt[i];
    ll sum = vt[n-1];
    for(int i=n-2;i>=0;i--){
        sum%=MOD;
        sf_sum[i] = sum;
        sum+= vt[i];
    }
    ll ans =0;
    for(int i=n-2;i>=0;i--){
        ans+= vt[i]*sf_sum[i];
        ans%=MOD;
    }
    // for(auto it: sf_sum) cout<<it<<" ";
    // cout<<"\n";
    cout<<ans<<"\n";
    return 0;
}
