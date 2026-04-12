#include <stdio.h>
#include <stdlib.h>

long long count;
long long pCnt;
int N;
long long X;
long long ansP[51] = { 1 };
long long ansC[51] = { 1 };

void b()
{
	count++;

	if (count >= X) {
		printf("%lld\n", pCnt);
		exit(0);
	}
}

void p()
{
	count++;
	pCnt++;

	if (count >= X) {
		printf("%lld\n", pCnt);
		exit(0);
	}
}

void barger(int level)
{
	if (X - count > ansC[level]) {
		count += ansC[level];
		pCnt += ansP[level];
		return;
	}
	if (level == 0) {
		p();
		return;
	}
	b();
	barger(level - 1);
	p();
	barger(level - 1);
	b();
	return;
}

int main() {

	for (int i = 1; i < 51; i++) {
		ansP[i] = 2 * ansP[i - 1] + 1;
		ansC[i] = 2 * ansC[i - 1] + 3;
	}

	scanf("%d %lld", &N, &X);

	barger(N);

	printf("%lld\n", pCnt);
	return 0;
}
