#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, s, k;
	char a[11];
	scanf("%d", &n);
	scanf("%s", a, 11);
	scanf("%d", &k);
	for (int i = 0; i < n; i++)
	{
		if (a[i] != a[k - 1])
			printf("*");
		else
			printf("%c", a[i]);
	}
	//system("pause");
	return 0;
}