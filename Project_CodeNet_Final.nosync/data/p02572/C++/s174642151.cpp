#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ll n;
    cin>>n;
    ll arr[n],i,j,t,sum[n],ans=0;
    for(i=0;i<n;i++)
        cin>>arr[i];

    t=0;
    for(i=n-1;i>=0;i--)
    {
        t=t+arr[i];
        sum[i]=t%mod;
    }

    for(i=0;i<(n-1);i++)
    {
        t=(arr[i]*sum[i+1])%mod;
        ans=(ans+t)%mod;
    }

    cout<<ans<<endl;
    return 0;
}
