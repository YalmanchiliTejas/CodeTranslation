#include <bits/stdc++.h>
using namespace std;

const int M=1e4+5;
const int MD=105;
const int MO=1e9+7;
inline int add(int x,int y)
{
	x+=y;
	if(x>=MO) x-=MO;
	return x;
}
inline void addv(int &x,int y)
{
	x+=y;
	if(x>=MO) x-=MO;
}
inline int mul(int x,int y)
{
	return 1LL*x*y%MO;
}

char s[M];
int dp[M][MD][2];
int n,d;
int getdp(int cur,int nd,int lim)
{
	if(cur==n) return nd==0;
	int &ans=dp[cur][nd][lim];
	if(ans!=-1) return ans;
	ans=0;
	int up=lim?s[cur]-'0':9;
	for(int i=0;i<=up;i++)
		addv(ans,getdp(cur+1,(nd+i)%d,lim&&i==up));
	return ans;
}

int main()
{
	scanf("%s%d",s,&d);
	n=strlen(s);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",add(getdp(0,0,1),MO-1)); // 0 is not counted
	return 0;
}