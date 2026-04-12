#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
const int inf = 1012345678;
int n, x[200009], y[200009], c[200009]; pair<int, int> w[400009];
int main() {
	scanf("%d", &n);
	int pl1 = inf, pr1 = -inf, ql1 = inf, qr1 = -inf;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		if (x[i] > y[i]) swap(x[i], y[i]);
		pl1 = min(pl1, x[i]);
		pr1 = max(pr1, x[i]);
		ql1 = min(ql1, y[i]);
		qr1 = max(qr1, y[i]);
		w[i] = make_pair(x[i], i);
		w[n + i] = make_pair(y[i], i);
	}
	sort(w, w + 2 * n);
	fill(c, c + n, 2);
	int two = n, r = 0;
	long long ret = 1LL * (pr1 - pl1) * (qr1 - ql1);
	for (int i = 0; i <= 2 * n; i++) {
		while (r < 2 * n && two >= 1) {
			if (c[w[r].second]-- == 2) two--;
			r++;
		}
		if (two == 0) ret = min(ret, 1LL * (w[2 * n - 1].first - w[0].first) * (w[r - 1].first - w[i].first));
		if (i != 2 * n) {
			c[w[i].second]++;
			if (c[w[i].second] == 2) two++;
		}
	}
	printf("%lld\n", ret);
	return 0;
}