#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	int wall = 0, ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int h;
		std::cin >> h;
		if (wall <= h)
		{
			ans++;
		}
		wall = std::max(wall, h);
	}
	std::cout << ans;
}