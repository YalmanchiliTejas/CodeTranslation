#include <cstdio>
#include <algorithm>
#define N 100005
using namespace std;
int n, ans, pr[N];
struct st{int w, x, y;} a[N], b[N], c[N*2];
bool cmp(st p, st q) {return p.w<q.w;}
int f(int p) {return pr[p]==p ? p : pr[p]=f(pr[p]);}

int main() {
	int i, x, y;
	scanf("%d", &n);
	for(i=1; i<=n; i++) {
		scanf("%d%d", &a[i].w, &b[i].w);
		a[i].x = b[i].x = pr[i] = i;
	}
	sort(a+1, a+n+1, cmp);
	sort(b+1, b+n+1, cmp);
	for(i=1; i<n; i++) {
		c[i] = {a[i+1].w-a[i].w, a[i].x, a[i+1].x};
		c[i+n-1] = {b[i+1].w-b[i].w, b[i].x, b[i+1].x};
	}
	sort(c+1, c+2*n-1, cmp);
	for(i=1; i<2*n-1; i++) {
		x = f(c[i].x), y = f(c[i].y);
		if(x!=y) ans += c[i].w, pr[y] = x;
	}
	printf("%d", ans);
	return 0;
}