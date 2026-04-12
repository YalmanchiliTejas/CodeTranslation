#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int inf = 1e9 + 10;

int n;
int x[N], y[N];
int l[N * 2], r[N * 2];
int MIN, MAX;
long long ans = 1LL * inf * inf;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	MIN = inf, MAX = -inf;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		MIN = min(MIN, min(x[i], y[i]));
		MAX = max(MAX, max(x[i], y[i]));
	}

	// (MAX-?) (L) * (?-MIN) (R)
	int minL = inf, maxR = -inf;
	for (int i = 1; i <= n; ++i) {
		if (x[i] > y[i]) minL = min(minL, x[i]), maxR = max(maxR, y[i]);
		else minL = min(minL, y[i]), maxR = max(maxR, x[i]);
	}
	ans = min(ans, 1LL * (MAX-minL) * (maxR-MIN));


	// (MAX-MIN) * (?-?)
	vector<int> a;
	vector<int> z; // for compression
	int lim = inf; // cannot choose an element greater than lim as min of the second group
	for (int i = 1; i <= n; ++i) if (x[i] > y[i]) swap(x[i], y[i]); // (x,y) with x <= y
	for (int i = 1; i <= n; ++i) a.push_back(i);
	sort(a.begin(), a.end(), [&](int i, int j) {
		return x[i] < x[j] || (x[i] == x[j] && y[i] < y[j]); // according to x
	});
	for (int i = 1; i <= n; ++i) {
		z.push_back(x[i]), z.push_back(y[i]);
		lim = min(lim, y[i]);
	}
	sort(z.begin(), z.end()); // compress
	
	int ptr = 0;
	for (int i = 0; i < z.size(); ++i) l[i] = r[i] = -inf;
	for (int i = 0; i < z.size(); ++i) {
		while(ptr < n && x[a[ptr]] < z[i]) l[i] = max(l[i], y[a[ptr]]), ++ptr; // x must be in the first group
		if (i > 0) l[i] = max(l[i], l[i-1]); 
	}
	ptr = n - 1;
	for (int i = (int)z.size()-1; i >= 0; --i) {
		while(ptr >= 0 && x[a[ptr]] >= z[i]) r[i] = max(r[i], x[a[ptr]]), --ptr; // x can be freely assigned to any group
		if (i < (int)z.size()-1) r[i] = max(r[i], r[i+1]);
	}
	for (int i = 0; i < z.size(); ++i) {
		if (z[i] > lim) break;
		ans = min(ans, 1LL * (max(l[i], r[i]) - z[i]) * (MAX - MIN));
	}
	cout << ans << endl;
}