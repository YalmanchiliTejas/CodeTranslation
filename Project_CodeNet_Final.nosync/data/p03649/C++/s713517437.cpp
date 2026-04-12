#include <cstdio>
using namespace std;

typedef long long LL;
const int N = 55;
LL n, ans, a[N];

template <class T> inline void in(T &x) {
	x = 0; int f = 1; char ch = getchar();
	for (; ch<'0' || ch>'9';) {if (ch=='-') f=-1; ch = getchar();}
	for (; ch>='0' && ch<='9';) x = x*10 + ch-'0', ch = getchar();
	x *= f;
}

inline void work() {
	LL p, sum; in(n);
	for (int i = 1; i <= n; ++i) in(a[i]);
	for (;;) {
		sum = 0;
		for (int i = 1; i <= n; ++i) sum += a[i] / n;
		if (!sum) break;
		ans += sum;
		for (int i = 1; i <= n; ++i) {
			p = a[i] / n;
			a[i] += sum - p;
			a[i] -= p * n;
		}
	}
	printf("%lld\n", ans);
}

int main() {work(); return 0;}