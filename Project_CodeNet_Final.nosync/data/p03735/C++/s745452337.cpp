#include <bits/stdc++.h>
#define ls (o << 1)
#define rs (o << 1 | 1)
#define mid ((L + R) >> 1)
using namespace std;
typedef long long LL;
const int N = 200500;
const int mod = 998244353;
bool is[N];
int x[N], y[N], h[N], n;
bool cmp(const int &o, const int &p) { return x[o] < x[p]; }
bool cmp1(const int &o, const int &p) { return y[o] < y[p]; }
int main() {
#ifdef TEST
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		if (x[i] > y[i]) swap(x[i], y[i]);
		h[i] = i;
	}
	sort(h, h + n, cmp1);
	int mx = h[n - 1];
	LL ans = y[h[n - 1]] - y[h[0]];
	sort(h, h + n, cmp);
	int mn = h[0];
	ans *= x[h[n - 1]] - x[h[0]];
	if (mn == mx) {
		cout << ans << endl;
		return 0;
	}
	multiset<int> s;
	for (int i = 0; i < n; ++i) {
		if (i == mn) {
			s.insert(y[i]);
		} else {
			s.insert(x[i]);
		}
	}
	LL con = y[mx] - x[mn];
	int ans2 = *s.rbegin() - *s.begin();
	for (int i = 1; i < n; ++i) {
		if (h[i] == mx) continue;
		s.erase(s.find(x[h[i]]));
		s.insert(y[h[i]]);
		ans2 = min(ans2, *s.rbegin() - *s.begin());
	}
	cout << min(ans, con * ans2) << endl;
	return 0;
}
