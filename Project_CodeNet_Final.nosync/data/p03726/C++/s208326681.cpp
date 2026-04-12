#include <bits/stdc++.h>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "a"
#define MAXN 2000002

int n;
vector <int> g[MAXN];
int d[MAXN];
int f[MAXN];

void dfs(int v = 0, int pr = -1) {
	int k = 0;
	int kd = 0;
	int kf = 0;
	for (const int& v2 : g[v]) {
		if (v2 == pr) continue;
		dfs(v2, v);
		if (d[v2]) ++kd;
		if (f[v2]) ++kf;
		++k;
	}
	if (kd) {
		f[v] = 1;
	}
	if (!k || (kf == k)) {
		d[v] = 1;
	}
	if (kd > 1 || (!v && d[v])) {
		puts("First");
		exit(0);
	}
}

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		--v1, --v2;
		g[v1].pb(v2);
		g[v2].pb(v1);
	}

	dfs();
	puts("Second");

	return 0;
}
