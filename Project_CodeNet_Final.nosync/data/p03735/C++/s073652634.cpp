#include <bits/stdc++.h>
#define F(i, x, y) for (int i = (x); i <= (y); ++i)
#define Fr(i, x, y) for (int i = (x); i < (y); ++i)
using namespace std;
typedef long long ll;

const int N = 200000 + 5;
int n, a[N], b[N], nd[N];
struct node {
	int bmx, bmn, rmx, rmn;
	node() { bmx = rmx = 0xcfcfcfcf; bmn = rmn = 0x3f3f3f3f; }
	void reset() {  bmx = rmx = 0xcfcfcfcf; bmn = rmn = 0x3f3f3f3f; }
	void add(int x, int y) {
		bmx = max(bmx, x);
		bmn = min(bmn, x);
		rmx = max(rmx, y);
		rmn = min(rmn, y); 
	}
	ll get() { return (ll)(bmx - bmn) * (rmx - rmn); }
}chance[N][41];

ll solve() {
	F(i, 1, n) {
		for (int k = 1; k <= 5; ++k) chance[i][k].reset();
		int t =  nd[i];
		F(j, 1, 5) {
			node cp = chance[i - 1][j];
			cp.add(a[t], b[t]);
			for (int k = 5; k >= 1; --k)
				if (chance[i][k].get() > cp.get()) {
					for (int lst = 1; lst < k; ++lst) chance[i][lst] = chance[i][lst + 1];
					chance[i][k] = cp;
					break;
				}
			cp = chance[i - 1][j];
			cp.add(b[t], a[t]);
			for (int k = 5; k >= 1; --k)
				if (chance[i][k].get() > cp.get()) {
					for (int lst = 1; lst < k; ++lst) chance[i][lst] = chance[i][lst + 1];
					chance[i][k] = cp;
					break;
				}
		}
	}
	
	ll ans = 0x3f3f3f3f3f3f3f3fll;
	for (int i = 1; i <= 5; ++i) ans = min(ans, chance[n][i].get());
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	F(i, 1, n) {
		cin >> a[i] >> b[i];
		nd[i] = i;
	}
	ll ans = 0x3f3f3f3f3f3f3f3fll;
	F(k, 1, 30) {
		random_shuffle(nd + 1, nd + n + 1);
		ans = min(ans, solve());
	}
	cout << ans << '\n';
	return 0;
}
