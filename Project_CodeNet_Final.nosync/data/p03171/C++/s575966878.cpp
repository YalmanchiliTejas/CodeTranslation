#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>> n;
    vector<long long> a(n);
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }

    long long dp[n][n];
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<n;j++)
        dp[i][j]=0;
    }
    for(long long i=0;i<n;i++)
    dp[i][i]=a[i];

    for(long long i=n-2;i>=0;i--)
    {
        for(long j=i+1;j<n;j++)
        {
            dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
            // cout<<dp[i][j]<<" ";
        }
    }


    cout<<dp[0][n-1];
    return 0;

}