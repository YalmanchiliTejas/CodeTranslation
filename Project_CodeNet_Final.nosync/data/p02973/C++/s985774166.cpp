#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
const int INF = 0x3f3f3f3f;

int n,a[maxn],q[maxn],f[maxn],res;
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
	}
	memset(q,0x3f,sizeof(q));
	q[0] = -INF;
	for (int i = 1; i <= n; i++) {
		f[i] = upper_bound(q + 1, q + n, -a[i]) - q;
		q[f[i]] = -a[i];
		res = max(res,f[i]);
	}
	printf("%d\n",res);
	return 0;
}