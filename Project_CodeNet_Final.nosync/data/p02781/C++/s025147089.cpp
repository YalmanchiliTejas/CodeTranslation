
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[101][101][2];

int main()
{
	string n;
	cin >> n;
	int k;
	cin >> k;

	dp[0][0][0] = 1;

	for(int i = 0;i<n.size();i++)
	{
		for(char c = '0';c<n[i];c++)
		{
			for(int j = 0;j<101;j++)
			{
				if(c=='0')dp[i+1][j][1] += dp[i][j][0];
				else dp[i+1][j+1][1] += dp[i][j][0];
			}
		}
		if(n[i]=='0')for(int j = 0;j<101;j++)dp[i+1][j][0] += dp[i][j][0];
		else for(int j = 0 ;j<101;j++)dp[i+1][j+1][0] += dp[i][j][0];

		for(char c = '0';c<='9';c++)
		{
			for(int j = 0;j<101;j++)
			{
				if(c=='0')dp[i+1][j][1] += dp[i][j][1];
				else dp[i+1][j+1][1] += dp[i][j][1];
			}
		}
	}
	//for(int i = 0;i<100;i++)
	//{for(int j=0;j<4;++j)cout<<dp[j][i][1]<<' ';cout<<endl;}
	cout<<dp[n.size()][k][0]+dp[n.size()][k][1]<<endl;
	return 0;
}
