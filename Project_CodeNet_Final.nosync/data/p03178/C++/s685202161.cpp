#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
main()
{
	string s;
	cin>>s;
	
	int n=s.length(),d;
	cin>>d;
	
	vector<vector<long long>> dp(d,vector<long long> (2));
	dp[0][1]=1;
	
	for(int i=0;i<n;i++)
	{
		vector<vector<long long>> new_dp(d,vector<long long> (2));
		for(int j=0;j<d;j++)
		{
			for(int k=0;k<10;k++)
			{
				new_dp[(j+k)%d][0]=(new_dp[(j+k)%d][0]+dp[j][0])%MOD;
			}
		}
		
		for(int j=0;j<d;j++)
		{
			for(int k=0;k<s[i]-'0';k++)
			{
				new_dp[(j+k)%d][0]=(new_dp[(j+k)%d][0]+dp[j][1])%MOD;
			}
		}
		
		for(int j=0;j<d;j++)
		{
			new_dp[(j+s[i]-'0')%d][1]=(new_dp[(j+s[i]-'0')%d][1]+dp[j][1])%MOD;
		}
		
		dp=new_dp;
	}
	
	long long ans=(dp[0][0]+dp[0][1]-1+MOD)%MOD;
	
	cout<<ans<<endl;
}