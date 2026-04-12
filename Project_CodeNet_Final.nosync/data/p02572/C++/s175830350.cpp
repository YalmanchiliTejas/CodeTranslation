#include<bits/stdc++.h>
#define PI 3.141592653589793238462
using namespace std;
typedef long long ll;
typedef long double db;
ll a[200005],mod=1e9+7;
int main(){
    ll n,sum=0,ans=0;cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];sum+=a[i];
    }
    for(ll i=1;i<=n;i++){
        sum-=a[i];
        ans=(ans%mod+sum%mod*a[i]%mod)%mod;
    }
    cout<<ans<<endl;
} 