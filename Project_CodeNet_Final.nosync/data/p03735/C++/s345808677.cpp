#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 200000 + 5;
int n, x[N], y[N];
int mn = 1e9 + 10, mx = -1;

ll get(int s, int e, int v) {
	if (v <= s) return s - v;
	return v - e;
}

ll calc1() {
	int mx1 = -1, mx2 = -1, mn1 = 1e9 + 10, mn2 = 1e9 + 10;
	mx1 = mx, mn1 = mn;
	vector<pair<int, int> > v, u;
	for (int i = 0; i < n; ++i) {
		if (x[i] == mn) {
			mx2 = max(mx2, y[i]);
			mn2 = min(mn2, y[i]);
		}
		else if (y[i] == mx) {
			mx2 = max(mx2, x[i]);
			mn2 = min(mn2, x[i]);
		}
		else {
			v.push_back(make_pair(x[i], y[i]));
		}
	}
	random_shuffle(v.begin(), v.end());
	int xd, yd;
	int mn3 = 1e9 + 10, mx3 = -1;
	bool ok = true;
	while (1) {
		u.clear();
		for (int i = 0; i < v.size(); ++i) {
			xd = v[i].X, yd = v[i].Y;
			if (xd > yd) swap(xd, yd);
			if (xd >= mn2) mx2 = max(mx2, xd);
			else if (yd <= mx2) mn2 = min(mn2, yd);
			else u.push_back(make_pair(xd, yd));
			
		}
		u.swap(v);
		if (u.size() == v.size())
			break;
	}
	int xdd, ydd;
	for (int i = 0; i < v.size(); ++i) {
		xd = v[i].X, yd = v[i].Y;
		
		xdd = get(mn2, mx2, xd);
		ydd = get(mn2, mx2, yd);

		if (xdd < ydd) {
			mx2 = max(mx2, xd);
			mn2 = min(mn2, xd);
		}
		else {
			mx2 = max(mx2, yd);
			mn2 = min(mn2, yd);
		}
	}
	return (ll(mx1) - mn1) * (ll(mx2) - mn2);
}

ll calc2() {
	int mx1 = -1, mx2 = -1, mn1 = 1e9 + 10, mn2 = 1e9 + 10;
	mx1 = mx, mn2 = mn;
	for (int i = 0; i < n; ++i) {
		mn1 = min(mn1, y[i]);
		mx2 = max(mx2, x[i]);
	}
	return (ll(mx1) - mn1) * (ll(mx2) - mn2);
}

int main() {
	srand(time(0));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", x + i, y + i);
		mn = min(mn, min(x[i], y[i]));
		mx = max(mx, max(x[i], y[i]));
	}

	if (mn == mx) return puts("0"), 0;
	for (int i = 0; i < n; ++i)
		if (x[i] > y[i])
			swap(x[i], y[i]);

	printf("%lld\n", min(calc1(), calc2()));
	return 0;
}

