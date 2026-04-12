#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int NM=1e5+5;

ll dp[3005][3005];

int main()
{   int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>dp[i][i];
    for(int k=1; k<n; k++)
        for(int i=1,j; i+k<=n; i++)
        {   j=i+k;
            dp[i][j]=max(dp[i][i]-dp[i+1][j],dp[j][j]-dp[i][j-1]);
        }
    cout<<dp[1][n];
    return 0;
}