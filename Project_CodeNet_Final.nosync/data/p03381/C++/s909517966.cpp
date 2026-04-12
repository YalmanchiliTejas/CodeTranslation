#include <cstdio>
#include <algorithm>
using namespace std;
int n, x[200010], a[200010];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", x+i);
		a[i] = x[i];
	}
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++) {
		int idx = lower_bound(a+1, a+n+1, x[i]) - a;
		if(idx <= n / 2) printf("%d\n", a[n/2+1]);
		else printf("%d\n", a[n/2]);
	}
	return 0;
}