#include<bits/stdc++.h>
using namespace std;
const long long md=998244353;
long long n,s,a[3333],dp[6666],ans;
int main()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==s)
		{
			ans+=i*(n-i+1);
			ans%=md;
		}
		else if(a[i]<s)
		{
			ans+=dp[s-a[i]]*(n-i+1);
			ans%=md;
		}
		for(int j=s;j>=0;j--)
		{
			if(j+a[i]>s)
			{
				continue;
			}
			dp[j+a[i]]+=dp[j];
			dp[j+a[i]]%=md;
		}
		dp[a[i]]+=i;
		dp[a[i]]%=md;
	}
	cout<<ans<<endl;
	return 0;
}