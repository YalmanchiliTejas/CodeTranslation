#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2005;
int n, arr[mxn * 3], dp[mxn][mxn], rmx[mxn], cmx[mxn], mx, ormx[mxn], ocmx[mxn], omx;

void upd(int x, int y, int v) {
	if (v > dp[x][y]) {
		dp[x][y] = v;
		rmx[x] = max(rmx[x], v);
		cmx[y] = max(cmx[y], v);
		mx = max(mx, v);
	}
}

int main() {
	scanf("%d", &n);
	rep(i, n * 3) scanf("%d", &arr[i]), -- arr[i];
	memset(dp, -0x3f, sizeof(dp));
	memset(rmx, -0x3f, sizeof(rmx));
	memset(cmx, -0x3f, sizeof(cmx));
	mx = -0x3f3f3f3f;
	upd(arr[0], arr[1], 0);
	int temp = 0;
	rep(i, n - 1) {
		int c = arr[i * 3 + 2], d = arr[i * 3 + 3], e = arr[i * 3 + 4];
		memcpy(ormx, rmx, sizeof(rmx));
		memcpy(ocmx, cmx, sizeof(cmx));
		omx = mx;
		int occ = dp[c][c], odd = dp[d][d], oee = dp[e][e];
		static int nc[mxn], nd[mxn], ne[mxn];
		memset(nc, -0x3f, sizeof(nc));
		memset(nd, -0x3f, sizeof(nd));
		memset(ne, -0x3f, sizeof(ne));
		if (c == d && d == e) { ++ temp; continue; }
		if (c == d) rep(a, n) ne[a] = max(dp[a][c], dp[c][a]) + 1;
		if (d == e) rep(a, n) nc[a] = max(dp[a][d], dp[d][a]) + 1;
		if (c == e) rep(a, n) nd[a] = max(dp[a][e], dp[e][a]) + 1;
		rep(a, n) upd(a, c, nc[a]);
		rep(a, n) upd(a, d, nd[a]);
		rep(a, n) upd(a, e, ne[a]);
		upd(d, e, occ + 1);
		upd(c, e, odd + 1);
		upd(c, d, oee + 1);
		upd(c, d, omx);
		upd(d, e, omx);
		upd(c, e, omx);
		rep(a, n) upd(a, c, max(ormx[a], ocmx[a]));
		rep(a, n) upd(a, d, max(ormx[a], ocmx[a]));
		rep(a, n) upd(a, e, max(ormx[a], ocmx[a]));
	}
	int ans = -0x3f3f3f3f;
	rep(a, n) rep(b, n) {
		int c = arr[n * 3 - 1];
		ans = max(ans, dp[a][b] + (a == b && b == c));
	}
	printf("%d\n", ans + temp);
	return 0;
}
