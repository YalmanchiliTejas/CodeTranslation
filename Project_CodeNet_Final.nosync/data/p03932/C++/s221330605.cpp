#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
typedef long long lint;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef unsigned long long ulint;
#define endl '\n'
#define fst first
#define sed second
#define pb push_back
#define mp make_pair
#define rint register int
#define newline putchar('\n')
#define leave_space putchar(' ')
#define all(x) (x).begin(), (x).end()
#define reveal(x) cerr << #x << " = " << (x) << endl
#define rep(it, f, e) for (rint it = (f); it <= (e); ++it)
#define per(it, f, e) for (rint it = (f); it >= (e); --it)
const int tx[] = {0, 1}, ty[] = {1, 0};
int n, m, mat[205][205];
int dp[205][205][205];
inline int dfs(int x1, int y1, int x2, int y2) {
	if (~dp[x1][y1][x2]) return dp[x1][y1][x2];
	int ret = 0, X1, Y1, X2, Y2;
	rep (i, 0, 1) {
		X1 = x1 + tx[i];
		Y1 = y1 + ty[i];
		rep (j, 0, 1) {
			X2 = x2 + tx[j];
			Y2 = y2 + ty[j];
			if (X1 == X2) continue;
			if (~mat[X1][Y1] && ~mat[X2][Y2])
			ret = max(ret, dfs(X1, Y1, X2, Y2));
		}
	}
	return dp[x1][y1][x2] = ret + mat[x1][y1] + mat[x2][y2];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	memset(mat, -1, sizeof(mat));
	rep (i, 1, n) {
		rep (j, 1, m) {
			cin >> mat[i][j];
		}
	}
	if (n < 3 || m < 3) {
		int ans = 0;
		rep (i, 1, n) {
			rep (j, 1, m) {
				ans += mat[i][j];
			}
		}
		cout << ans << endl;
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(1, 2, 2, 1) + mat[1][1] + mat[n][m] << endl;
	return 0;
}