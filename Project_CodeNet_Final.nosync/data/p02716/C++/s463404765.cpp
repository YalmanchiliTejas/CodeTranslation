#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+50;
int t,n,m;
int arr[maxn];
ll dp[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
/*  	if(n%2==0)
	{
		ll fin0=0;
		ll fin1=0;
		for(int i=1;i<=n;i++)
		{
			if(i&1) fin1+=arr[i];
			else fin0+=arr[i];
		}
		cout<<max(fin0,fin1)<<endl;
		return 0; 
	}*/
	ll sum[maxn];
	sum[1]=arr[1];
	for(int i=3;i<=n;i+=2)
	{
		sum[i]=sum[i-2]+arr[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(i%2==1)
		{
			dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
		}
		else
		{
			dp[i]=max(sum[i-1],dp[i-2]+arr[i]);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}