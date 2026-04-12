#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

const int N = 4e5 + 10;
multiset<int> a, b;
P p[N];

ll getans() {
	return 1LL * (*a.rbegin() - *a.begin()) * (*b.rbegin() - *b.begin());
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &p[i].first, &p[i].second);
		if (p[i].first > p[i].second)
			swap(p[i].first, p[i].second);
		a.insert(p[i].first);
		b.insert(p[i].second);
	}
	sort(p + 1, p + n + 1);
	ll ans = getans();
	for (int i = 1; i <= n; i++) {
		int x = p[i].first, y = p[i].second;
		a.erase(a.find(x));
		b.erase(b.find(y));
		b.insert(x);
		a.insert(y);
		ans = min(ans, getans());
	}
	printf("%lld\n", ans);
	return 0;
}