/*input
27
18 -28 18 28 -45 90 -45 23 -53 60 28 -74 -71 35 -26 -62 49 -77 57 24 -70 -93 69 -99 59 57 -49
*/
#include "bits/stdc++.h"
#define ll long long
using namespace std;
const int MAXN = 2e5+9;
ll a[MAXN],dp[MAXN][2];
int main()
{
	ll n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			dp[i][0]=a[i];
			if(i-2>=0)
			{
				dp[i][0]+=dp[i-2][0];
				dp[i][1]=a[i]+dp[i-2][1];
				dp[i][1]=max(dp[i][1],dp[i-1][0]);
			}
		}
		else
		{
			dp[i][0]=dp[i-1][0];
			ll res=a[i];
			if(i-2>=0)
			{
				res+=dp[i-2][0];
			}
			dp[i][0]=max(dp[i][0],res);
		}
	}
	ll fans;
	if(n%2)
	{
		fans=dp[n-1][1];
	}
	else
	{
		fans=dp[n-1][0];
	}
	cout<<fans<<endl;
	return 0;

}