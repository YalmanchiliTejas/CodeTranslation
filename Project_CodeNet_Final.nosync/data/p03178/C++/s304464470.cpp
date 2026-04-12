#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4+5;
int dp[N][100][2];
const int mod = 1e9+7;
int32_t main()
{
	string str;
	cin>>str;
	int d;
	cin>>d;
	for(int i=0;i<str[0]-'0';i++)
		dp[0][i%d][0] += 1;
	dp[0][(str[0]-'0')%d][1] = 1;

	for(int i=1;i<str.size();i++)
	{
		for(int j=0;j<d;j++)
		{
			for(int k=0;k<10;k++){
				dp[i][(j+k)%d][0] = (dp[i][(j+k)%d][0] + dp[i-1][j][0])%mod;
				if(k < str[i]-'0')
					dp[i][(j+k)%d][0] = (dp[i][(j+k)%d][0] + dp[i-1][j][1])%mod;
			}

			dp[i][(j + str[i]-'0')%d][1] = (dp[i][(j + str[i]-'0')%d][1] + dp[i-1][j][1])%mod;

		}
	}

	cout<<(dp[str.size()-1][0][0] + dp[str.size()-1][0][1]-1 + mod)%mod;

}