#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n;
    cin>>n;
    int a[n];   
    ll sum=0,mod=1e9+7;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum=(sum+a[i])%mod;
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        sum=((sum-a[i])%mod+mod)%mod;
        ans=((ans+ (sum*a[i])%mod)%mod+mod)%mod;
    }
    cout<<ans<<endl;
}