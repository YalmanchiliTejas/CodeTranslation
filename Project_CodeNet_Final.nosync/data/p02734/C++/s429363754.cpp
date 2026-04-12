//Link : https://codeforces.com/contest/1253

#include <stdio.h>
#include <vector>


using namespace std;
#define ll long long
#define N 3005
#define mod 998244353
/*
#include <limits.h>
INT_MAX
LLONG_MAX
*/
int add(int x, int y) {
	return ((x + y) % mod + mod) % mod;
}
int mul(int x, int y) {
	return (ll)x*y%mod;
}
int mypow(int x, int c) {
	int ret = 1;
	while (c > 0) {
		if (c & 1) {
			ret = mul(ret, x);
		}
		x = mul(x, x);
		c /= 2;
	}
	return ret;
}
int a[N], pp[N], tmp[N], ppp[N];
void solve() {
	int n, s;
	scanf("%d %d", &n,&s);
	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		for (int j = s - x; j >= 0; --j) {
			pp[j + x] = add(pp[j + x], pp[j]);
		}
		if (x <= s) {
			pp[x] = add(pp[x], i);
		}
		ret = add(ret, pp[s]);
	}
	printf("%d\n", ret);
}

int main() {
	//freopen("input.txt","r",stdin);
	solve();
	return 0;
}
