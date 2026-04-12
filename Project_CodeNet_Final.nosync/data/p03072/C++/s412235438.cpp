#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <numeric>


int main() {
	int n;

	std::cin >> n;

	std::vector<int> v(n);

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> v[i];
	}

	int count = 1;
	int max = v[0];

	for (size_t i = 1; i < n; i++)
	{
		if (max <= v[i]) {
			count++;
			max = v[i];
		}
	}

	std::cout << count << std::endl;
}