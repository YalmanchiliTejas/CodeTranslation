#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <bitset>
#include <string>
#include <cmath>
#include <set>
#include <map>
#define Rep(i, x, y) for (int i = x; i <= y; i ++)
#define Dwn(i, x, y) for (int i = x; i >= y; i --)
#define RepE(i, x) for (int i = pos[x]; i; i = g[i].nex)
#define ev g[i].y
using namespace std;
typedef long long ll;
typedef double db;
const int N = 200010;
ll ans;
int mx, mn, mxa, mnb, k;
int n;
struct arr {
	int x, y;
	void r() {
		scanf ("%d%d", &x, &y);
		if (x > y) swap(x, y);
		mn = min(mn, x);
		mx = max(mx, y);
		mxa = max(mxa, x);
		mnb = min(mnb, y);
	}
} a[N];
bool cmp(arr a, arr b) { return a.x < b.x; }
int main()
{
	mn = mnb = k = 1 << 30;
	scanf ("%d", &n);
	Rep(i, 1, n) a[i].r();
	/* {
		scanf ("%d%d", &a[i], &b[i]);
		if (a[i] > b[i]) swap(a[i], b[i]);
	} */
	ans = ll(mxa - mn) * (mx - mnb);
	sort(a + 1, a + n + 1, cmp);
	Rep(i, 1, n - 1) {
		mxa = max(mxa, a[i].y);
		k = min(k, a[i].y);
		ans = min(ans, ll(mxa - min(a[i + 1].x, k)) * (mx - mn));
	}
	printf("%lld\n", ans);

	return 0;
}