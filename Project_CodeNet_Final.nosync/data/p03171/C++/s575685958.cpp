#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = (3e3) + 3;
bool done1[N][N];
bool done2[N][N];
ll memo1[N][N];
ll memo2[N][N];
int n, a[N];

ll DP1(int i, int j);

ll DP2(int i, int j) {
	if (i > j) return 0;
	ll &ret = memo2[i][j];
	if (done2[i][j]) return ret;
	done2[i][j] = 1;
	ret = min(-a[i] + DP1(i + 1, j), -a[j] + DP1(i, j - 1));
	return ret;
}

ll DP1(int i, int j) {
	if (i > j) return 0;
	ll &ret = memo1[i][j];
	if (done1[i][j]) return ret;
	done1[i][j] = 1;
	ret = max(a[i] + DP2(i + 1, j), a[j] + DP2(i, j - 1));
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	ll ans = DP1(0, n - 1);
	printf("%lld\n", ans);
	return 0;
}