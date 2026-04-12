#include <stdio.h>
#include <algorithm>

int main() {
	int a[100];
	int n, s, i, j, sum;

	scanf("%d",&n);

	while(true) {
		sum = 0;
		if(n == 0)break;
		for(i = 0; i < 100; i++) {
			a[i] = 1000;
		}	
		for(i = 0; i < n; i++) {
			scanf("%d",&s);
			a[i] = s;
		}
		std::sort(a,a+100);
		for(j = 1; j < n-1; j++) {
			sum = sum + a[j];
		}
		printf("%d\n",sum/(n-2));
		scanf("%d",&n);
	}
	return 0;
}