#include <iostream>
#define ll long long
using namespace std;
ll dp[3001][3001],ar[3001];
int main()
{
	ll n;cin>>n;
	for (int i=1;i<=n;i++) {cin>>ar[i];}
	for (int i=1;i<=n;i++) 
	{
		dp[i][i] = ar[i];
		if (!(n%2)) {dp[i][i] = -dp[i][i];}
	}
	for (int i=2;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			if ((i+(int)(!(n%2)))%2) {dp[j-i+1][j] = max(dp[j-i+2][j]+ar[j-i+1],dp[j-i+1][j-1]+ar[j]);}
			else {dp[j-i+1][j] = min(dp[j-i+2][j]-ar[j-i+1],dp[j-i+1][j-1]-ar[j]);}
			//cout<<(i+(int)(!(n%2)))%2<<" "<<j-i+1<<" "<<j<<" "<<dp[j-i+1][j]<<"\n";
		}
	}
	cout<<dp[1][n]<<"\n";
	return 0;
}