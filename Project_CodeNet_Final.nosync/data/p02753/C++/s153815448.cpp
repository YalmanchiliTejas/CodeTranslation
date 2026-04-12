#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	std::vector<char> stations;
	for (int i = 0; i < 3; i++) {
		char temp;
		std::cin >> temp;
		stations.push_back(temp);
	}
	if (stations[0] == stations[1] && stations[1] == stations[2]) {
		std::cout << "No";
	}
	else {
		std::cout << "Yes";
	}
}