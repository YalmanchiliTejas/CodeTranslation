#include<bits/stdc++.h>
using namespace std;
const int N=10005,M=105,mod=1e9+7;
inline int add(int &a,int b){a+=b;if(a>=mod)a-=mod;}
int dp[N][M][2],d,n;
char s[N];
int main()
{
	scanf("%s%d",s+1,&d);
	n=strlen(s+1);
	dp[0][0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<d;j++)
			for(int x=0;x<=9;x++)
				add(dp[i+1][(j+x)%d][1],dp[i][j][1]);
		for(int j=0;j<d;j++)
			for(int x=0;x<=s[i+1]-'0';x++)
				add(dp[i+1][(j+x)%d][x!=s[i+1]-'0'],dp[i][j][0]);
	}
	printf("%d\n",(dp[n][0][0]+dp[n][0][1]-1+mod)%mod);
	return 0;
}