// Ball Coloring
// * frank_c1
// * 2017 / 09 / 30

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int maxn = (int)(1e6) + 5;
pii a[maxn];
int c[maxn];

int main() {
	int n, tot = 0;
	scanf("%d", &n);
	int mi = (int)(1e9), mx = 0, Mi = (int)(1e9), Mx = 0;
	for (int i = 1; i <= n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		if (x > y) swap(x, y); 
		a[++tot] = make_pair(x, i); a[++tot] = make_pair(y, i); 
		mi = min(mi, x); mi = min(mi, y); 
		mx = max(mx, x); mx = max(mx, y);
		Mi = min(Mi, y); Mx = max(Mx, x);
	} LL ret = 1LL * (Mx - mi) * (mx - Mi);
	sort(a + 1, a + tot + 1); 
	int ps = 1, cnt = 0;
	for (int i = 1; i <= tot; ++i) {
		int u = a[i].second; if (!c[u]) ++cnt; ++c[u];
		while (c[a[ps].second] > 1) --c[a[ps++].second]; if (cnt == n) ret = min(ret, 1LL * (mx - mi) * (a[i].first - a[ps].first));
	}
	return printf("%lld\n", ret), 0;
}