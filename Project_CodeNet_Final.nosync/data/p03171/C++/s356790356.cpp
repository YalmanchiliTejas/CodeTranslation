#include <bits/stdc++.h>
using namespace std;

long long dp[3000][3000][2];
int main()
{
    long long n,sum=0;
    cin>>n;
    vector<long long> a(n);
    for(long long& x:a)
    {
        cin>>x;
        sum+=x;
    }

    for(long long i=0;i<n;i++)
    {
    dp[i][i][0]=a[i];
    dp[i][i][1]=0;
    }

    for(long long RminusL=1;RminusL<n;RminusL++)
    {
        for(long long L=0;L+RminusL<n;L++)
        {
            long long R=L+RminusL;
            dp[L][R][0]=max(a[L]+dp[L+1][R][1],a[R]+dp[L][R-1][1]);
            dp[L][R][1]=min(dp[L+1][R][0],dp[L][R-1][0]);
        }
    }
    long long x=dp[0][n-1][0];

    long long ans=2*x-sum;
    cout <<ans;
    return 0;
}