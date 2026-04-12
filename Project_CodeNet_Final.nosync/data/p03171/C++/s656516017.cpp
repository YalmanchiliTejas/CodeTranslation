#include <bits/stdc++.h>
using namespace std;

long long solve1(long long i,long long j,long long dp[][3001],long long a[])
{
    if(i>j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    long long op1=a[i]+min(solve1(i+2,j,dp,a),solve1(i+1,j-1,dp,a));
    long long op2=a[j]+min(solve1(i+1,j-1,dp,a),solve1(i,j-2,dp,a));
    return dp[i][j]=max(op1,op2);
}

int main() {
    long long n;
    cin>>n;
    long long a[n];
    long long sum=0;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    long long dp[3001][3001];
    memset(dp,-1,sizeof(dp));
    long long X=solve1(0,n-1,dp,a);
     long long Y=sum-X;
    cout<<X-Y;
    return 0;
}
