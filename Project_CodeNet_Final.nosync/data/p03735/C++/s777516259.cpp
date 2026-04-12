# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn(2e5 + 5);

int n, x[maxn], y[maxn], bmx, bmn, rmx, rmn;
int premn[maxn], premx[maxn];
ll ans;
pair <int, int> vxy[maxn];

int main() {
	int i, p1, p2;
	scanf("%d", &n), rmn = bmn = 1e9;
	for (i = 1; i <= n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		if (x[i] > y[i]) swap(x[i], y[i]);
		bmx = max(bmx, y[i]), rmn = min(rmn, x[i]);
		rmx = max(rmx, x[i]), bmn = min(bmn, y[i]);
	}
	ans = (ll)(bmx - bmn) * (rmx - rmn);
	for (i = 1; i <= n; ++i) vxy[i] = make_pair(x[i], y[i]);
	bmn = rmn, sort(vxy + 1, vxy + n + 1);
	premn[1] = premx[1] = vxy[1].second;
	for (i = 2; i <= n; ++i) {
		premx[i] = max(premx[i - 1], vxy[i].second);
		premn[i] = min(premn[i - 1], vxy[i].second);
		if (i ^ n) ans = min(ans, (ll)(bmx - bmn) * (max(premx[i], vxy[n].first) - min(premn[i], vxy[i + 1].first)));
	}
	printf("%lld\n", ans);
	return 0;
}