#include <stdio.h>
#include <string.h>

const int MAX_N = 10005;
const int MAX_D = 105;
const int MOD = 1000000007;

int n,d,dp[MAX_N][MAX_D][2];
char s[MAX_N];

int f(int p, int r, int l)
{
	if (p==n)
		return r==0;
	if (dp[p][r][l]!=-1)
		return dp[p][r][l];
	int ans=0;
	for (int i=(l?9:s[p]-'0'); i>=0; i--)
		ans=(ans+f(p+1,(r+i)%d,l|(i<s[p]-'0')))%MOD;
	return dp[p][r][l]=ans;
}

int main()
{
	scanf("%s",s);
	n=strlen(s);
	scanf("%d",&d);
	for (int i=0; i<n; i++)
		for (int r=0; r<d; r++)
			dp[i][r][0]=dp[i][r][1]=-1;
	printf("%d\n",(f(0,0,0)-1+MOD)%MOD);
	return 0;
}
