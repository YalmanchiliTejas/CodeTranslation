#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, x, y, a[200005], b[200005];
int main() {
	int i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &a[i]), b[i] = a[i];
	sort(b, b+n);
	x = b[n/2-1];
	y = b[n/2];
	for(i=0; i<n; i++) printf("%d\n", a[i]<=x ? y:x);
	return 0;
}