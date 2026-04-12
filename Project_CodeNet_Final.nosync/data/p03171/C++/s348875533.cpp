// fest
#include <bits/stdc++.h>	

#define pb push_back
#define F first
#define S second
#define y1 dasdasfasfas
#define x1 wqdadfasfasfas
#define All(c) c.begin(), c.end()
#define SZ(A) (int((A).size()))
#define umap unordered_map
#define __ fflush(stdout)
#define FILENAME ""

typedef long long ll;
typedef long double ld;    

using namespace std;

void FREOPEN() {
	#ifdef LOCAL
		freopen(".in", "r", stdin);
		freopen("1.out", "w", stdout);
	#else
		//freopen(FILENAME".in", "r", stdin);
		//freopen(FILENAME".out", "w", stdout);
	#endif
}

inline double Time() {return (clock() * 1.0) / CLOCKS_PER_SEC; }             

const int N = 3001, inf = 1e9 * 2;

const ll MOD = 1e9 + 7ll, INF = 1e18;

const int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};
const int dy[] = {0, 0, 1, -1, -1, 1, 1, -1};

ll dp[N][N];

bool was[N][N];

int a[N];

ll solve(int l, int r, int player) {
	if (was[l][r]) return dp[l][r];
	was[l][r] = 1;
	if (l == r) {
		if (player) return dp[l][r] = -a[l];
		else return dp[l][r] = a[l];
	}
	if (!player) {
		dp[l][r] = max(solve(l + 1, r, 1) + a[l], solve(l, r - 1, 1) + a[r]);
	}
	else {
		dp[l][r] = min(solve(l + 1, r, 0) - a[l], solve(l, r - 1, 0) - a[r]);
	}
	return dp[l][r];
}

int main() {
	FREOPEN();
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d ", &a[i]);
	printf("%lld ", solve(1, n, 0));
	return 0;
}
