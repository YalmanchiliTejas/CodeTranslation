#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
const int inf = 1e9 + 7;
int n, par[100010], ans = 0;
pair <pair <int, int>, int> a[100010]; bool dis[100010];
priority_queue<pair <int, pair <int, int> >, vector<pair <int, pair <int, int> > >, greater<pair <int, pair <int, int> > > > wl1, wl2;
int find(int a) {
	return (par[a] < 0 ? a : par[a] = find(par[a]));
}
void unionset(int a, int b) {
	int c = find(a), d = find(b);
	if(par[c] < par[d]) par[c] += par[d], par[d] = c;
	else par[d] += par[c], par[c] = d;
}
int main() {
	memset(par, -1, sizeof(par));
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].fi.fi, &a[i].fi.se);
		a[i].se = i;
	}
	sort(a, a + n);
	for(int i = 0; i < n-1; i++) {
		wl1.push({a[i+1].fi.fi - a[i].fi.fi, {a[i].se, a[i+1].se}});
		swap(a[i].fi.fi, a[i].fi.se);
	}
	swap(a[n-1].fi.fi, a[n-1].fi.se);
	sort(a, a + n);
	for(int i = 0; i < n-1; i++) wl2.push({a[i+1].fi.fi - a[i].fi.fi, {a[i].se, a[i+1].se}});
	for(int i = 1; i < n; i++) {
		while(find(wl1.top().se.fi) == find(wl1.top().se.se)) wl1.pop();
		while(find(wl2.top().se.fi) == find(wl2.top().se.se)) wl2.pop();
		int d1 = inf, d2 = inf, u1, u2, v1, v2;
		if(not wl1.empty()) d1 = wl1.top().fi, u1 = wl1.top().se.fi, v1 = wl1.top().se.se;
		if(not wl2.empty()) d2 = wl2.top().fi, u2 = wl2.top().se.fi, v2 = wl2.top().se.se;
		if(d1 < d2) {
			unionset(u1, v1);
			ans += d1;
		}
		else {
			unionset(u2, v2);
			ans += d2;
		}
	}
	printf("%d\n", ans);
}