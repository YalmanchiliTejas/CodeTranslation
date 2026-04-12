#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const LL N = 1000000007;

LL dp[10005][105];
LL n,k,ans = 0;
string s;

int main(){
	cin >> s; n = s.length();
	cin >> k; s = ' ' + s;
	dp[0][0] = 1;
	for(LL i = 1;i <= n;i ++){
		for(LL j = 0;j <= 9;j ++){
			for(LL l = 0;l <= k;l ++){
				dp[i][(j + l) % k] += dp[i - 1][l];
				dp[i][(j + l) % k] %= N;
			}
		}
	}
	LL sdg = 0;
	for(LL i = 1;i <= n;i ++){
		for(LL j = 0;j < s[i] - '0';j ++){
			ans += dp[n - i][(k - (sdg + j) % k) % k];
			ans %= N;
		}
		sdg += (s[i] - '0');
		sdg %= k;
	}
	if(sdg == 0) ans ++;
	ans --; ans = (ans + N) % N;
	printf("%lld\n",ans);
	return 0;
}
//