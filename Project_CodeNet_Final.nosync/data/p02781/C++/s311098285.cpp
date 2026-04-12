#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
using namespace std;
string s;
ll dp[110][5][2],k;
int main(){
	ll i,j,l,p;
	cin>>s>>k;
	reverse(s.begin(),s.end());
	s='#'+s;
	memset(dp,0,sizeof(dp));
	for(i=0;i<s.size();i++)
	{
		dp[i][0][0]=1;
	}
	for(i=1;i<s.size();i++)
	{
		p=s[i]-'0';
		for(l=1;l<=k;l++)
		{
			if(p==0)
			{
				dp[i][l][0]=dp[i-1][l][0];
				dp[i][l][1]=9*(dp[i-1][l-1][0]+dp[i-1][l-1][1])+dp[i-1][l][1];
			}
			else
			{
				dp[i][l][0]=(p-1)*(dp[i-1][l-1][0]+dp[i-1][l-1][1])+dp[i-1][l-1][0]+dp[i-1][l][0]+dp[i-1][l][1];
				dp[i][l][1]=(9-p)*(dp[i-1][l-1][0]+dp[i-1][l-1][1])+dp[i-1][l-1][1];
			}
		}
	}
	cout<<dp[s.size()-1][k][0]<<endl;
	return 0;
}