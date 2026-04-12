#include <bits/stdc++.h>
using namespace std;

long long dp[200005],sum[200005],s[200005];

int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            cin>>s[i];
        for(int i=1;i<=n;i++)
        {
            if(i==1)
                sum[i]=s[i];
            else
                sum[i]=sum[i-2]+s[i];
        }
        for(int i=2;i<=n;i++)
        {
            if(i%2==0)
            {
                dp[i]=max(dp[i-2]+s[i],sum[i-1]);
            }
            else
            {
                dp[i]=max(dp[i-2]+s[i],dp[i-1]);
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}