#include <bits/stdc++.h>
using namespace std;

#define f(i,x,y)			for(int i=x; i<y; i++)
#define ll 					long long 
#define mp 					make_pair
#define F 					first
#define S 					second
#define N 					100005
#define inf 				1e9+1

int main()
{
	int n;
	cin>>n;
	int a[n];
	f(i,0,n)
		cin>>a[i];


	ll dp[n][n];
	f(i,0,n)
		dp[i][i] = a[i];

	f(l,1,n)
	{
		f(i,0,n-l)
		{
			int j = i+l;
			dp[i][j] = max(a[i]-dp[i+1][j] , a[j]-dp[i][j-1]);

		}
	}
	cout<<dp[0][n-1];

	return 0;
}