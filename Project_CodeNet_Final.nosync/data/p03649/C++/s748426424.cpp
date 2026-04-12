#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int MaxN = 50;
int n;
LL a[MaxN + 5];
LL b[MaxN + 5];
LL pred[MaxN + 5];
LL succ[MaxN + 5];

int main()
{
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		LL cnt = 0;
		while (true) {
			sort(a + 1, a + n + 1);
			if (a[n] < n) break;
			for (int i = 1; i <= n; i++) b[i] = a[i] / n;
			pred[0] = succ[n + 1] = 0;
			for (int i = 1; i <= n; i++) pred[i] = pred[i - 1] + b[i];
			for (int i = n; i >= 1; i--) succ[i] = succ[i + 1] + b[i];
			for (int i = 1; i <= n; i++) a[i] = a[i] % n + pred[i - 1] + succ[i + 1];
			cnt += pred[n];
		}
		printf("%lld\n", cnt);
	}
	return 0;
}