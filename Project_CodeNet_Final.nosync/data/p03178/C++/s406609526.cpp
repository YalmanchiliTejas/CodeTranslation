#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
string s;
int k;
void add(int &a, int b)
{
	a+=b;
	if(a>=mod)
		a-=mod;
}
signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>s>>k;
	int n=s.length();
	vector<vector<int>> dp(k, vector<int>(2));
	/* dp[i][j], where i = number of digits processed so far, j = bound or not(0-> bound, 1->not bound);*/

	dp[0][1]=1;
	for(int idx=0; idx<n; ++idx)
	{
		vector<vector<int>> new_dp(k, vector<int>(2));
		for(int sum=0; sum<k; ++sum)
		{
			for(bool bound : {true, false}){
				for(int newdig=0; newdig<=9; ++newdig)
				{
					if(newdig>(s[idx]-'0') and bound)
						break;
					add(new_dp[(sum+newdig)%k][bound and (newdig==(s[idx]-'0'))], dp[sum][bound]);
				}
			}
		}
		dp=new_dp;
	}
	int ans = (dp[0][0]+dp[0][1])%mod-1;
	if(ans==-1)
		ans=mod-1;
	cout<<ans;


	return 0;	
}