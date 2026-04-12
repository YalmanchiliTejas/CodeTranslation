#include <bits/stdc++.h>
#define ll long long

using namespace std;
int m=1000000007;


int main() {
    ll n;
    cin>>n;
    vector<ll> arr(n,0);
    for(ll i=0;i<n;i++)cin>>arr[i];
    
    vector<ll> psum(n,0);
    
    
    for(ll i=n-2;i>=0;i--)
    {
        psum[i]=(arr[i+1]+psum[i+1])%m;
    }
    
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ans =  (ans + (psum[i]*arr[i])%m)%m;
    }
    cout<<ans<<endl;
    return 0;
}