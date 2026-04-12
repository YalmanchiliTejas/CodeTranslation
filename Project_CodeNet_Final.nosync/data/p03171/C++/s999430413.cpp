#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3004;
ll dp[N][N];
// dp(i,j) the optimal value of x-y in interval (i->j)

ll a[N];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		dp[i][i] = a[i];
	}
	
	for(int len=2;len<=n;len++)
	{
		for(int l=1;l+len<=n+1;l++)
		{
			int r = l+len-1;
			dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
		}
	}
	cout<<dp[1][n];
}