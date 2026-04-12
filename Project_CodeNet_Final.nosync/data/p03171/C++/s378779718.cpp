#include<iostream>
using namespace std;
int a[3001];
long long dp[3001][3001];
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int len=1;len<=n;len++)
		for(int i=1;i<=n;i++)
		{
			int j=i+len-1;
			if(j>n)continue;
			if(len==1)dp[i][j]=a[i];
			else dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
		}
	cout<<dp[1][n];
	return 0;
}