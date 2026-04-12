//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100000

int n, k;

int input() {
	if (scanf("%d %d", &n, &k) < 0) return 0;
	return 1;
}

void init() {
}

long solve() {
	long ans = 0;
	for (int b=1; b<=n; b++) {
		int p = n/b, r = n%b;
		long d = long(p) * max(0, b-k) + max(0, r-k+1);
		ans += d;
	}
	if (k==0) ans-=n;
	return ans;
}

void output(long ans) {
	printf("%ld\n", ans);
}

void cleanup() {
}

int main() {
	//int ca; scanf("%d", &ca);
	while (input()) {
		init();
		output(solve());
		cleanup();
		//break;
	}
}



