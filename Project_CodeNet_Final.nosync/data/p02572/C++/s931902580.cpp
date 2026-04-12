#include <iostream>
#include <vector>

int main()
{
	long long modular = 1000000007;

	size_t N = 0;

	std::cin >> N;

	std::vector<long long> numbers(N, 0);
	std::vector<long long> sums(N - 1, 0);

	for (auto& number : numbers)
	{
		std::cin >> number;
	}

	long long answer = 0;

	for (size_t index = 0; index < N - 1; ++index)
	{
		if (index == 0)
		{
			sums.at(index) = numbers.at(N - 1);

			continue;
		}

		sums.at(index) = (numbers.at(N - index - 1) + sums.at(index - 1)) % modular;

		sums.at(index) %= modular;
	}

	for (size_t index = 0; index < N -1; ++index)
	{
		long long sum = 0;

		answer += (numbers.at(index) * sums.at(N - index - 2)) % modular;

		answer %= modular;
	}

	std::cout << answer << std::endl;
}

