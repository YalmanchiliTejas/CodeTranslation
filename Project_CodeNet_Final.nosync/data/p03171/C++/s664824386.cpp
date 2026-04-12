#include<bits/stdc++.h>
using namespace std;
long long int dp[3001][3001][2];
long long int arr[3001];
long long int func(long long int start,long long int end,long long int turn)
{
	if(start>end)
		return 0;
	else if(start==end)
	{
		if(turn==0)
		dp[start][end][turn]=arr[start];
	    else
	    dp[start][end][turn]=-arr[start];
		return dp[start][end][turn];
	}
	else if(start<end)
	{
	if(dp[start][end][turn]!=1000000000000007)
      return dp[start][end][turn];
    long long int ans1,ans2,ans;
    if(turn==0)
    {
    ans1=arr[start]+func(start+1,end,1-turn);
    ans2=arr[end]+func(start,end-1,1-turn);
    }
    else
    {
    ans1=func(start+1,end,1-turn)-arr[start];
    ans2=func(start,end-1,1-turn)-arr[end];
    }
    if(turn==0)
    ans=max(ans1,ans2);
    else
    ans=min(ans1,ans2);
    dp[start][end][turn]=ans;
    return ans;
    }
}
int main()
{
	long long int n;
	scanf("%lld",&n);
	long long int i,ans,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			{
				dp[i][j][0]=1000000000000007;
				dp[i][j][1]=1000000000000007;
			}
	for(i=0;i<n;i++)
		scanf("%lld",&arr[i]);
    ans=func(0,n-1,0);
    printf("%lld\n",ans);
    return 0;
}