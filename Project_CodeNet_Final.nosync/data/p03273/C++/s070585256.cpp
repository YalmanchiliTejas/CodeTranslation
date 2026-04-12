#include "bits/stdc++.h"

int main() {
	int H, W;
	std::cin >> H >> W;
	std::vector<std::string> a;

	for (int i = 0; i < H; i++) {
		std::string str;
		std::cin >> str;
		if (str.find('#') == std::string::npos) continue;
		a.push_back(str);
	}

	std::vector<bool> ignore(W);
	for (int i = 0; i < W; i++) {
		bool ignore_check = true;
		for (auto b : a) {
			if (b[i] == '#') {
				ignore_check = false;
				break;
			}
		}
		if (ignore_check) {
			ignore[i] = true;
		}
	}

	// output
	for (auto b : a) {
		for (int i = 0; i < W; i++) {
			if (ignore[i] == false) {
				std::cout << b.at(i);
			}
		}
		std::cout << std::endl;
	}

	return 0;
}
