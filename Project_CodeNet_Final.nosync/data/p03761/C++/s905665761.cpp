#include <stdio.h>
#include <string.h>

int main(void)
{
	int n;
	int i,j,k;
	int num;
	char ans[60];

	scanf("%d", &n);

	char a[n][30] = {0};
	char s[n][60] = {0};
	for (i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
		for (j = 0; j < strlen(s[i]); j++)
			a[i][s[i][j] - 97]++;
	}

	for (i = 0; i < 30; i++)
	{
		num = a[0][i];
		for (j = 0; j < n; j++)
		{
			if (num > a[j][i])
				num = a[j][i];
		}
		for (k = 0; k < num; k++)
			printf("%c", i+97);
	}

	return 0;
}