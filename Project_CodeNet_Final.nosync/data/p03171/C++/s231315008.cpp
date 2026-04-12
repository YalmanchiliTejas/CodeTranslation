#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    ll dp[n+1][n+1][2];
    dp[0][0][0]=0;
    dp[0][0][1]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j][0]=0;
            dp[i][j][1]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][i][0]=arr[i-1];
        dp[i][i][1]=0;
    }
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            if(arr[i-1]+dp[i+1][j][1]>arr[j-1]+dp[i][j-1][1])
            {
                dp[i][j][0]=arr[i-1]+dp[i+1][j][1];
                dp[i][j][1]=dp[i+1][j][0];
            }
            else
            {
                dp[i][j][0]=arr[j-1]+dp[i][j-1][1];
                dp[i][j][1]=dp[i][j-1][0];
            }
        }
    }
    cout<<dp[1][n][0]-dp[1][n][1]<<"\n";
    return 0;
}