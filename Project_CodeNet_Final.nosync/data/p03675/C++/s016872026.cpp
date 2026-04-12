#include <cstdio>
#define MAXN 200100
int perm[MAXN];
int a[MAXN];
int ans[MAXN];
int n;
void solve(void) {
	int sz = n, inc = -1, i;
	for(i = 1; i <= n; i++) {
		perm[i] = sz;
		sz += 2 * inc;
		if(sz == 0) {
			sz = 1;
			inc = -inc;
		} else if(sz == -1) {
			sz = 2;
			inc = -inc;
		}
	}
	for(i = 1; i <= n; i++) ans[i] = a[perm[i]];
}
int main(void) {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	solve();
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}