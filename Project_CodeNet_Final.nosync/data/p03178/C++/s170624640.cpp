#include <bits/stdc++.h>
#define ll long long
using namespace std;
string a;
int m;
int mod=1e9+7;
long long out = 0;
int dp[10005][105],pref[10005][105];
void dawaj( string e)
{
	pref[0][0]=1;
	for(int i=1;e.size()>=i;i++)
	{
		int cyfra=e[i-1]-'0';
		for(int r=0;m>r;r++)
		{
			for(int c=0;9>=c;c++)
			{
				dp[i][(r+c)%m]=(dp[i][(r+c)%m]+dp[i-1][r])%mod;
			}
			for(int c=0;cyfra>=c;c++)
			{
				if(c==cyfra)
					{
						pref[i][(r+c)%m]=(pref[i][(r+c)%m] + pref[i-1][r])%mod;
					}
				else
					{
						dp[i][(r+c)%m] = ( dp[i][(r+c)%m ] + pref[i-1][r] )% mod;
					}

			}
		}
	}
}
int main(){
	cin>>a>>m;
	dawaj(a);
	cout<<(dp[a.size()][0]+pref[a.size()][0]-1+mod)%mod;
	return 0;
}
