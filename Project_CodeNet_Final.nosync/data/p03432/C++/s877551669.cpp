#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
const int RT = 3;

int power(int x, int t)
{
	int ret = 1;
	while(t > 0) {
		if(t & 1) ret = 1LL * ret * x % MOD;
		x = 1LL * x * x % MOD;
		t >>= 1;
	}
	return ret;
}

void fft(int from[], int to[], int tp)
{
	int cur = 0;
	rep(i, 16384) {
		to[i] = from[cur];
		for(int j = 13; j >= 0; j --) {
			cur ^= 1 << j;
			if(cur >> j & 1) break;
		}
	}
	
	for(int d = 2; d <= 16384; d <<= 1) {
		int rt = power(RT, MOD - 1 + (MOD - 1) / d * tp);
		for(int i = 0; i < 16384; i += d) {
			int cr = 1;
			for(int j = i; j < i + (d >> 1); j ++) {
				int ev = to[j], od = 1LL * to[j + (d >> 1)] * cr % MOD;
				to[j] = (ev + od) % MOD;
				to[j + (d >> 1)] = (ev - od + MOD) % MOD;
				cr = 1LL * cr * rt % MOD;
			}
		}
	}
	
	if(tp == -1) {
		int invn = power(16384, MOD - 2);
		rep(i, 16384) to[i] = 1LL * to[i] * invn % MOD;
	}
}

void prod(int u[], int v[], int w[])
{
	fft(u, w, 1);
	fft(v, u, 1);
	rep(i, 16384) v[i] = 1LL * u[i] * w[i] % MOD;
	fft(v, w, -1);
}

int n, m;
int fac[8005], ifac[8005];
int dp[8005];

int cu[16384], cv[16384], cw[16384];
void trans_dp()
{
	memset(cu, 0, sizeof(cu));
	memset(cv, 0, sizeof(cv));
	for(int i = 0; i <= n; i ++) cu[i] = 1LL * dp[i] * ifac[i] % MOD;
	for(int i = 0; i <= n; i ++) cv[i] = ifac[i + 2];
	prod(cu, cv, cw);
	for(int i = 0; i <= n; i ++) cw[i] = 1LL * cw[i] * fac[i + 2] % MOD;
	for(int i = 0; i <= n; i ++) dp[i] = (cw[i] - 1LL * dp[i] * i % MOD + MOD) % MOD;
}

int main()
{
	fac[0] = 1;
	rep1(i, 8002) fac[i] = 1LL * fac[i - 1] * i % MOD;
	ifac[8002] = power(fac[8002], MOD - 2);
	for(int i = 8002; i >= 1; i --) ifac[i - 1] = 1LL * ifac[i] * i % MOD;
	
	scanf("%d%d", &n, &m);
	dp[0] = 1;
	
	rep(i, m) trans_dp();
	
	int ans = 0;
	for(int i = 0; i <= n; i ++) ans = (ans + 1LL * ifac[i] * ifac[n - i] % MOD * dp[i]) % MOD;
	ans = 1LL * ans * fac[n] % MOD;
	printf("%d\n", ans);
	return 0;
}