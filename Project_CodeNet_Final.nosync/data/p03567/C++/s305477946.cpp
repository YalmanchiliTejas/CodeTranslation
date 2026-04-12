#include <stdio.h>
#include <string.h>
int main()
{
	bool A = false;
	bool AC = false;
	char x[6] = { 0 };
	scanf("%s", x);
	int c = strlen(x);
	for (int i = 0;i < c;i++)
	{
		if (A)
		{
			if (x[i] == 'C')
			{
				AC = true;
			}
			else
			{
				A = false;
			}
		}
		if (x[i] == 'A')
		{
			A = true;
		}

	}
	if (AC)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
    return 0;
}
