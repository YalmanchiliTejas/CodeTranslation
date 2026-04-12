#include<bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int i,j,n;
	cin>>n;
	long long int sum[n];
	long long int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sum[0]=a[0];
	for(i=1;i<n;i++)
		sum[i]=sum[i-1]+a[i];
	long long int dp[n][n];
	memset(dp,0,sizeof(dp));
	for(i=0;i<n;i++)
		dp[i][i]=a[i];
	int l;
	for(l=2;l<=n;l++)
	{
		for(i=0;i<n-l+1;i++)
		{
			j=l-1+i;
			long long int pp=sum[j];
			if(i)
				pp-=sum[i-1];
			dp[i][j]=max(pp-dp[i+1][j],pp-dp[i][j-1]);
		}
	}
	
	long long int pp=dp[0][n-1]-sum[n-1];
	pp+=dp[0][n-1];
	cout<<pp<<endl;
	return 0;
}