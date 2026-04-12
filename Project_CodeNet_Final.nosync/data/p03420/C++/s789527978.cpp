#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	long long ans = 0;
	for(int i=K+1; i<=N; ++i)
	{
		int div = N/i;
		int rem = N%i;
		ans += 1LL*div*(i-K) + max(rem-K+1, 0);
	}
	if(K==0) ans = 1LL*N*N;
	printf("%lld\n", ans);
	return 0;
}