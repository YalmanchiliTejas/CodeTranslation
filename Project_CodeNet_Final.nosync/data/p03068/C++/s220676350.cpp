#include <bits/stdc++.h>

int main()
{
	char s[20];
	int n,k;
	scanf ("%d\n", &n);
	int i;
	for (i=1; i<=n; i++)
		scanf("%c", &s[i]);
	scanf ("%d", &k);
	for (i=1; i<=n; i++)
	{
		if (s[i] != s[k])
			printf("*");
		else
			printf("%c", s[i]);
	}
	printf("\n");
	return 0;
 } 