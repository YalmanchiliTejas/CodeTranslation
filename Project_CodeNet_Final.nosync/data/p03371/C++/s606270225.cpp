#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)


int main(void) {
	int a, b, c, x, y; cin >> a >> b >> c >> x >> y;

	int ans = 1e9;
	for (int i = 0; i <= 2 * max(x, y); ++i) {
		int cntx = max(x - i / 2 + (i % 2 ? 1 : 0), 0);
		int cnty = max(y - i / 2 + (i % 2 ? 1 : 0), 0);
		// printf("%d %d %d\n", i, cntx, cnty);
		ans = min(ans, a * cntx + b * cnty + c * i);
	}
	printf("%d\n", ans);
	return 0;
}