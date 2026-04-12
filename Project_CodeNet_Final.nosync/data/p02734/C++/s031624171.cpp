#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int dp[3005];
int main()
{
    int a,b,ans=0;
    cin>>a>>b;
    for(int i=0;i<a;i++)
    {
        int n;
        cin>>n;
        for(int j=b;j-n>0;j--)
        {
            dp[j]=(dp[j]+dp[j-n])%mod;
        }
        dp[n]=(dp[n]+i+1)%mod;
        ans=(ans+dp[b])%mod;
    }
    cout<<ans<<endl;
    return 0;
}
