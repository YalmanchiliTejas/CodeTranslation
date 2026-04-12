/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); i++)
#define cont(i, n)          for(int i = 1; i <= (n); i++)
#define circ(i, a, b)       for(int i = (a); i <= (b); i++)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

int dp[2005][2005], mx[2005], nmx[2005], ndp[2005][2005];
int a[6005], n, jar, Mx, NMx;
map<pair<int, int>, int> zh;

int inline val(int i, int j) {
	return dp[i][j];
}

void inline zy(int i, int j, int v) {
	ndp[i][j] = max(ndp[i][j], v);
	ndp[j][i] = max(ndp[j][i], v);
	nmx[i] = max(nmx[i], v);
	nmx[j] = max(nmx[j], v);
	NMx = max(NMx, v);
}

int main() {
	scanf("%d", &n);
	cont(i, 3 * n) scanf("%d", a + i);
	cont(i, n) cont(j, n) dp[i][j] = -Inf;
	cont(i, n) mx[i] = -Inf;
	mx[a[1]] = mx[a[2]] = 0;
	Mx = 0;
	dp[a[1]][a[2]] = 0;
	memset(ndp, -1, sizeof(ndp));
	range(i, 3, 3 * n - 1, 3) {
		cont(j, n) nmx[j] = -Inf;
		NMx = -Inf; zh.clear();
		int p = a[i], q = a[i + 1], r = a[i + 2];
		if(p == q && q == r) {
			jar++; continue;
		}
		cont(j, n) {
			ndp[j][p] = dp[j][p]; ndp[j][q] = dp[j][q]; ndp[j][r] = dp[j][r];
			ndp[p][j] = dp[p][j]; ndp[q][j] = dp[q][j]; ndp[r][j] = dp[r][j];
		}
		if(p == q || q == r || p == r) {
			int Q = p ^ q ^ r, P = (p + q + r - Q) >> 1;
			cont(j, n) zy(j, Q, val(j, P) + 1);
		}
		zy(q, r, val(p, p) + 1);
		zy(p, r, val(q, q) + 1);
		zy(p, q, val(r, r) + 1);
		zy(q, r, Mx); zy(p, r, Mx); zy(p, q, Mx);
		cont(j, n) {
			zy(j, p, mx[j]);
			zy(j, q, mx[j]);
			zy(j, r, mx[j]);
		}
		cont(j, n) mx[j] = nmx[j];
		cont(j, n) {
			dp[j][p] = ndp[j][p]; dp[j][q] = ndp[j][q]; dp[j][r] = ndp[j][r];
			dp[p][j] = ndp[p][j]; dp[q][j] = ndp[q][j]; dp[r][j] = ndp[r][j];
		}
		cont(j, n) {
			ndp[j][p] = ndp[j][q] = ndp[j][r] = -1;
			ndp[p][j] = ndp[q][j] = ndp[r][j] = -1;
		}
		Mx = NMx;
	}
	int res = dp[a[3 * n]][a[3 * n]] + 1;
	cont(i, n) cont(j, n) res = max(res, dp[i][j]);
	printf("%d\n", res + jar);
	return 0;
}
