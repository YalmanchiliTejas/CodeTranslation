#include <stdio.h>
#include <iostream>

using namespace std;
int n,a[201001],b[202020],st,ed;
int main() {
	scanf("%d",&n);
	for (int i = 1;i <= n; i++)
		scanf("%d",&a[i]);
	st = 1,ed = n;
	for (int i = n;i >= 1; i--)
		if ((n-i+1)&1)
			b[st++] = a[i];
		else
			b[ed--] = a[i];
	for (int i = 1;i <= n; i++)
		printf("%d ",b[i]);
	return 0;
}