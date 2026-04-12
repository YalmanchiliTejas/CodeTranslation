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
#define N 10010
#define M 110
using namespace std;
string s;
ll d,n,dp[N][M][2];//0->the number is already smaller than the original number 1->the number equals to the original number. 
int main(){
	ll i,j,k;
	cin>>s>>d;
	n=s.size();
	memset(dp,0,sizeof(dp));
	dp[0][(s[0]-'0')%d][1]=1;
	for(i=0;i<s[0]-'0';i++)
	{
		dp[0][i%d][0]++;
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<d;j++)
		{
			for(k=0;k<10;k++)
			{
				if(k<s[i]-'0')
				{
					dp[i][(j+k)%d][0]=(dp[i][(j+k)%d][0]+dp[i-1][j][1]+dp[i-1][j][0])%MOD;
				}
				else if(k==s[i]-'0')
				{
					dp[i][(j+k)%d][0]=(dp[i][(j+k)%d][0]+dp[i-1][j][0])%MOD;
					dp[i][(j+k)%d][1]=(dp[i][(j+k)%d][1]+dp[i-1][j][1])%MOD;
				}
				else
				{
					dp[i][(j+k)%d][0]=(dp[i][(j+k)%d][0]+dp[i-1][j][0])%MOD;
				}
			}
		}
	}
	cout<<(dp[n-1][0][0]+dp[n-1][0][1]-1+MOD)%MOD<<endl;
	return 0;
}