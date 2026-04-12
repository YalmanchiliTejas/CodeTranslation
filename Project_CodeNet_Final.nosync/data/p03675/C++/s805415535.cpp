#include <cstdio>

int n, a[200005];

int index[200005];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	
	int cur = 0, idx[2] = {1, n};
	
	for (int i = n; i; --i) {
		index[idx[cur]] = i;
		
		if (cur == 0) ++idx[cur];
		else --idx[cur];
		
		cur ^= 1;
	}
	
	for (int i = 1; i <= n; ++i) printf(i == n ? "%d\n" : "%d ", a[index[i]]);
	
	return 0;
}