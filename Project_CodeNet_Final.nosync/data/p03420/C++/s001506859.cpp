#include <cstdio>
using namespace std;

long long N, K;
long long cnt;

long long maxlld(long long a, long long b)
{
	return a > b ? a : b;
}

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	N = (long long)n;
	K = (long long)k;
	
	if (K == 0)
		printf("%lld", N * N);
	else
	{
		cnt = 0LL;
		for (long long b = K + 1; b <= N; ++b)
		{
			long long temp = (b - K) * (N / b);
			if (N % b > 0)
				temp += maxlld(0, N % b - K + 1);
			//printf("b = %d then pile = %d, cnt = %lld\n", b, N / b, temp);
			cnt += temp;
		}
		printf("%lld", cnt);
	}
	return 0;
}