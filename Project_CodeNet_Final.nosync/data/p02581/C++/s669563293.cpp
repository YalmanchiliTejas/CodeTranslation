#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n, a[6005], dp[6005][6005], nex[6005], lst[6005], id[6005], bg[2005];
int extra, ans;

void solve_extra() {
	for (int i = 2; i + 2 < n * 3; i += 3) {
		if (a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
			++ extra;
			for (int j = i; j + 3 < n * 3; ++ j) a[j] = a[j + 3];
			-- n;
			return solve_extra();
		}
	}
}

bool F(int x, int y, int z) {
	return a[x] == a[y] && a[y] == a[z];
}

void upd(int a, int b, int v) {
	dp[a][b] = max(dp[a][b], v);
}

void extend(int a, int b, int c) {
	if (c == n * 3 - 1) { ans = max(ans, dp[a][b] + F(a, b, c)); return ; }
	int d = c + 1, e = d + 1;
	upd(a, c, dp[a][b] + F(b, d, e));
	upd(a, d, dp[a][b] + F(b, c, e));
	upd(a, e, dp[a][b] + F(b, c, d));
	upd(b, c, dp[a][b] + F(a, d, e));
	upd(b, d, dp[a][b] + F(a, c, e));
	upd(b, e, dp[a][b] + F(a, c, d));
	upd(c, d, dp[a][b] + F(a, b, e));
	upd(c, e, dp[a][b] + F(a, b, d));
	upd(d, e, dp[a][b] + F(a, b, c));
}

int main() {
	scanf("%d", &n);
	rep(i, n * 3) scanf("%d", &a[i]), -- a[i];
//	n = 2000;
//	rep(i, n * 3) a[i] = rand() % n;
	solve_extra();
	id[0] = id[1] = -1;
	rep(i, n) {
		bg[i] = i * 3 + 2;
		for (int j = i * 3 + 2; j <= i * 3 + 4 && j < n * 3; ++ j) id[j] = i;
	}
	rep(i, n) lst[i] = n * 3;
	for (int i = n * 3 - 1; ~i; -- i) {
		nex[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	memset(dp, -0x3f, sizeof(dp));
	dp[0][1] = 0;
	rep(j, n * 3) rep(i, j) {
		extend(i, j, bg[id[j] + 1]);
		if (id[j] < id[nex[i]]) extend(i, j, bg[id[nex[i]]]);
		if (id[j] < id[nex[j]]) extend(i, j, bg[id[nex[j]]]);
	}
	printf("%d\n", ans + extra);
	return 0;
}
