#include<iostream>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll mod=1e9+7;
    ll arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    ll suf[n];
    ll sum=0;
    for(int i=n-1; i>=0; i--) {
        suf[i]=sum%mod;
        sum+=arr[i];
    }
    ll ans=0;
    for(int i=0; i<n; i++)
        ans+=(arr[i]*suf[i])%mod;
    cout<<ans%mod<<endl;
    return 0;
}