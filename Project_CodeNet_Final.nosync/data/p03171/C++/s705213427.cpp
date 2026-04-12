#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

LL n;
LL a[3005];
LL dp[3005][3005] = {0};

int main(){
	scanf("%lld",&n);
	for(LL i = 1;i <= n;i ++){
		scanf("%lld",&a[i]);
		if(n & 1) dp[i][i] = a[i];
		else dp[i][i] = -a[i];
	}
	for(LL l = 1;l < n;l ++){
		for(LL i = 1;i < n;i ++){
			LL j = i + l; if(j > n) break;
			if((n - l - 1) & 1) dp[i][j] = min(dp[i + 1][j] - a[i],dp[i][j - 1] - a[j]);
			else dp[i][j] = max(dp[i + 1][j] + a[i],dp[i][j - 1] + a[j]);
		}
	}
	printf("%lld\n",dp[1][n]); 
	return 0;
}