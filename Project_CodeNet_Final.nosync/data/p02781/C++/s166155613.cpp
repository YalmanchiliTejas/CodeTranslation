#include<cstdio>
#include<cstring>
int l,k;
char s[110];
long long dp0[110][4],dp1[110][4];//可能等于、已经小于,第i位，用了j个非零数字


int main()
{
	//freopen("test.in","r",stdin);
	scanf("%s%d",s,&k);
	l=strlen(s);
	dp1[0][0]=1;//这一位小于，这一位是0
	dp0[0][0]=0;//这一位等于，这一位是0
	dp0[0][1]=1;
	dp1[0][1]=s[0]-'0'-1;
	for(int i=1;i<l;i++)
	{
		dp1[i][0]=1;//0
		for(int j=1;j<=k;j++)
		{
			if(s[i]=='0')
			{
				dp0[i][j]=dp0[i-1][j];//只能填一个0
				dp1[i][j]=dp1[i-1][j]+dp1[i-1][j-1]*9;
			}
			else
			{
				dp0[i][j]=dp0[i-1][j-1];
				dp1[i][j]=dp0[i-1][j-1]*(s[i]-'0'-1)+dp0[i-1][j]+dp1[i-1][j]+dp1[i-1][j-1]*9;
			}
		}
	}
	printf("%lld\n",dp0[l-1][k]+dp1[l-1][k]);
	return 0;
}
