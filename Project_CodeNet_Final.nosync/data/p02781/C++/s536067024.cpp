#include<bits/stdc++.h>
using namespace std;
const int N=105;
int dp[N][2][2][4],n,k;
char s[N];
int dfs(int i,int f1,int f2,int sum)
{
	if(sum>k)
		return 0;
	int &f=dp[i][f1][f2][sum];
	//printf("%d %d %d %d\n",i,f1,f2,sum);
	if(f!=-1)
		return f;
	f=0;
	if(i==n+1)
		return f=(f2==0&&sum==k);
	for(int j=0;j<=9;j++)
	{
		if(f1&&j>s[i]-'0')
			break;
		int nf1=(f1&&(j>=s[i]-'0')),nf2=(f2&&(j==0)),nsum=sum+(nf2==0&&j!=0);
		//printf("(%d %d %d %d)->(%d %d %d %d)\n",i,f1,f2,sum,i+1,nf1,nf2,nsum);
		f+=dfs(i+1,nf1,nf2,nsum);
	}
	//printf("#%d %d %d %d %d\n",i,f1,f2,sum,f);
	return f;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&k);
	printf("%d\n",dfs(1,1,1,0));
	return 0;
}