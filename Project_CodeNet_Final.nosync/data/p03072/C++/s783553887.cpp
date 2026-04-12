#include <iostream>
#include <vector>
#include <sstream>

inline void split(const std::string& str, std::vector<int>& H) {
	const char sep = ' ';
    std::stringstream ss(str);
    std::string buffer;

	while (std::getline(ss, buffer, sep)) {
		H.push_back(std::stoi(buffer));
	}
}

int main (void) {
	std::string str;
	int N;
	std::getline(std::cin, str);
	N = std::stoi(str);
	
	std::vector<int> H;
	std::getline(std::cin, str);
	split(str, H);
	
	int i, max = 0, cnt = 0;
	
	for (i = 0; i < H.size(); ++i) {
		if (H[i] >= max) {
			max = H[i];
			++cnt;
		}
	}
	
	std::cout << cnt << std::endl;
	
	return 0;
}