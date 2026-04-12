#include <bits/stdc++.h>
#define ll long long int

using namespace std;
ll m=1e9+7;
int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    ll b[n];
    memset(b,0,sizeof(b));

    b[n-2]=a[n-1];
    for(ll i=n-3;i>=0;i--){
        b[i]=(a[i+1]+b[i+1])%m;
    }
    ll ans=0;
    for(ll i=0;i<n-1;i++){
        ans=(ans+(a[i]*b[i])%m)%m;
    }
    cout<<ans;

    return 0;
}
