#include <stdio.h>
#include <algorithm>
using namespace std;
int n, x, y, d, p, a[100], c[100]; double b[100];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d%d", &x, &y, &d);
		for(int j = 0; j < d; j++) scanf("%d%lf%d", &a[j], &b[j], &c[j]);
		int ret = 0;
		for(int j = 0; j < d; j++) {
			int r = x, s = 0;
			if(a[j] == 0) {
				for(int k = 0; k < y; k++) s += r * b[j], r -= c[j];
				r += s;
			}
			else {
				for(int k = 0; k < y; k++) r = r * (1 + b[j]) - c[j];
			}
			ret = max(ret, r);
		}
		printf("%d\n", ret);
	}
	return 0;
}