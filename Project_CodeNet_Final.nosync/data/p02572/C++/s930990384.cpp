#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    ll sumarr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1)
            sumarr[n-1]=arr[i];
        else
            sumarr[i]=(sumarr[i+1]+arr[i])%mod;
    }
    ll sum=0;
    for(ll i=0;i<n-1;i++)
        sum=(sum+(arr[i]*sumarr[i+1])%mod)%mod;
    cout<<sum;
    return 0;
}