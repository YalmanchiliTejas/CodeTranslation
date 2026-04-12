#include<bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPN(i,n) for(int i=1;i<=(n);i++)
using namespace std;
int dp[105][4][2];
int main()
{
	int ans;
	string s;
	cin>>s;
	ll n=s.size();
	ll K;
	cin>>K;
	dp[0][0][0]=1;
	REP(i,n)
	{
		REP(j,4)
		{
			REP(k,2)
			{
				ll nd=s[i]-'0';
				REP(d,10)
				{
					ll ni=i+1,nj=j,nk=k;
					if(d!=0)
					{
						nj++;
					}
					if(nj>K)
					{
						continue;
					}
					if(k==0)
					{
						if(d>nd)
						{
							continue;
						}
						if(d<nd)
						{
							nk=1;
						}
					}
					dp[ni][nj][nk]+=dp[i][j][k];
				}
			}
		}
	}
	ans=dp[n][K][0]+dp[n][K][1];
	cout<<ans<<endl;
	return 0;	
} 