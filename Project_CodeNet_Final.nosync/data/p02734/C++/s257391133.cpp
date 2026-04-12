#include <bits/stdc++.h>
using namespace std;
int n,s,dp[3300],mod=998244353,ans;
int main()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++) //枚举前n个物品的方案数. i表示从1到第i个物品 
    {
        int x; cin>>x;
        dp[0]=i;//01背包的变形。 这里dp[0]=i是因为 以前的背包问题只算了1--i的方案数,缺少2--i,3--i,4--i,以及i--i等i-1种情况.每情况对dp[0]要使用一次 
        for(int j=s;j>=x;j--) dp[j]=(dp[j]+dp[j-x])%mod;
        ans=(ans+dp[s])%mod;
    }
    cout<<ans<<endl;
}