#include <bits/stdc++.h>

typedef long long int int64;
static const int64 mod = 1000000007LL;

int n,m;
char s[200003];
int64 dp[200003],rdp[200003];
int64 solve(int n,int m) // divide circle of n into sections not longer than m
{
	dp[0] = rdp[0] = 1;
	for(int i = 1;i <= n;++i) {
		dp[i] = (rdp[i-1] - (i>=m+1?rdp[i-m-1]:0)) % mod;
		rdp[i] = (rdp[i-1] + dp[i]) % mod;
	}
	int64 ans = 0;
	for(int i = 1;i <= m;++i) {
		ans += (n-i>=0?rdp[n-i]:0) - (n-m-1>=0?rdp[n-m-1]:0);
	}
	return ans % mod;
}
int main()
{
	scanf("%d%d ",&n,&m);
	for(int i = 0;i < m;++i) {
		s[i] = getchar() == 'R' ? 0 : 1;
	}
	int len = 1;
	int maxlen = -1;
	for(int i = 1;i < m;++i) {
		s[i] ^= s[0];
		if(s[i] == 0) ++len;
		else {
			if(len == i) maxlen = (len%2==0?len+1:len);
			else if(len % 2 == 1) maxlen = std::min(maxlen,len);
			len = 0;
		}
	}
	int64 ans;
	if(len == m) {
		switch(n) {
		case 1: {
			ans = 1;
			break;
		}
		case 2: {
			ans = 3;
			break;
		}
		default: {
			dp[0] = dp[1] = 1;
			for(int i = 2;i <= n+1;++i) {
				dp[i] = (dp[i-1] + dp[i-2]) % mod;
			}
			ans = dp[n+1]-dp[n-3];
			break;
		}}
	} else {
		if(n%2==1) {
			ans = 0;
		} else {
			ans = solve(n/2,(maxlen+1)/2)*2;
		}
	}
	ans %= mod;
	if(ans < 0) ans += mod;
	printf("%lld\n", ans);
}
