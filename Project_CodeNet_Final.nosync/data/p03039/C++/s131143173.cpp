#include <cstdio>
#include <algorithm>
using namespace std;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	
	long long mod = 1000000007;	
	long long comb = 1;
	for(long long i = 1; i <= K-2; i++) {
		comb *= N * M - K + i;
		comb %= mod;
		comb *= modinv(i, mod);
		comb %= mod;
	}
	
	long long sum = 0;
	for(long long i = 1; i < N; i++) {
		sum += i * (N - i) * M * M;
		sum %= mod;
	}
	for(long long i = 1; i < M; i++) {
		sum += i * (M - i) * N * N;
		sum %= mod;
	}
	sum *= comb;
	sum %= mod;
	
	printf("%ld", sum);
	return 0;
}