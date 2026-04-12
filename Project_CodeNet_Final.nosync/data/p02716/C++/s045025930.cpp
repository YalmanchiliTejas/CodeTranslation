#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin>>n;
	ll a[n];
	for(auto &o : a)cin>>o;
	ll  dp[n+1];
	ll sum=0;
	memset(dp, 0, sizeof dp);
	sum=a[0];
	
	for(int i=2;i<=n;i++)
	{
		if(i&1)
		{
			dp[i]=max(a[i-1]+dp[i-2], dp[i-1]);
			sum+=a[i-1];
		}
		else //choosing odd number of elements
		{
			dp[i]=max(a[i-1]+dp[i-2], sum);
			
		}
		
	}
	cout<<dp[n]<<"\n";
}