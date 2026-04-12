#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[3005][3005];
int a[3005];
int n;
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld", &a[i]);
	for(int i=1;i<=n;i++)dp[i][i]=a[i];
	for(int i=2;i<=n;i++)
		for(int j=1;i+j-1<=n;j++)
		dp[j][i+j-1]=max(a[j]-dp[j+1][i+j-1],-dp[j][i+j-2]+a[i+j-1]);
	printf("%lld\n",dp[1][n]);
}