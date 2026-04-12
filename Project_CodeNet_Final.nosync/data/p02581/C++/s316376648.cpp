#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n, a[6005], dp[2005][2005], rmx[2005], mx;
int todo[100005][3], tsz;

void add_todo(int x, int y, int v) { todo[tsz][0] = x; todo[tsz][1] = y; todo[tsz ++][2] = v; }
void upd(int x, int y, int v) { rep(_, 2) { dp[x][y] = max(dp[x][y], v); rmx[x] = max(rmx[x], v); mx = max(mx, v); swap(x, y); } }
void fix() { rep(i, tsz) upd(todo[i][0], todo[i][1], todo[i][2]); tsz = 0; }

int main() {
	scanf("%d", &n);
	rep(i, n * 3) scanf("%d", &a[i]), -- a[i];
	memset(rmx, -0x3f, sizeof(rmx));
	memset(dp, -0x3f, sizeof(dp));
	mx = -0x3f3f3f3f;
	upd(a[0], a[1], 0);
	int extra = 0;
	rep(i, n - 1) {
		int x[3] = { a[i * 3 + 2], a[i * 3 + 3], a[i * 3 + 4] };
		if (x[0] == x[1] && x[1] == x[2]) { ++ extra; continue; }
		rep(_, 3) {
			add_todo(x[0], x[1], max(mx, dp[x[2]][x[2]] + 1));
			rep(j, n) {
				if (x[0] == x[1]) add_todo(j, x[2], dp[j][x[0]] + 1);
				add_todo(j, x[2], rmx[j]);
			}
			swap(x[0], x[1]); swap(x[1], x[2]);
		}
		fix();
	}
	int ans = mx;
	ans = max(ans, dp[a[n * 3 - 1]][a[n * 3 - 1]] + 1);
	printf("%d\n", ans + extra);
	return 0;
}
