#include <bits/stdc++.h>
using namespace std;
#define int long 
int32_t main()
{
    int d = 10e9 + 7;
    int n;
    cin >> n;
    int ar[n];
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++) cin>>ar[i];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=ar[i];
        for(int k=0,j=i;j<n;j++,k++)
        {
            if(k==j)
            {
                dp[k][j]=ar[k];
            }
            else if(k+1==j)
            {
                dp[k][j]=max(ar[j],ar[k]);
            }
            else
            {
                dp[k][j]=max(ar[k]+min(dp[k+1][j-1],dp[k+2][j]),ar[j]+min(dp[k][j-2],dp[k+1][j-1]));
            }
        }
    }
    int b=sum-dp[0][n-1];
    cout<<dp[0][n-1]-b<<endl;
}
