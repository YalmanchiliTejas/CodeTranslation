#include <iostream>
#include <string>

int main()
{
	int N = 0, M = 0;
	std::string ans;

	std::cin >> N >> M;

	ans = (N == M) ? "Yes" : "No";

	std::cout << ans << std::endl;

	return 0;
}