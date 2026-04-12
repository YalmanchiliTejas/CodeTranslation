#include<bits/stdc++.h>
using namespace std;
const int N=110;
typedef long long ll;
int dp[N][4],a[N],k;
char s[N];
int dfs(int pos,bool lead,bool lim,int now)
{
	if(pos==0)return now==0;
	if(now<0)return 0;
	if(~dp[pos][now] && !lead && !lim)return dp[pos][now];
	int ret=0;
	int up=lim?a[pos]:9;
	for(int i=0;i<=up;++i)
	{
		if(i==0)ret+=dfs(pos-1,lead,lim&&(i==up),now);
		else ret+=dfs(pos-1,0,lim&&(i==up),now-1);
	}
	return !lim?dp[pos][now]=ret:ret;//注意到方案数只受非lim限制不受前导0限制 
}
 
int part(char s[])
{
	int len=0;
	int l=strlen(s);
	for(int i=l-1;i>=0;--i)
		a[++len]=s[i]-'0';
	memset(dp,-1,sizeof dp);
	return dfs(len,1,1,k); 
}
 
int main()
{
	scanf("%s",s);
	scanf("%d",&k);
	printf("%d\n",part(s));
}