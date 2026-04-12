#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for(int i = s; i <= e; ++i)
#define fto1(i, s, e) for(int i = s; i < e; ++i)
#define fdto(i, s, e) for(int i = s; i >= e; --i)
#define fit(var, it) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define frit(var, it) for(__typeof(var.rbegin()) it = var.rbegin(); it != var.rend(); ++it)

#define newl '\n'
#define debugt cerr << 0.001*clock() << newl
#define debug1(x, i) cout << #x << '[' << i << "] = " << x[i] << newl
#define debug(v, l, r) fto(_i, l, r) debug1(v, _i)
#define debug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << newl
#define debug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << newl

#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define glen(v) int((v).size())

template<typename T1, typename T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.ff << ", " << v.ss << ')';
}

#define eps 1e-15
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 3003

int n;
int a[maxn];
ll f[maxn][maxn][2];

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0);

	scanf("%d", &n);

	fto (i, 1, n) {
		scanf("%d", &a[i]);
		f[i][i][0] = a[i];
		f[i][i][1] = -a[i];
	}

	fdto (i, n-1, 1) {
		fto (j, i+1, n) {
			f[i][j][0] = max(f[i+1][j][1] + a[i], f[i][j-1][1] + a[j]);
			f[i][j][1] = min(f[i+1][j][0] - a[i], f[i][j-1][0] - a[j]);
		}
	}

	printf("%lld\n", f[1][n][0]);

	return 0;
}
