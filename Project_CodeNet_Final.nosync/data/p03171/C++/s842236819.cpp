#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3005;
ll dp[N][N];
int n,x[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++)dp[i][i]=x[i];
	for(int i=n;i>=1;--i)
	{
		for(int j=i+1;j<=n;j++)
		{
			dp[i][j]=max(x[i]-dp[i+1][j],x[j]-dp[i][j-1]);
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}