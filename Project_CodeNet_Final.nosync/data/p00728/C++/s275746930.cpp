#include <stdio.h>

int n;	//審判数
int sum;
int max;
int min;
	
void fun_max(int i, int j);
void fun_min(int i, int j);
	
int main()
{
	scanf("%d", &n);
	//printf("n=%d", n);
	
	while (n)
	{
		int i;
	
		sum = 0;
		max = -1;
		min = 1500;
		
		for (i=0; i<n; i++)
		{
			int input;
			
			scanf("%d", &input);
			//printf("input=%d\n", input);
			fun_max(max, input);
			//printf("max=%d\n", max);
			fun_min(min, input);
			//printf("min=%d\n", min);
			sum += input;
		}
		sum -= max;
		sum -= min;
		
		int ans;
		ans = sum/(n-2);
		printf("%d\n", ans);
		//printf("\n\n\n\n");
		
		scanf("%d", &n);
	}
	
	return 0;
}

void fun_max(int i, int j)
{
	if (i > j)
	{
		max = i;
	}
	else
	{
		max = j;
	}
	return;
}

void fun_min(int i, int j)
{
	if (i < j)
	{
		min = i;
	}
	else
	{
		min = j;
	}
	return;
}