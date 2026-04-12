#include <bits/stdc++.h>
using namespace std;
const int MM=3013;
long long dp[MM][MM];
long long s=0;
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>dp[i][i];
    for(int i=1;i<=n;i++)
    {
        s+=dp[i][i];
        for(int j=1;j+i<=n;j++)
        {
            dp[j][j+i]=max(dp[j][j]-dp[j+1][j+i],dp[j+i][j+i]-dp[j][j+i-1]);
        }
    }
    cout<<dp[1][n];
    return 0;
}
