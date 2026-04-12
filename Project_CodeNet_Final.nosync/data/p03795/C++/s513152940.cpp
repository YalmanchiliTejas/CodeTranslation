#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	int present = N / 15;
	int answer = N * 800 - present * 200;
    std::cout << answer <<"\n"; 
}