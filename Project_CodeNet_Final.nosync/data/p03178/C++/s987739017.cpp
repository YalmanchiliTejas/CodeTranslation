#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

ll dp[10001][100][2];

int main()
{
	string k;
	int d;
	ll ans=0;
	cin>>k>>d;
	fill(dp[0][0],dp[10001][0],0);
	
	dp[0][0][1]=1;
	for(int i=1;i<k.size()+1;i++)
	{
		for(int j=0;j<d;j++)
		{
			if(dp[i-1][j][0]>0)
			{
				for(int m=0;m<10;m++)
				{
					int t=(j+m)%d;
					if(t<0)
						t+=d;
					dp[i][t][0]+=dp[i-1][j][0];
					dp[i][t][0]%=MOD;
				}
			}
			if(dp[i-1][j][1]>0)
			{
				int t;
				for(int m=0;m<(k[i-1]-'0');m++)
				{
					t=(j+m)%d;
					if(t<0)
						t+=d;
					dp[i][t][0]+=dp[i-1][j][1];
					dp[i][t][0]%=MOD;
				}
				t=(j+(int)(k[i-1]-'0'))%d;
				if(t<0)
					t+=d;
				dp[i][t][1]+=dp[i-1][j][1];
				dp[i][t][1]%=MOD;
			}
		}
	}

	ans=dp[k.size()][0][0]+dp[k.size()][0][1]-1;
	ans%=MOD;
	if(ans<0)
		ans+=MOD;
	cout<<ans<<endl;
	return 0;
}