#include <iostream>
#include <vector>

int main()
{
	int n, l;
	std::vector<int> h;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> l;
		h.push_back(l);
	}
	int result_count = 1;
	int max = h[0];
	for (unsigned int i = 1; i < h.size(); i++)
	{
		if (h[i] >= max)
		{
			result_count++;

		}
		if (max < h[i])
		{
			max = h[i];
		}
	}
	std::cout << result_count << "\n";
    return 0;
}

