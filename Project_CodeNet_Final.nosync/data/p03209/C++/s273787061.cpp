#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 100000;
typedef long long LL;
LL g[55];
LL f[55];
LL n, x;
int main() {
	g[1] = 5, f[1] = 3;
	for(int i = 2; i <= 50; i++) {
		g[i] = (g[i - 1] + 1) * 2 + 1;
		f[i] = f[i - 1] * 2 + 1;
	}
	LL ans = 0;
	scanf("%lld%lld", &n, &x);
	if(x <= n)ans = 0;
	else {
		for(int i = n; i >= 1; i--) {
			if(x >= g[i] + n - i) {
	//			printf("%lld %d %lld %lld\n", n - i, i, g[i], x);
				x -= (g[i] + n - i);
				ans += f[i];
				if(x)x--, ans++;
				n = i;
			}
		}
	//	printf("%lld %lld %lld\n", n, ans, x);
		if(x - n == 1)ans++;
		else if(x - n == 2)ans += 2;
		else if(x - n >= 3)ans += 3;
	}
	printf("%lld\n", ans);
	return 0;
}