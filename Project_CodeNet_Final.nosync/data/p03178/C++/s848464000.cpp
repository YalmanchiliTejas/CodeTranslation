#include<iostream>
#include<algorithm>
using lint=long long;
using namespace std;

const int mod=1e9+7;
//lint dp[100010][2][110]={};

int main()
{
	string K;
	lint D;
	
	cin >> K >> D;
	
	const lint N=K.length();
	lint dp[100010][2][110]={};
	dp[0][0][0]=1;
	
	for(lint i=0;i<N;i++)
	{
		for(lint j=0;j<2;j++)
		{
			for(lint k=0;k<D;k++)
			{
				lint dmax;
				if(j==1)dmax=9;
				else dmax=K[i]-'0';
				for(lint d=0;d<=dmax;d++)
				{
					lint nj,nk;
					if(j==1 || d<dmax)nj=1;
					else nj=0;
					nk=(k+d)%D;
					
					dp[i+1][nj][nk]+=dp[i][j][k];
					dp[i+1][nj][nk]%=mod;
				}
			}
		}
	}
	
	cout << (dp[N][0][0]+dp[N][1][0]-1+mod)%mod << endl;
	return 0;
}