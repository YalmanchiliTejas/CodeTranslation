#include<bits/stdc++.h>
#define ull unsigned long long
# define ll long long
# define mod 1000000007LL 
using namespace std;
int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    ll sum[n]={0};
    sum[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        sum[i]=sum[i+1]%mod+arr[i]%mod;
        sum[i]=sum[i]%mod;
    }
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        ans=(ans+(arr[i-1]*sum[i])%mod)%mod;
        ans=ans%mod;
    }
    cout<<ans;

    
    
    return 0;
}