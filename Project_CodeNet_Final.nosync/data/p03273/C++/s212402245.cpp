#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main(int argc, char const *argv[]) {
	int h,w;
	std::cin >> h >> w;
	std::vector<string> str(h);
	for (size_t i = 0; i < h; i++) {
		std::cin >> str[i];
	}

	std::vector<string> eraseH;
	for (size_t i = 0; i < str.size(); i++) {
		bool flag = false;
		for (size_t j = 0; j < str[i].size(); j++) {
			if (str[i][j] == '#') {
				flag = true;
				break;
			}
		}
		if (flag) {
			eraseH.push_back(str[i]);
		}
	}
	std::vector<bool> use(w,false);
	for (size_t i = 0; i < w; i++) {
		for (size_t j = 0; j < h; j++) {
			if (str[j][i] == '#') {
				use[i] = true;
				break;
			}
		}
	}

	for (size_t i = 0; i < eraseH.size(); i++) {
		for (size_t j = 0; j < use.size(); j++) {
			if (use[j]) {
				std::cout << eraseH[i][j];
			}
		}
		std::cout << '\n';
	}
	return 0;
}
