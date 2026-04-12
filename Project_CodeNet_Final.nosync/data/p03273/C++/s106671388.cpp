#include<iostream>

int main()
{
	int h, w;
	bool row[100]{}, column[100]{}, matrix[100][100]{};
	char tmp;
	std::cin >> h >> w;
	for (int r = 0; r < h; ++r)
		for (int c = 0; c < w; ++c)
		{
			std::cin >> tmp;
			if (tmp == '#')
			{
				matrix[r][c] = column[c] = row[r] = true;
			}
		}

	for (int r = 0; r < h; ++r)
	{
		if (!row[r]) continue;
		for (int c = 0; c < w; ++c)
		{
			if (!column[c]) continue;
			if (matrix[r][c])
				std::cout << '#';
			else
				std::cout << '.';
		}
		std::cout << std::endl;
 	}

	return 0;
}