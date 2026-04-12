#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=3e3+10;
int n,a[N];ll dp[N][N][2];
int main(){
	scanf("%d",&n);
	for(register int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(register int i=1;i<=n;i++)dp[i][i][0]=a[i];
	for(register int i=1;i<=n;i++)dp[i][i][1]=-a[i];
	for(register int i=n;i;i--)
		for(register int j=i+1;j<=n;j++)
			dp[i][j][0]=max(dp[i][j-1][1]+a[j],dp[i+1][j][1]+a[i]),
			dp[i][j][1]=min(dp[i][j-1][0]-a[j],dp[i+1][j][0]-a[i]);
	printf("%lld\n",dp[1][n][0]);
	return 0;
}