#include<bits/stdc++.h>
#define pii pair<int, int>
#define LL long long
#define mp make_pair
#define pb push_back
#define x first
#define y second
using namespace std;
const int maxn = 2e3 + 10;
int dp[maxn][maxn], ans, add, g[maxn];
vector<pair<pii, int>> vec;
int n, m, v[maxn * 3]; 

void singleInsert(int a, int b, int c) {
	vec.pb(mp(mp(b, c), dp[a][a] + 1));
	for (int i = 1; i <= n; ++i)
		vec.pb(mp(mp(i, a), g[i]));
}

void doubleInsert(int a, int b, int c) {
	if (a == b) {
		for (int i = 1; i <= n; ++i)
			vec.pb(mp(mp(i, c), dp[a][i] + 1));
	}
	vec.pb(mp(mp(a, b), ans)); 
}

void upd(int i, int j, int k) {
	dp[i][j] = max(dp[i][j], k);
	g[i] = max(g[i], k);
	ans = max(ans, k);
}

int main() {
	#ifdef DEBUG
	freopen("text.in", "r", stdin);
	freopen("wa.out", "w", stdout);
	#endif
	scanf("%d", &n);
	m = n * 3;
	for (int i = 1; i <= m; ++i)
		scanf("%d", &v[i]);
	for (int i = 1; i <= n; ++i) {
		g[i] = -m;
		for (int j = 1; j <= n; ++j)
			dp[i][j] = -m;
	}
	dp[v[1]][v[2]] = dp[v[2]][v[1]] = 0; g[v[1]] = g[v[2]] = 0;
	for (int i = 3, a, b, c; i + 2 <= m; i += 3) {
		vec.clear();
		a = v[i]; b = v[i + 1]; c = v[i + 2];
		if (a == b && a == c) { ++add; continue; } //allInsert
		singleInsert(a, b, c); singleInsert(b, a, c); singleInsert(c, a, b);
		doubleInsert(a, b, c); doubleInsert(a, c, b); doubleInsert(b, c, a);
		for (auto s : vec) {
			upd(s.x.x, s.x.y, s.y);
			upd(s.x.y, s.x.x, s.y);
		}
	}
	printf("%d\n", max(ans, dp[v[m]][v[m]] + 1) + add);
	return 0;
}
