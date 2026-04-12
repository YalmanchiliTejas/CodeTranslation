#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
int n,a[maxn];
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if (n%2==0) {
		for (int i=n;i>=2;i-=2)
			printf("%d ",a[i]);
		for (int i=1;i<=n;i+=2)
			printf("%d ",a[i]);
		printf("\n");
	}
	else {
		for (int i=n;i>=1;i-=2)
			printf("%d ",a[i]);
		for (int i=2;i<=n;i+=2)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}