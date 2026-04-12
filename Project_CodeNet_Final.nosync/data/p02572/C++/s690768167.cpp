#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,i,j,k,mod=1e9+7,ans=0;
    cin>>n;
    long long a[n+1],sum[n+1];
    sum[0]=0;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(i=1;i<n;i++)
    {
        ans+=(a[i]*((sum[n]-sum[i])%mod))%mod;
        ans=ans%mod;
    }
    cout<<ans<<endl;
}
