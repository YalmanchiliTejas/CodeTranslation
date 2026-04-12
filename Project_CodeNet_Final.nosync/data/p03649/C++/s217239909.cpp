#include <cstdio>

typedef long long int lli;

int main()
{
	lli mod[50], a[50];
	lli sum = 0, modSum;
	lli ans = 6 * 1e17;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
		mod[i] = a[i] % (N + 1);
		sum += a[i];
	}
	for (int i = 0; i < N + 1; i++) {
		modSum = 0;
		bool notCount = false;
		for (int j = 0; j < N; j++) {
			modSum += (mod[j] + i) % (N + 1);
			if ((mod[j] + i) % (N + 1) == N)
				notCount = true;
		}
		if (!notCount && ans > sum - modSum && sum - modSum >= 0)
			ans = sum - modSum;
	}
	printf("%lld\n", ans);
}