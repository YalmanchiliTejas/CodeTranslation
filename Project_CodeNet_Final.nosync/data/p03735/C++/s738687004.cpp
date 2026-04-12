#include <stdio.h>
#include <algorithm>
#define ff first
#define ss second
using namespace std;
const int INF = 1e9, MAX_N = 2e5;
pair<long long, long long> b[MAX_N], mm1[MAX_N], mm2[MAX_N];

int main() {
	int n; scanf("%d", &n); --n;
	for (int i = 0; i <= n; ++i) {
		scanf("%lld%lld", &b[i].ff, &b[i].ss);
		if (b[i].ff > b[i].ss) swap(b[i].ff, b[i].ss);
	}
	sort(b, b + n + 1);
	for (long long MIN = INF, MAX = 0, i = 0; i < n; ++i)
		mm1[i] = make_pair(MIN = min(MIN, b[i].ss), MAX = max(MAX, b[i].ss));
	for (long long MIN = INF, MAX = 0, i = n; i > 0; --i)
		mm2[i] = make_pair(MIN = min(MIN, b[i].ss), MAX = max(MAX, b[i].ss));
	long long ans = (b[n].ff - b[0].ff) * (max(mm1[n - 1].ss, b[n].ss) - min(mm2[1].ff, b[0].ss));
	for (int i = 0; i < n; ++i)
		ans = min(ans, (max(b[n].ff, mm1[i].ss) - min(b[i + 1].ff, mm1[i].ff)) * (max(b[i].ff, mm2[i + 1].ss) - min(b[0].ff, mm2[i + 1].ff)));
	printf("%lld", ans);
	return 0;
}