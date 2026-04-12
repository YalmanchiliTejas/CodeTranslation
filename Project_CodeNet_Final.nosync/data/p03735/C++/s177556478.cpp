#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long i64;

const int NR = 4e5 + 10;

vector<int> vec[NR];
int x[NR], y[NR], li[NR], v[NR];
int n, len;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		li[++len] = x[i];
		li[++len] = y[i];
	}

	sort(li + 1, li + len + 1);

	len = unique(li + 1, li + len + 1) - li - 1;

	int l0 = li[1], r1 = li[len];
	int r0 = l0, l1 = r1;


	for (int i = 1; i <= n; ++i) {
		r0 = max(r0, min(x[i], y[i]));
		l1 = min(l1, max(x[i], y[i]));

		x[i] = lower_bound(li + 1, li + len + 1, x[i]) - li;
		y[i] = lower_bound(li + 1, li + len + 1, y[i]) - li;

		//printf("%d %d\n", x[i], y[i]);

		vec[x[i]].push_back(i);
		vec[y[i]].push_back(i);
	}

	int j = 0, cnt = 0;
	i64 ans = 1ll * (r0 - l0) * (r1 - l1);
	for (int i = 1; i <= len; ++i) {
		while (cnt < n && j < len) {
			++j;
			for (int k : vec[j]) {
				if (v[k] == 0) ++cnt;
				++v[k];
			}
		}
		if (cnt == n) ans = min(ans, 1ll * (r1 - l0) * (li[j] - li[i]));
		//printf("%d %d %d\n", i, j, cnt);
		for (int k : vec[i]) {
			--v[k];
			if (v[k] == 0) --cnt;
		}
	}

	printf("%lld\n", ans);
	return 0;
}