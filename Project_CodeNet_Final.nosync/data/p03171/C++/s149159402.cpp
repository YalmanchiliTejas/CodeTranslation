#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mk make_pair
#define MAX (lld)1e18+7
#define lim 1e5
using namespace std;

const lld mod=1e9+5;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	lld n;
	cin>>n;
	std::vector<lld> v(n);

	for(lld i=0;i<n;i++)
		cin>>v[i];

	lld dp[n+1][n+1];

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
			dp[i][j]=mod;
	}

	for(lld L=n-1;L>=0;L--)
	{
		for(lld R=L;R<n;R++)
		{
			if(L==R)
				dp[L][R]= v[L];
			else
				dp[L][R] = max(v[L]-dp[L+1][R] , v[R]-dp[L][R-1]);
		}
	}


	cout<<dp[0][n-1]<<endl;
}