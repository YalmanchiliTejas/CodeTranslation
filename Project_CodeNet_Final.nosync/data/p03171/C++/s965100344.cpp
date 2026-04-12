#include<iostream>
#define inf 1e18
using namespace std;
long long dp[3005][3005];
long long a[3005];
long long int rec(int i,int j){
	if(i>j)return 0;
	if(dp[i][j]!=-inf)return dp[i][j];
	return dp[i][j]=max(a[i]-rec(i+1,j),a[j]-rec(i,j-1));
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=-inf;
	cout<<rec(0,n-1);
}