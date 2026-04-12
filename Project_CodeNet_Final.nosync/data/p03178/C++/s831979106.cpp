#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,MOD=1e9+7;
char a[N];
int n,D,num[N],dp[N][110];
int Search(int k,int sum,int lim,int preo)
{
	if ((!lim)&&(!preo)&&dp[k][sum]!=-1) return dp[k][sum];//´íÎó±Ê¼Ç£º¶¨¸ñºÍÓÐÇ°µ¼0µÄÇé¿ö²»ÄÜÖ±½Ó·µ»Ø 
	if (k>n) if (!sum) return 1; else return 0;
	int s=0,maxd=(lim?num[k]:9);
	for (register int i=0;i<=maxd;++i) s=(s+Search(k+1,(sum+i)%D,lim&&(i==num[k]),preo&&(i==0)))%MOD;
	if ((!lim)&&(!preo)) dp[k][sum]=s;
	return s;
}
int main()
{
	scanf("%s%d",a+1,&D);n=strlen(a+1);
	for (register int i=1;i<=n;++i) num[i]=a[i]-'0';
	memset(dp,-1,sizeof(dp));
	printf("%d\n",(Search(1,0,1,1)-1+MOD)%MOD);
	return 0;
}