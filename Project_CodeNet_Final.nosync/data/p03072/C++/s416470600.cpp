#include <bits/stdc++.h>

using namespace std;

int n, a[25];

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	int res = 0;
	int mx = 0;
	
	for (int i = 0; i < n; i++) {
		mx = max(mx, a[i]);
		if (mx == a[i]) res++;
	}
	
	printf("%d\n", res);
}
