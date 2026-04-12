#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
const int MAX = 3e5 + 5;
int n, m;
int64 tree[4 * MAX], lazy[4 * MAX], dp[MAX];
vector <pair <int, int> > s[MAX];

void prop(int x, int st, int nd) {
	tree[x] += lazy[x];

	if(st != nd) {
		lazy[2 * x] += lazy[x];
		lazy[2 * x + 1] += lazy[x];
	}

	lazy[x] = 0;
}

void upd(int x, int st, int nd, int a, int b, int64 v) {
	prop(x, st, nd);

	if(st > b || nd < a)
		return;

	if(st >= a && nd <= b) {
		lazy[x] = v;
		prop(x, st, nd);
		return;
	}

	int mid = (st + nd) >> 1;

	upd(2 * x, st, mid, a, b, v);
	upd(2 * x + 1, mid + 1, nd, a, b, v);

	tree[x] = min(tree[2 * x], tree[2 * x + 1]);
}

int64 query(int x, int st, int nd, int a, int b) {
	prop(x, st, nd);

	if(st > b || nd < a)
		return LLONG_MAX;

	if(st >= a && nd <= b)
		return tree[x];

	int mid = (st + nd) >> 1;

	return min(query(2 * x, st, mid, a, b), query(2 * x + 1, mid + 1, nd, a, b));
}

int main() {
	scanf("%d%d", &n, &m);

	int64 sum = 0;
	for(int i = 1; i <= m; i++) {
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		s[l].push_back({r, c});
		sum += c;
	}

	for(int i = n; i > 0; i--) {
		upd(1, 1, n, i, i, dp[i + 2]);

		for(auto o : s[i])
			upd(1, 1, n, o.first, n, o.second);

		dp[i] = min(dp[i + 1], query(1, 1, n, i, n));
	}

	printf("%lld\n", sum - dp[1]);
	return 0;
}