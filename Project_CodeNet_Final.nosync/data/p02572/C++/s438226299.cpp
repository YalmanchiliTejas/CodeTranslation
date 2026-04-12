#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,sum=0,mod=1e9+7,ans=0;
    cin>>n;
    long long arr[n],dp[n];
    for(long i=0;i<n;i++){
    cin>>arr[i];
    sum=(sum+arr[i])%mod;
    dp[i]=sum;
    }
    for(long i=0;i<n;i++){
    ans=(ans+(arr[i]*(sum-dp[i]+mod)%mod)%mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}
