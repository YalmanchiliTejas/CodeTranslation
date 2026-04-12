#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define MOD 1000000007

long long int intpow(long long int base, long long int p)
{
	if (1 == p){
		return base;
	}

	if (0 == p % 2){
		long long int val = intpow(base, p / 2);
		return (val*val) % MOD;
	}
	else{
		return (intpow(base, p - 1) * base) % MOD;
	}
}

long long int comb(long long int n, long long int k)
{
	if (1 == n){
		return 1;
	}
	if (0 == k){
		return 1;
	}
	return (((comb(n - 1, k - 1)*n) % MOD) * intpow(k, MOD - 2)) % MOD;
}

void solv()
{
	long long int N, M, K; scanf("%lld%lld%lld", &N, &M, &K);

	long long int c = comb(N*M - 2, K - 2);
	long long int ret = 0;
	for (int d = 1; d < N; d++){
		long long int val = ((N - d)*M*M) % MOD;
		val = (val*(long long int)d) % MOD;
		val = (val*c) % MOD;
		ret = (ret + val) % MOD;
	}

	for (int d = 1; d < M; d++){
		long long int val = ((M - d)*N*N) % MOD;
		val = (val*(long long int)d) % MOD;
		val = (val*c) % MOD;
		ret = (ret + val) % MOD;
	}

	printf("%lld", ret);

	return;
}

int main()
{
	FILE *fin = NULL, *fout = NULL;
	//fin = freopen("input.txt", "r", stdin);
	//fout = freopen("output.txt", "w", stdout);

	solv();

	//finalize
	if (NULL != fin) fclose(fin);
	if (NULL != fout) fclose(fout);

	return 0;
}