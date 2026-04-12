#include<iostream>
using namespace std;
int d,m=1e9+7,dp[10001][2][100];
string s;
main()
{
	cin>>s>>d;
	dp[0][0][0]=1;
	for(int i=0;i<s.size();i++)
	{
		for(int j=0;j<2;j++)
		{
			int L=j?9:s[i]-48;
			for(int l=0;l<=L;l++)
			{
				for(int k=0;k<d;k++)
					(dp[i+1][j|l<L][(k+l)%d]+=dp[i][j][k])%=m;
			}
		}
	}
	cout<<(dp[s.size()][0][0]+dp[s.size()][1][0]-1L+m)%m<<endl;
}