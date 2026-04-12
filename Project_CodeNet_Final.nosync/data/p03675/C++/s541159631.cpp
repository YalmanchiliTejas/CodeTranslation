#include <cstdio>
int n, a[200005];
int main() {
	int i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &a[i]);
	for(i=n-1; i>=0; i-=2) printf("%d ", a[i]);
	for(i=n%2; i<n; i+=2) printf("%d ", a[i]);
	return 0;
}