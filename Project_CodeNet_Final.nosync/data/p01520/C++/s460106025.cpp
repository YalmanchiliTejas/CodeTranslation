#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int main() {
	int n, t, e; scanf("%d%d%d", &n, &t, &e);
	rep(i, n) {
		int x; scanf("%d", &x);
		int k = (t + e) / x;
		if (t - e <= k*x) {
			printf("%d\n", i + 1);
			return 0;
		}
	}
	puts("-1");
}