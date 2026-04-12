#include <iostream>
using namespace std;
long long int dp[3000][3000][2];
int main() {
	long long int n,s=0;
	cin>>n;
	long long int a[n],i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	for(i=0;i<n;i++)
	{
		dp[i][i][0]=a[i];
		dp[i][i][1]=0;
	}
	for(long long int rminusl=1;rminusl<n;rminusl++)
	{
		for(long long int l=0;l<n-rminusl;l++)
		{
			long long int r=l+rminusl;
			dp[l][r][0]=max(a[l]+dp[l+1][r][1],a[r]+dp[l][r-1][1]);
			dp[l][r][1]=min(dp[l+1][r][0],dp[l][r-1][0]);
		}
	}
	long long int x=2*dp[0][n-1][0]-s;
	cout<<x<<endl;
	return 0;
}