#include <cstdio>
const int MOD = 998244353;
const int MAXN = 10000000;
int sub(int x, int y) {return x - y < 0 ? x - y + MOD : x - y;}
int pow_mod(int b, int p) {
	int ret = 1;
	while( p ) {
		if( p & 1 ) ret = 1LL*ret*b%MOD;
		b = 1LL*b*b%MOD;
		p >>= 1;
	}
	return ret;
}
int pw2[MAXN + 5], fct[MAXN + 5], ifct[MAXN + 5];
void init() {
	pw2[0] = 1;
	for(int i=1;i<=MAXN;i++)
		pw2[i] = 2LL*pw2[i-1]%MOD;
	fct[0] = 1;
	for(int i=1;i<=MAXN;i++)
		fct[i] = 1LL*fct[i-1]*i%MOD;
	ifct[MAXN] = pow_mod(fct[MAXN], MOD-2);
	for(int i=MAXN-1;i>=0;i--)
		ifct[i] = 1LL*ifct[i+1]*(i+1)%MOD;
}
int comb(int n, int m) {
	return 1LL*fct[n]*ifct[m]%MOD*ifct[n-m]%MOD;
}
int main() {
	init();	int N;
	scanf("%d", &N);
	int ans = pow_mod(3, N);
	for(int i=N/2+1;i<=N;i++)
		ans = sub(ans, 2LL*comb(N, i)*pw2[N-i]%MOD);
	printf("%d\n", ans);
}