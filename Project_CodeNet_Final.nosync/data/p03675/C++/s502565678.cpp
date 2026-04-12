/* "It's okay if you hate me. I hate me too." */

#include <bits/stdc++.h>

using namespace std;

const int maxN = (int)2E5+5;

int n;
int a[maxN];
int b[maxN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	b[(n/2)+1] = a[1];
	int left = (n/2)+1, right = (n/2)+1;
	for (int i = 2; i <= n; ++i)
		if (i%2 == n%2) 
			b[--left] = a[i];
		else
			b[++right] = a[i];
	for (int i = 1; i <= n; ++i)
		printf("%d ", b[i]);
	puts("");
	return 0;
}
