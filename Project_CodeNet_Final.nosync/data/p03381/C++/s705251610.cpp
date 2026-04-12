#include<stdio.h>
#include<algorithm>
#include<functional>
#include<cmath>
using namespace std;
long long  mod = 1000000007;
long long X[200000], Y[200000];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &X[i]);
		Y[i] = X[i];
	}
	sort(Y, Y + N);
	long long an1 = Y[N / 2], an2 = Y[N / 2 - 1];
	//printf("%lld %lld\n", an1, an2);
	for (int i = 0; i < N; i++) {
		if (X[i] < an1) {
			printf("%lld\n", an1);
		}
		else {
			printf("%lld\n", an2);
		}
	}
	return 0;
}