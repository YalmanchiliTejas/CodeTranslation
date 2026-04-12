#include <cstdio>

const int MAXN = 3000;

int pow_mod(int b, int p, int m) {
	int ret = 1;
	while( p ) {
		if( p & 1 ) ret = 1LL*ret*b%m;
		b = 1LL*b*b%m;
		p >>= 1;
	}
	return ret;
}

int N, M;

int c[MAXN + 5][MAXN + 5], s[MAXN + 5][MAXN + 5], f[MAXN + 5][MAXN + 5];
void init() {
	for(int i=0;i<=MAXN;i++) {
		c[i][0] = 1;
		for(int j=1;j<=i;j++)
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % M;
	}
	s[0][0] = 1;
	for(int i=1;i<=MAXN;i++)
		for(int j=1;j<=i;j++)
			s[i][j] = (1LL*j*s[i-1][j]%M + s[i-1][j-1]) % M;
	for(int i=0;i<=MAXN;i++) {
		for(int j=1;j<=i;j++)
			f[i][j] = (1LL*(j + 1)*f[i-1][j]%M + f[i-1][j-1]) % M;
		f[i][0] = 1;
	}
}

int main() {
	scanf("%d%d", &N, &M); init();
	int ans = 0;
	
	for(int p=0;p<=N;p++) {
		int d = 1LL*pow_mod(M-1, p, M)*c[N][p]%M;
		d = 1LL*d*pow_mod(2, pow_mod(2, N-p, M-1), M)%M;
/*
		for(int j=0;j<=p;j++) {
			for(int k=0;k<=j;k++) {
				ans = (ans + 1LL*d*s[j][k]%M*c[p][j]%M*pow_mod(2, 1LL*k*(N-p)%(M-1), M)%M)%M;
			}
		}
*/
		int t = 1, q = pow_mod(2, N-p, M);
		for(int k=0;k<=p;k++,t=1LL*t*q%M)
			ans = (ans + 1LL*d*f[p][k]%M*t%M)%M;
	}
	
	printf("%d\n", ans);
}