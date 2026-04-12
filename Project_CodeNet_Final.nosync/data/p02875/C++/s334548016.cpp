#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 998244353
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200000


long long rev(long long k) {
	long long x = MOD - 2;
	long long re = 1;
	while (x > 0) {
		if (x % 2 == 1) {
			re = (re*k) % MOD;
		}
		k = (k*k) % MOD;
		x /= 2;
	}
	return re;
}


int main() {
	long long a[N];
	f(i, N)a[i] = 0;
	long long n, k;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%lld", &n);
	n /= 2;
	x = 1;
	f(i, n)x = (x * 2) % MOD;
	y = x;
	z = 1;
	ans = 0;
	f(i, n+1) {
		if (i > 0) {
			x = (x*(n - i + 1)) % MOD;
			x = (x*rev(i)) % MOD;
			x = (x*rev(2)) % MOD;
			y = (x+y) % MOD;
			if (i > 1) {
				z = (z*(n - i + 2)) % MOD;
				z = (z*rev(i-1)) % MOD;
				z = (z * 2) % MOD;
			}
			y = (y - z + MOD) % MOD;
		}
		s = ((2 * y) - x + MOD) % MOD;
		s = (s*x) % MOD;
		ans = (ans + s) % MOD;
	}
	printf("%lld\n", ans);


	return 0;
}