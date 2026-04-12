#include <iostream>
#include <cstdio>
#include <vector>

int main()
{
	std::vector<bool> answer;
	std::vector<bool> isWolf;

	int n;
	std::cin >> n;
	answer.resize(n);
	isWolf.resize(n);
	while (getchar() != '\n')
		continue;
	for (int i = 0; i < n; ++i)
		answer[i] = getchar() == 'x';

	bool hasSolution = false;
	for (int start = 0; start < 4; ++start)
	{
		isWolf[0] = start & 1;
		isWolf[1] = start & 2;
		for (int i = 2; i < n; ++i)
			isWolf[i] = (isWolf[i - 2] != isWolf[i - 1] != answer[i - 1]);
		if ((isWolf[n - 2] != isWolf[n - 1] != answer[n - 1]) == isWolf[0] &&
			(isWolf[n - 1] != isWolf[0] != answer[0]) == isWolf[1])
		{
			hasSolution = true;
			break;
		}
	}
	if (hasSolution)
	{
		for (int i = 0; i < n; ++i)
			putchar(isWolf[i] ? 'W' : 'S');
		std::cout << std::endl;
	}
	else
		std::cout << "-1" << std::endl;

	return 0;
}