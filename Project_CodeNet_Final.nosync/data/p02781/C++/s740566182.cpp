#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1;
int n,k;
int a[10001];
int dp[101][2][101][2];
int dfs(int x,int up,int num,int pre)
{
	if(x==0)
		return num==k;
	if(dp[x][up][num][pre]!=-1) return dp[x][up][num][pre];
		dp[x][up][num][pre]=0;
//	if(pre!=0)
	dp[x][up][num][pre]+=dfs(x-1,up&&('0'==s1[x-1]),num,pre);
	for(int i=1;i<=9;i++)
	{
		if(up&&i+'0'>s1[x-1])
			break;
		dp[x][up][num][pre]+=dfs(x-1,up&&(i+'0'==s1[x-1]),num+1,1);
	}
	return dp[x][up][num][pre];
}
signed main() 
{
	cin>>s1>>k;
	reverse(s1.begin(),s1.end());
	n=s1.length();
	
	memset(dp,-1,sizeof(dp));
	printf("%lld",dfs(s1.length(),1,0,0));
	return 0;
}
