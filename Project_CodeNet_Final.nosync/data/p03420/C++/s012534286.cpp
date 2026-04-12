#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>

using namespace std;

typedef long long ll;

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	if (K == 0) return !printf("%lld\n", (ll)N*N);
	ll ans = 0;
	for (int i = K+1; i <= N; i++) {
		int p = N % i;
		ans += N / i * (i - K) + max(0, p-K+1);
	}
	printf("%lld\n", ans);
}