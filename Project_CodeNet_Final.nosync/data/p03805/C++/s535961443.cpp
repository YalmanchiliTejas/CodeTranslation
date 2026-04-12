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


int n, m;
int g[12][12];
ll d[1 << 10][10];

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		--v1, --v2;
		g[v1][v2] = 1;
		g[v2][v1] = 1;
	}

	d[1][0] = 1;
	for (int mask = 0; mask < (1 << n); ++mask) {
		for (int i = 0; i < n; ++i) {
			if (!d[mask][i]) continue;
			for (int j = 0; j < n; ++j) {
				if (((mask >> j) & 1) || !g[i][j]) continue;
				d[mask | (1 << j)][j] += d[mask][i];
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans += d[(1 << n) - 1][i];

	printf(I64"\n", ans);

	return 0;
}
