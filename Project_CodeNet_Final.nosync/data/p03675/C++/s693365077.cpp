#include <iostream>

int main()
{
	long int n, a[200010], b[200010];
	std::cin >> n;
	
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	
	if (n % 2 == 0)
	{
		int j = 0;
		for (int i = n - 1; i >= 0; i -= 2)
		{
			b[j] = a[i];
			++j;
		}
		for (int i = 0; i < n; i += 2)
		{
			b[j] = a[i];
			++j;
		}
	}
	else
	{
		int j = 0;
		for (int i = n - 1; i >= 0; i -= 2)
		{
			b[j] = a[i];
			++j;
		}
		for (int i = 1; i < n; i += 2)
		{
			b[j] = a[i];
			++j;
		}
	}
	
	for (int i = 0; i < n; ++i)
		std::cout << b[i] << " ";
}