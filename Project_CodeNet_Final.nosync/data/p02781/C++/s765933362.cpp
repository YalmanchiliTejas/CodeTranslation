#include<iostream>
using namespace std;
string N;
int K;
long dp[111][2][4];
main()
{
	cin>>N>>K;
	dp[0][0][0]=1;
	for(int i=0;i<N.size();i++)
	{
		for(int j=0;j<2;j++)
		{
			int lim=j?9:N[i]-'0';
			for(int k=0;k<=K;k++)
			{
				for(int l=0;l<=lim;l++)
				{
					int nk=k+!!l;
					if(nk<=K)
					{
						dp[i+1][j||l<lim][nk]+=dp[i][j][k];
					}
				}
			}
		}
	}
	cout<<dp[N.size()][0][K]+dp[N.size()][1][K]<<endl;
}
