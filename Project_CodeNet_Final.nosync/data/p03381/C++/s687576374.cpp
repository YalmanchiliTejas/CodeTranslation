#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, a[MAXN];
int c[MAXN], dx[MAXN], dx_top = 0;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), c[i] = a[i];
	int x1 = n/2, x2 = x1+1;
	nth_element(a+1, a+x1, a+n+1);
	int x = a[x1];
	nth_element(a+1, a+x2, a+n+1);
	int y = a[x2];
	// cerr << x << " " << y << endl;
	for (int i = 1; i <= n; i++) {
		if (c[i] <= x) printf("%d\n", y);
		else printf("%d\n", x);
	}
	return 0;
}
