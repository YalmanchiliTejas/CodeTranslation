#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod =1e9+7;

int main(){
    ll n;
    cin>>n;
    ll sum=0;
    ll a[n+5];
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum=sum+a[i];
        sum%=mod;
    }
    ll pre=0;
    for(int i=0; i<n; i++){
        pre=(pre+(a[i]*a[i]));
        pre%=mod;
    }
    ll ans=((sum*sum-pre)+mod)%mod;
    ans*=500000004;
    cout<<ans%mod<<endl;

    return 0;
}
