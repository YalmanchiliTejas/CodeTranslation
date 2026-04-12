#include<bits/stdc++.h>
using namespace std;
long long int a[100005];
long long int n;
long long int dp[10000][10000][2];
long long int func(long long int i,long long int j,long long int turn)
{
	if(i>j)
	return 0;

	if(dp[i][j][turn])
	return dp[i][j][turn];
	if(turn==0)
	{
		if(i!=j)
		{
			dp[i][j][turn]=max(a[i]+func(i+1,j,1),a[j]+func(i,j-1,1));
		}
		else
		{
			dp[i][j][turn]=a[i]+func(i+1,j,1);
		}
	}
	if(turn==1)
	{
		if(i!=j)
		dp[i][j][turn]=min(-1*a[i]+func(i+1,j,0),-1*a[j]+func(i,j-1,0));
		else
		{
			dp[i][j][turn]=-1*a[i]+func(i+1,j,0);
		}
		
	}
	return dp[i][j][turn];

}


 int main()
{
long long int t=1;
	;
	while(t--)
	{
	cin>>n;
for(long long int i=01;i<=n;i++)
cin>>a[i];
		cout<<func(1,n,0);
	}
}