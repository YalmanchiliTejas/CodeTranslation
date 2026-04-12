#include <bits/stdc++.h>
using namespace std;

long long st[200010];
int vis[200010];

int main() {
	int x, m;
	long long n;
	scanf("%lld%d%d", &n, &x, &m);
	memset(vis, -1, sizeof(vis));
	long long ans = 0;
	int i;
	long long j;
	for (i = 0, j = x; vis[j] == -1; ++i, j = j * j % m)
		vis[j] = i, st[i] = j;
	if (n <= vis[j]) {
		for (int k = 0; k < n; ++k)
			ans += st[k];
		printf("%lld\n", ans);
		return 0;
	}
	for (int k = 0; k <	vis[j]; ++k)
		ans += st[k];
	long long sum = 0;
	for (int k = vis[j]; k < i; ++k)
		sum += st[k];
	for (int k = 0; k < (n - vis[j]) % (i - vis[j]); ++k)
		ans += st[k + vis[j]];
	printf("%lld\n", ans + (n - vis[j]) / (i - vis[j]) * sum);
	return 0;
}

