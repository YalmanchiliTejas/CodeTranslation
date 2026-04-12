#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define debug1(x) cerr<<#x<<" : "<<x<<"\n";
#define debug2(x,y) cerr<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\n";
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main() {
    IOS;
    ll n;
    cin>>n;
    ll a[n],sum=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        sum = (sum+a[i])%mod;
    }
    ll ans=0;
    for(ll i=0;i<n-1;i++){
        sum-=a[i];
        if(sum<0)sum+=mod;
        ans = ( ans + (a[i]*(sum))%mod )%mod;
    }
    cout<<ans;

    return 0 ;
}
