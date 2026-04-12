#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;

ll n;
ll a[200005];
ll dp[200005];
ll lastsum[200005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	lastsum[1]=a[1];
	for(int i=3;i<=n;i+=2)
	{
		lastsum[i]=lastsum[i-2]+a[i];
	}
	
	for(int i=2;i<=n;i++)
	{
		if(i%2==0)
		{
			dp[i]=max(dp[i-2]+a[i],lastsum[i-1]);
		}
		else
		{
			dp[i]=max(dp[i-2]+a[i],dp[i-1]);
		}
	}
	
	cout<<dp[n];
	return 0;
}