#include <stdio.h>
int main ()
{
	int x,y,z;
	int count = 0;
	int counter;
	while(scanf("%d %d %d", &x, &y, &z)!=EOF)
	{
		count = 0;
		counter = x;
		while(x >= 1)
		{
			x = x - y - z;
			count++;
			if(x < 2 * z + y)break;
		}
		printf("%d\n",count);
	}
	return 0;
}
