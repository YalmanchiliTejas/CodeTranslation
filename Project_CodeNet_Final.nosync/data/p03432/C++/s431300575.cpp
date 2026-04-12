#include <bits/stdc++.h>

typedef long long int int64;
static const int64 mod = 998244353LL;
int64 inv[8003],fac[8003],invfac[8003];
int64 dp[203][8003];
int64 arr[3][16384];
int64 g[24];
int n,m;
int64 choice(int a,int b)
{
	if(a < b || b < 0) return 0;
	return fac[a] * invfac[b] % mod * invfac[a-b] % mod;
}
void fft(int64 *arr, int n)
{
	int j = 0;
	for(int i = 1;i < (1<<n);++i) {
		int k = (1<<(n-1));
		while((j&k)!=0) { j ^= k;k >>= 1; }
		j ^= k;
		if(i < j) std::swap(arr[i],arr[j]);
	}
	for(int i = 0;i < n;++i) {
		int step = (1<<i);
		for(int j = 0;j < (1<<n);j += (1<<(i+1))) {
			int64 w = 1;
			for(int k = 0;k < (1<<i);++k) {
				int64 v1 = arr[j+k], v2 = arr[j+k+step]*w%mod;
				arr[j+k] = (v1+v2)%mod;
				arr[j+k+step] = (v1-v2+mod)%mod;
				w = w * g[i+1] % mod;
			}
		}
	}
}
void ifft(int64 *arr, int n)
{
	fft(arr,n);
	int64 inv2 = 1;
	for(int k = 0;k < n;++k) inv2 = inv2 * inv[2] % mod;
	for(int i = 1;i < (1<<(n-1));++i) std::swap(arr[i],arr[(1<<n)-i]);
	for(int i = 0;i < (1<<n);++i) arr[i] = (arr[i] * inv2) % mod;
}
int main()
{
	scanf("%d%d",&n,&m);
	fac[0] = inv[1] = invfac[0] = invfac[1] = fac[1] = 1;
	for(int i = 2;i <= 8002;++i) {
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
		fac[i] = (fac[i-1] * i) % mod;
		invfac[i] = (invfac[i-1] * inv[i]) % mod;
	}
	g[23] = 31;
	for(int i = 22;i >= 0;--i) g[i] = (g[i+1]*g[i+1]) % mod;

	int64 *dp1 = arr[0], *dp2 = arr[1];
	dp1[0] = 1;
	for(int k = 1;k <= n;++k) {
		arr[2][k] = invfac[k+2];
	}
	fft(arr[2],14);
	for(int i = 1;i <= m;++i) {
		memcpy(dp2,dp1,sizeof(arr[0]));
		fft(dp2,14);
		for(int k = 0;k < 16384;++k) dp2[k] = (dp2[k] * arr[2][k]) % mod;
		ifft(dp2,14);
		for(int k = n+1;k < 16384;++k) dp2[k] = 0;
		for(int k = 0;k <= n;++k) dp2[k] = (dp2[k] * (k+1) % mod * (k+2) % mod + dp1[k] * (choice(k+1,2)+1)) % mod;
		std::swap(dp1,dp2);
	}
	/*
	dp[0][0] = 1;
	for(int i = 1;i <= m;++i) {
		for(int j = 0;j <= n;++j) {
			int64 val = 0;
			for(int k = 0;k < j;++k) {
				val += dp[i-1][k] * choice(j+2,k) % mod;
			}
			val += dp[i-1][j] * (choice(j+1,2)+1) % mod;
			dp[i][j] = val % mod;
		}
	}
	int64 ans = 0;
	for(int j = 0;j <= n;++j) {
		ans += dp[m][j] * choice(n,j) % mod;
	}
	*/
	int64 ans = 0;
	for(int j = 0;j <= n;++j) {
		ans += dp1[j] * fac[n] % mod * invfac[n-j] % mod;
	}
	ans %= mod;
	if(ans < 0) ans += mod;
	printf("%lld\n", ans);
}
