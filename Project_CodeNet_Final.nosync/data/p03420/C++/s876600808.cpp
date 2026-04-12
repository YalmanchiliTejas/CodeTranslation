#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i, s, t) for(i = s; i <= t; ++i)
#define dep(i, s, t) for(i = s; i >= t; --i)

using namespace std;

typedef long long LL;
int n, k;
LL ans;

int main() {
	int i, j, l, r;
	scanf("%d%d", &n, &k);
	rep(i, k+1, n)
		for(l = k, r = i-1; l <= n; l += i, r += i) ans += (LL)min(r, n) - max(l, 1) + 1;
	printf("%lld\n", ans);
	return 0;
}