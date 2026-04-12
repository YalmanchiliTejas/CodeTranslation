#include <stdio.h>

int main(void)	{
	
	int n, s, smax, smin, ssum, mean;
	
	while (true)	{
		
		scanf("%d", &n);
		
		if (n == 0)	{
			break;
		}
		
		smax = 0;
		smin = 1000;
		ssum = 0;
		
		for (int i = 1; i <= n; i++)	{
			
			scanf("%d", &s);
			
			if (smax < s)	{
				smax = s;
			}
			if (smin > s)	{
				smin = s;
			}
			
			ssum += s;
		}
		
		mean = (ssum - smax - smin) / (n - 2);
		
		printf("%d\n", mean);
	}
	
	return 0;
}
