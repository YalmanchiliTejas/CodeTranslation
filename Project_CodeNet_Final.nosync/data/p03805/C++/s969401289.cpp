#include<iostream>
#include<vector>
using namespace std;
vector<int>G[8];
long dp[1<<8][8];
main()
{
	long cnt=0;
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;cin>>a>>b;
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dp[1][0]=1;
	for(int i=1;i<1<<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<G[j].size();k++)
			{
				int b=G[j][k];
				if(i&(1<<b))continue;
				dp[i|(1<<b)][b]+=dp[i][j];
			}
		}
	}
	for(int i=0;i<n;i++)cnt+=dp[(1<<n)-1][i];
	cout<<cnt<<endl;
}