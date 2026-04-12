#include<cstdio>
#define maxn 3005
#define ll long long
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
ll dp[maxn][maxn];
ll a[maxn];
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%lld",&a[i]),dp[i][i]=n&1?a[i]:-a[i];
	for (int i=2;i<=n;i++){
		for (int l=1;l<=n;l++){
			int r=l+i-1;
			if ((n-i+1)&1)dp[l][r]=max(dp[l+1][r]+a[l],dp[l][r-1]+a[r]);else
				dp[l][r]=min(dp[l+1][r]-a[l],dp[l][r-1]-a[r]);
		}
	}
	printf("%lld\n",dp[1][n]);
	return 0;
}
/*

*/
 