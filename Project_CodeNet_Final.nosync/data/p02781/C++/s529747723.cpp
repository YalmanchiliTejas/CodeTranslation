//by (111110101)2
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
string s;
long long k,n,ans,dp[111][5][3];
int main()
{
	cin>>s>>k;
	n=s.size();
	dp[0][0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			for(int o=0;o<2;o++)
			{
				for(int x=0;x<=9;x++)
				{
					int ni=i+1,nj=j,no=o;
					if(o==0)
					{
						if(x>(s[i]-'0'))
						{
							continue;
						}
						else if(x<(s[i]-'0'))
						{
							no=1;
						}
					}
					if(x!=0)
					{
						nj++;
					}
					dp[ni][nj][no]+=dp[i][j][o];
				}
			}
		}
	}
	cout<<dp[n][k][0]+dp[n][k][1]<<endl;
	return 0;
}