#include<bits/stdc++.h>
#include<math.h>
#include<vector>
using namespace std;
#define MAX 200005
#define MOD 1000000007
#define NINF -1000000000000000000
long long dp[MAX][5];
int a[MAX];
void initialize(int n)
{
    int i,j;
    for(i=0;i<=n+1;i++)
    {
        for(j=0;j<5;j++)
        {
            dp[i][j]=NINF;
        }
    }
}
long long int sum(int index,int skip,int n)
{
    if(dp[index][skip]!=NINF)
    {
        //printf("DP(%d,%d)=%lld\n",index,skip,dp[index][skip]);
        return dp[index][skip];
    }
    if(index>=n)
    {
        if(n%2>0&&skip>1) dp[index][skip]=NINF/100;
        else dp[index][skip]=0;
        //printf("Default(%d,%d)=%lld\n",index,skip,dp[index][skip]);
        return dp[index][skip];
    }
    dp[index][skip]=sum(index+2,skip,n)+a[index];
    if(skip>0)
    {
        dp[index][skip]=max(dp[index][skip],sum(index+1,skip-1,n));
    }
    //printf("Recursion(%d,%d)=%lld\n",index,skip,dp[index][skip]);
    return dp[index][skip];
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    initialize(n);
    long long int ans=sum(0,1+n%2,n);
    printf("%lld",ans);
    return 0;
}
