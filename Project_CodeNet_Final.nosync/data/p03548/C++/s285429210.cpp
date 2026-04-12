#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int x,y,z;
	std::cin >> x >> y >> z;
	std::cout << (x - z) / (y + z) << '\n';
	return 0;
}
