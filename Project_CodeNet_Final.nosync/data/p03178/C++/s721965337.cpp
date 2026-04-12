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
const long long md=1e9+7;
string k;
long long n,dp[10101][2][111];
int main()
{
	cin>>k>>n;
	dp[0][0][0]=1;
	for(int i=0;i<k.size();i++)
	{
		for(int j=0;j<2;j++)
		{
			int lm;
			if(j==1)
			{
				lm=9;
			}
			else
			{
				lm=k[i]-'0';
			}
			for(int kk=0;kk<n;kk++)
			{
				for(int l=0;l<=lm;l++)
				{
					if(j || l<lm)
					{
						dp[i+1][1][(kk+l)%n]+=dp[i][j][kk];
						dp[i+1][1][(kk+l)%n]%=md;
					}
					else
					{
						dp[i+1][0][(kk+l)%n]+=dp[i][j][kk];
						dp[i+1][0][(kk+l)%n]%=md;
					}
				}
			}
		}
	}
	cout<<(dp[k.size()][0][0]+dp[k.size()][1][0]-1+md)%md<<endl;
	return 0;
}