#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
	int num_of_eat = 0;
	int paid = 0;
	int received = 0;

	std::cin >> num_of_eat;
	paid = 800 * num_of_eat;
	received = (num_of_eat / 15) * 200;

	std::cout << (paid - received) << std::endl;
	return 0;
}
