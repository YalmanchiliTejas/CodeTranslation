#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    const ll mod=1e9+7;
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    vector<ll>suffix(n);
    suffix[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
        suffix[i]=(suffix[i+1]+arr[i+1])%mod;
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans=(ans+((arr[i]*suffix[i])%mod))%mod;

    }
    cout<<ans<<endl;


    return 0;
}