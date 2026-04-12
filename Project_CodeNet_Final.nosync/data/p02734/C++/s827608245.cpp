#include <bits/stdc++.h>
using namespace std;
int n,s,dp[3300],mol=998244353,ans;
int main()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        dp[0]=i;
        for(int j=s;j>=x;j--) dp[j]=(dp[j]+dp[j-x])%mol;
        ans=(ans+dp[s])%mol;
    }
    cout<<ans<<endl;
}
