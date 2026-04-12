#include <stdio.h>

int N; long long M;
int I[3030][3030]; long long inv[3030]={0,1},fact[3030]={1,1},ifact[3030]={1,1};

long long comb(int n, int k)
{
	return fact[n] * ifact[k] % M * ifact[n-k] % M;
}

void add(int &a, int b)
{
	a += b;
	if (a >= M)
		a -= M;
}

long long fpow(long long a, long long p, long long m = M)
{
	long long r = 1;
	while (p){
		if (p & 1) r = r * a % m;
		a = a * a % m;
		p /= 2;
	}
	return r;
}

long long tpow(int p)
{
	return fpow(2,fpow(2,p,M-1),M);
}

int main()
{
	scanf ("%d %lld",&N,&M);

	for (int i=2;i<=N;i++){
		inv[i] = (M - M / i) * inv[M % i] % M;
		fact[i] = fact[i-1] * i %  M;
		ifact[i] = ifact[i-1] * inv[i] % M;
	}

	I[0][0] = 1;
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++) if (I[i][j]){
			add(I[i+1][j+1],I[i][j]);
			add(I[i+1][j],I[i][j]*(j+1ll)%M);
		}
	}

	int ans = 0;
	for (int i=0;i<=N;i++){
		long long rem = fpow(2,N-i), mul = 1; int sum = 0;
		for (int j=0;j<=N;j++){
			add(sum, I[i][j] * mul % M);
			mul = mul * rem % M;
		}

		long long coeff = tpow(N-i) * comb(N,i) % M;
		if (i % 2) coeff = M - coeff;
		add(ans, coeff * sum % M);
	}

	printf ("%d\n",ans);

	return 0;
}