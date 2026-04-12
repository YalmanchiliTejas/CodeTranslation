#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

ll dp[3001][3001];//dp[i][j]...区間[i,j)において先手-後手の最大値
ll a[3000];
int main()
{
	int n;
	int ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	fill(dp[0],dp[3001],0);
	for(int i=0;i<n;i++)
		dp[i][i+1]=a[i];
	for(int i=2;i<n+1;i++)
	{
		for(int j=i;j<n+1;j++)
		{
			dp[j-i][j]=max(a[j-i]-dp[j-i+1][j],a[j-1]-dp[j-i][j-1]);
		}
	}
	cout<<dp[0][n]<<endl;
	return 0;
}