#include<bits/stdc++.h>
using namespace std;
#define ll long long int
long long int mod=1000000007;
long int N=200000+5;

int main()
{
    ll n;
    cin>>n;
    ll a[N];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
       
    }
    ll sum[n];
    sum[n-1]=a[n-1]%mod;
    for(int i=n-2;i>=0;i--)
    {
        sum[i]=(a[i]%mod+sum[i+1]%mod)%mod;
    }
    ll ans=0;
    ll k=0;
    for(int i=0;i<n-1;i++)
    {   
        
        ans=(ans%mod+((a[i]%mod)*(sum[i+1]%mod))%mod)%mod;
    
    }
    ans=ans%mod;
    cout<<ans<<endl;



    return 0;
}