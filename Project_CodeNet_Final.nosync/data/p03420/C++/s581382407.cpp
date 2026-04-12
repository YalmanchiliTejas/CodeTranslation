#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define LL long long
using namespace std;
LL n, K;
LL _min(LL x, LL y) { return x < y ? x : y; }
int main() {
	LL i, j, k;
	scanf("%lld%lld", &n, &K);
	LL ans = 0;
	for(i = K+1; i <= n; i++){
		LL p = (n+1)/i*K+_min((n+1)%i, K)-1;
		if(p < 0) p = 0;
		ans += n-p;
	}
	printf("%lld\n", ans);
	return 0;
}