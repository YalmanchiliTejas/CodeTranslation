#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 2e5 + 10;

int n;
long long x[MAXN], y[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld%lld", x + i, y + i);
		if (x[i] < y[i]) swap(x[i], y[i]);
	}
	x[0] = LLONG_MIN;
	y[0] = LLONG_MAX;
	int max_pos = 0, min_pos = 0;
	for (int i = 1; i <= n; ++i) {
		if (x[max_pos] < x[i]) max_pos = i;
		if (y[min_pos] > y[i]) min_pos = i;
		if (y[min_pos] == y[i] && min_pos == max_pos)
			min_pos = i;
	}
	long long ans = LLONG_MAX;
	{ // case 1 : rmax == max, bmin == min
		long long rmax = x[max_pos], rmin = LLONG_MAX;
		long long bmin = y[min_pos], bmax = LLONG_MIN;
		for (int i = 1; i <= n; ++i) {
			rmin = min(rmin, x[i]);
			bmax = max(bmax, y[i]);
		}
		ans = min(ans, (rmax - rmin) * (bmax - bmin));
	}
	
	if (max_pos != min_pos) { // case2 : rmax == max, rmin == min
		long long rdiff = x[max_pos] - y[min_pos];
		set<pair<long long, long long> > sets;
		for (int i = 1; i <= n; ++i)
			sets.insert(make_pair(x[i], i));
		for (;;) {
			long long bdiff = sets.rbegin()->first - sets.begin()->first;
			ans = min(ans, rdiff * bdiff);
			pair<long long, long long> temp = *sets.rbegin();
			sets.erase(*sets.rbegin());
			if (temp.second == -1) break;
			sets.insert(make_pair(y[temp.second], -1));
		}
	}
	printf("%lld\n", ans);
}