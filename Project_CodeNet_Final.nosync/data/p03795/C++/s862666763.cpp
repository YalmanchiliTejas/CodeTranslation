#include <stdio.h>
#include <iostream>
#include <string>
int main(void)
{
	int N, i;
	int sum = 0;
	std::cin >> N;
	for (i = 1; i <= N; i++)
	{
		sum += 800;
		if (i % 15 == 0)
		{
			sum -= 200;
		}
	}
	std::cout << sum;
	

	return 0;
}
	

		
	