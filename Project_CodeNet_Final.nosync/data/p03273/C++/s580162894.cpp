#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

std::vector<int> WID;
std::vector<int> HEI;

bool func(intt& h) {
	for (auto r : WID) {
		if (r == h)
			return true;
	}
	return false;
}

bool func2(intt& w) {
	for (auto r : HEI) {
		if (r == w)
			return true;
	}
	return false;
}

int main() {
	intt H, W; std::cin >> H >> W;
	std::vector<std::vector<char>> a(H, std::vector<char>(W));
	bool flag;
	intt I;
	for (I = 0; I < H; ++I) {
		flag = false;
		for (intt j = 0; j < W; ++j) {
			std::cin >> a[I][j];
			if (a[I][j] == '#')
				flag = true;
		}
		if (flag == false)
			WID.push_back(I);
	}
	intt J;
	for (J = 0; J < W; ++J) {
		flag = false;
		for (intt i = 0; i < H; ++i) {
			if (a[i][J] == '#')
				flag = true;
		}
		if (flag == false)
			HEI.push_back(J);
			
	}
	intt w;
	for (intt h = 0; h < H; ++h) {
		for (w = 0; w < W; ++w) {
			if (func(h) == false && func2(w) == false)
				std::cout << a[h][w];
		}
		if (func(h) == false)
			std::cout << std::endl;
	}

	return 0;
}