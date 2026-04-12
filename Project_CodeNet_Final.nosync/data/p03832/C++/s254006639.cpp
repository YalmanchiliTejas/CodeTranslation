#include <cstdio>

int N, A, B, C2, D2;
long long memo[1100][1100];
long long D = 1000000007;
long long C[1100][1100];
long long nP[1100];

long long calc(long long ii)
{
	long long r = 1;
	long long b = D-2;
	long long x = ii;
	while(b>0){
		if(b % 2 == 1){
			r *= x;
			r %= D;
		}
		b /= 2;
		x *= x;
		x %= D;
	}
	return r;
}

void pre()
{
	int i, j;
	for(i=0; i<=N; i++){
		C[i][0] = 1;
		C[i][i] = 1;
	}
	for(i=1; i<=N; i++){
		for(j=1; j<i; j++){
			C[i][j] = C[i-1][j] + C[i-1][j-1];
			C[i][j] %= D;
		}
	}
	nP[1] = 1;
	for(i=2; i<=N; i++){
		nP[i] = calc(i);
	}
}

void srch(int ii, int jj)
{
	int i;
	if(jj==A-1 && ii>0){
		memo[ii][jj] = 0;
		return ;
	}
	//if(jj>=A-1 && ii==0){
	if(ii==0){
		memo[ii][jj] = 1;
		return ;	
	}
	long long sum = 0;
	if(memo[ii][jj-1] == -1)
		srch(ii, jj-1);
	sum += memo[ii][jj-1];
	long long tmp = 1;
	long long tmp2 = 1;
	int i2 = ii;
	for(i=0; i<C2-1; i++){
		tmp *= C[i2][jj];
		tmp %= D;
		tmp *= nP[i+1];
		tmp %= D;
		i2 -= jj;
		if(i2<0){
			memo[ii][jj] = sum;
			return ;
		}
	}
	for(i=C2; i<=D2; i++){
		if(i2-jj<0)
			break;
		tmp *= C[i2][jj];
		tmp %= D;
		tmp *= nP[i];//tmp /= i;
		tmp %= D;
		if(memo[i2-jj][jj-1] == -1)
			srch(i2-jj, jj-1);
		tmp2 = tmp;
		tmp2 *= memo[i2-jj][jj-1];
		tmp2 %= D;
		sum += tmp2;
		sum %= D;
		i2 -= jj;
		//if(i2<0)
		//	break;
	}
	memo[ii][jj] = sum;
}

void solve()
{
	pre();
	int i, j;
	for(i=0; i<=N; i++){
		for(j=0; j<=N; j++)
			memo[i][j] = -1;
	}
	srch(N, B);
	printf("%lld\n", memo[N][B]);
}

int main()
{
	scanf("%d%d%d%d%d", &N, &A, &B, &C2, &D2);
	solve();
	return 0;
}