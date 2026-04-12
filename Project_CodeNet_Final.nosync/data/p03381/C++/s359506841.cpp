#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
struct data {
	int x, p;
	bool friend operator < (const data &a, const data &b) {
		return a.x < b.x;
	}
} a[maxn];
int n;
int p[maxn];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].x);
		a[i].p = i;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) {
		p[a[i].p] = i;
	}
	int o = (n + 1) / 2;
	for(int i = 1; i <= n; ++i) {
		if(p[i] <= o) {
			printf("%d\n", a[o + ((n & 1) ^ 1)].x);
		} else {
			printf("%d\n", a[o - (n & 1)].x);
		}
	}
	return 0;
}
