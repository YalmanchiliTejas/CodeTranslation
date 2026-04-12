#include<bits/stdc++.h>
using namespace std;

const int maxn=3005,mod=998244353;
int a[maxn];
long long dp[maxn][maxn][3];
int n,s;

int main()
{
	scanf("%d %d",&n,&s);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	dp[0][0][0]=1;
	for(int i=1; i<=n; ++i) {
		for(int j=0; j<=s; ++j) {
			(dp[i][j][0]+=dp[i-1][j][0])%=mod;
			(dp[i][j][1]+=dp[i-1][j][0]+dp[i-1][j][1])%=mod;
			(dp[i][j][2]+=dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2])%=mod;
			if(j+a[i]<=s) {
				(dp[i][j+a[i]][1]+=dp[i-1][j][0]+dp[i-1][j][1])%=mod;
				(dp[i][j+a[i]][2]+=dp[i-1][j][0]+dp[i-1][j][1])%=mod;
			}
		}
	}
	printf("%lld",dp[n][s][2]);
}