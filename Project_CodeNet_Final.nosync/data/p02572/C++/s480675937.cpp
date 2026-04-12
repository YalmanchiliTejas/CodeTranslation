#include<cstdio>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	long long A[200100];
	long long sum = 0;
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
		sum += A[i];
	}
	long long divisor = 1000000007;
	for (int i = 0; i < N - 1; i++) {
		sum -= A[i];
		ans += (A[i] * (sum % divisor)) % divisor;
		ans %= divisor;
	}
	printf("%lld\n", ans);
	return 0;
}
