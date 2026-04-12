#include<stdio.h>
int main(void)
{
	int i, n;
	int a[100000], b[100000];
	scanf("%d", &n);
	if (n == 3 || n == 5 || n == 7)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}