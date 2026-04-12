#include<stdio.h>
#include<string.h>
char s[100009], a[100009], d[4][2] = { {'S','S'},{'S','W'},{'W','S'},{'W','W'} };
int main()
{
	int n, i, j, f1 = 0,f2=0,f=0;
	scanf("%d%s", &n,s);
	for (j = 0; j < 4; j++)
	{
		f1 = 0; f2 = 0;
		a[0] = d[j][0];
		a[1] = d[j][1];
		for (i = 2; i < n; i++)
		{
			if (s[i - 1] == 'o')
			{
				if (a[i - 1] == 'S')a[i] = a[i - 2];
				else
				{
					if (a[i - 2] == 'S')a[i] = 'W';
					else a[i] = 'S';
				}
			}
			else
			{
				if (a[i - 1] == 'S')
				{
					if (a[i - 2] == 'S')a[i] = 'W';
					else a[i] = 'S';
				}
				else a[i] = a[i - 2];
			}
		}
		if ((a[0] == 'S'&&s[0] == 'o'&&a[n - 1] == a[1]) || (a[0] == 'S'&&s[0] == 'x'&&a[n - 1] != a[1]) || (a[0] == 'W'&&s[0] == 'o'&&a[n - 1] != a[1]) || (a[0] == 'W'&&s[0] == 'x'&&a[n - 1] == a[1]))f1 = 1;
		if ((a[n - 1] == 'S'&&s[n - 1] == 'o'&&a[n - 2] == a[0]) || (a[n - 1] == 'S'&&s[n - 1] == 'x'&&a[n - 2] != a[0]) || (a[n - 1] == 'W'&&s[n - 1] == 'o'&&a[n - 2] != a[0]) || (a[n - 1] == 'W'&&s[n - 1] == 'x'&&a[n - 2] == a[0]))f2 = 1;
		if(f1&&f2)
		{
			f = 1;
			break;
		}
	}
	if (f)printf("%s\n", a);
	else printf("-1\n");
	return 0;
}