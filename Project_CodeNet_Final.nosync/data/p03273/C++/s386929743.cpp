#include <stdio.h>
#include <string.h>

char aa[500][500];
int markc[500];
int markr[500];

int main()
{
	int a, b;
	int ww;
	scanf("%d %d ", &a, &b);
	for (int i = 0; i < a; i++)
	{
		ww = 0;
		for (int j = 0; j < b; j++)
		{
			aa[i][j] = getchar();
			if ((aa[i][j]) == '#')
				ww = 1;
		}
		getchar();
		if (!ww) markr[i] = 1;
	}
	for (int j = 0; j < b; j++)
	{
		ww = 0;
		for (int i = 0; i < a; i++)
		{
			if ((aa[i][j]) == '#')
				ww = 1;
		}
		if (!ww) markc[j] = 1;
	}
	for (int i = 0; i < a; i++)
	{
		if (markr[i]) continue;
		for (int j = 0; j < b; j++)
		{
			if (!markc[j])
				putchar(aa[i][j]);
		}
		puts("");
	}
			
	return 0;
}
