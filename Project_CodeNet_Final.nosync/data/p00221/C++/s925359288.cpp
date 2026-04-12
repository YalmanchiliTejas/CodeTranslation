#include <iostream>
#include <string>
#include <list>

std::string getFizzBuzz(int n)
{
	if (n % 15 == 0)
	{
		return "FizzBuzz";
	}
	else if (n % 5 == 0)
	{
		return "Buzz";
	}
	else if (n % 3 == 0)
	{
		return "Fizz";
	}
	else
	{
		return std::to_string(n);
	}
}

void fizzbuzz(int m, int n)
{
	std::list<int> lst;

	for (int i = 1; i <= m; ++i)
	{
		lst.push_back(i);
	}

	for (int i = 1; i <= n; ++i)
	{
		std::string rem;
		std::cin >> rem;

		if (lst.size() <= 1)
		{
			continue;
		}

		int player = *(lst.begin());
		lst.pop_front();

		std::string ret = getFizzBuzz(i);

		if (rem == ret)
		{
			lst.push_back(player);
		}
	}

	lst.sort();
	for (auto itr = lst.begin(); itr != lst.end(); ++itr)
	{
		if (itr != lst.begin())
		{
			std::cout << " ";
		}
		std::cout << *itr;
	}
	std::cout << std::endl;

	return;
}

int main(void)
{
	int m;
	int n;

	while (std::cin >> m >> n && m != 0 && n != 0)
	{
		fizzbuzz(m, n);
	}
	return 0;
}

