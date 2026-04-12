#include <stdio.h>
#include <algorithm>

int main(void)	{
	while (true)	{
		int umpire, temp, summ, mini, maxi;
		mini = 1000;
		maxi = 0;
		summ = 0;
	
		scanf("%d", &umpire);
		if (umpire == 0)	{
			break;
		}
		for (int i = 0; i <= umpire - 1; i++)	{
			scanf("%d", &temp);
			mini = std::min(mini, temp);
			maxi = std::max(maxi, temp);
			summ = summ + temp;
		}
		printf("%d\n", (summ - mini - maxi) / (umpire - 2));
	}
	return 0;	
}

