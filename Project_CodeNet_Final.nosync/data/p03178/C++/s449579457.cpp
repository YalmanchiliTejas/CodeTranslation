#include<bits/stdc++.h>
using namespace std;
#define LL long long

int n,k;
char s[10005];
LL dp[10005][105];
int mod = 1e9+7;

int main() {
	scanf("%s",&s);
	scanf("%d",&k);
	n = strlen(s);
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
    for (int i=1; i<=n; i++) {
		for (int j=0; j<k; j++) {
			dp[i][j] = 0;
			for (int d=0; d<10; d++) {
				dp[i][j] += dp[i-1][((j-d)%k+k)%k];
			}
			dp[i][j] %= mod;
			//printf("  %d,%d = %lld\n",i,j,dp[i][j]);
		}
    }
    LL ret = 0;
    int rem = 0;
    for (int i=0; i<n; i++) {
		int dig = s[i]-'0';
		for (int j=0; j<dig; j++) {
			ret += dp[n-i-1][((rem-j)%k+k)%k];
			//printf("%d,%d + %lld = %lld\n",i,j,dp[n-i-1][((rem-j)%k+k)%k],ret);
		}
		ret %= mod;
		rem = ((rem-dig)%k+k)%k;
    }
    if (rem == 0) ret++;
    printf("%lld\n",(ret-1+mod)%mod);
	return 0;
}
