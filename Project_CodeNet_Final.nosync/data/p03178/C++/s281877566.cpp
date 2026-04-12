#include<bits/stdc++.h>
#define M 1000000007
#define pb push_back
#define ll long long int
using namespace std;

int main()
{
	string s;
	cin>>s;
	int d;
	cin>>d;
	int n = s.length();
	ll dp[n][2][d];
	int i,j,k;
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<d;j++)
		{
			if(i==n-1)
			{
				dp[n-1][0][j] = 0;
				dp[n-1][1][j] = 0;
				for(k=0;k<=9;k++)
					dp[n-1][0][j] += (k%d==j);
				for(k=0;k<=s[n-1]-'0';k++)
					dp[n-1][1][j] += (k%d==j);
			}
			else
			{
				dp[i][0][j] = 0;
				for(k = 0;k<=9;k++)
				{
					dp[i][0][j] += dp[i+1][0][((j-k)%d+d)%d];
					dp[i][0][j] %= M;
				}
				dp[i][1][j] = 0;
				for(k = 0;k<s[i]-'0';k++)
				{
					dp[i][1][j] += dp[i+1][0][((j-k)%d+d)%d];
					dp[i][1][j] %= M;
				}
				dp[i][1][j] += dp[i+1][1][((j-k)%d+d)%d];
				dp[i][1][j] %= M;
			}
		}
	}


	cout<<(dp[0][1][0]-1+M)%M;

	return 0;

}
