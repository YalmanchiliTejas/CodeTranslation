#include<cstdio>
#include<algorithm>
using namespace std;
long long n, K, res;
int main() {
	int i, j;
	scanf("%lld%lld", &n, &K);
	if (K == 0) {
		printf("%lld\n", n*n);
		return 0;
	}
	for (i = K + 1; i <= n; i++) {
		for (j = 1; j <= n; ) {
			if (j + i <= n) {
				res += i - K;
				j += i;
				continue;
			}
			if (j%i < K)j += K - (j%i);
			if (j > n)break;
			if(n%i)res += n - j + 1;
			else res += n - j;
			break;
		}
	}
	printf("%lld\n", res);
}