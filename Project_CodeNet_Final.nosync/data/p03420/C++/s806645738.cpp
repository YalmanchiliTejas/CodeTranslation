#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	long long res = 0;
	for(int b = 1; b <= n; ++b) {
		res += n / b * max(0, b - k);
		res += max(0, (n % b) - k + 1);
	}
	if(k == 0) res -= n;
	printf("%lld\n", res);
}