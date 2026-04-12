//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 200000

int n;
int a[MAXN], b[MAXN], c[MAXN];

int input() {
	if (scanf("%d", &n) < 0) return 0;
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	return 1;
}

void init() {
}

int solve() {
	for (int i=0; i<n; i++) b[i] = i;
	sort(b, b+n, [](auto &x, auto &y) {
		return a[x] < a[y];
	});
	int k = n/2-1, j;
	for (int i=0; i<n; i++) {
		if (i<=k) j = k+1;
		else j = k;
		c[b[i]] = a[b[j]];
	}
	return 1;
}

void output(int ans) {
	for (int i=0; i<n; i++)
		printf("%d\n", c[i]);
}

void cleanup() {
}

int main() {
	//int ca; scanf("%d", &ca);
	while (input()) {
		init();
		output(solve());
		cleanup();
		break;
	}
}


