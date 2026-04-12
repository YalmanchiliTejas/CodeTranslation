//2017-05-06 16:50
//2017-05-06 15:04
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 2e5;
int n, pred[MaxN + 5], succ[MaxN + 5];
struct ARR {
	int x, y;
}a[MaxN + 5];

bool cmp(ARR A, ARR B) {return A.x < B.x;}
int main()
{
	while (~scanf("%d", &n)) {
		int MiN = 1 << 30;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &a[i].x, &a[i].y);
			if (a[i].x > a[i].y) swap(a[i].x, a[i].y);
			MiN = min(MiN, a[i].y);
		}
		sort(a + 1, a + n + 1, cmp);
		pred[0] = succ[n + 1] = 0;
		for (int i = 1; i <= n; i++) pred[i] = max(pred[i - 1], a[i].y);
		for (int i = n; i >= 1; i--) succ[i] = max(succ[i + 1], a[i].y);
		long long ans = ((long long)succ[1] - MiN) * ((long long)a[n].x - a[1].x);
		int pM = 1 << 30, MaX = 0;
		for (int i = 1; i <= n - 1; i++) {
			pM = min(pM, a[i].y);
			MiN = min(a[i + 1].x, pM);
			MaX = max(a[n].x, pred[i]);
			ans = min(ans, ((long long)MaX - MiN) * ((long long)succ[i + 1] - a[1].x));
		}
		printf("%lld\n", ans);
	}
	return 0;
}