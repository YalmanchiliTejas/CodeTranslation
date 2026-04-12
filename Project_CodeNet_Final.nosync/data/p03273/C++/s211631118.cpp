#include <iostream>
#include <vector>

int main(void)
{
	int H, W;
	std::cin >> H >> W;

	std::vector< std::vector<char> > a;
	
	std::vector<int> H_del;
	std::vector<int> W_del;
	
	a.resize(H);
	for (auto &it : a) {
		it.resize(W);
		for (auto &iit : it) {
			std::cin >> iit;
		}
	}

	for (int i = 0; i < a.size(); ++i) {
		int sum_w = 0;
		for (int j = 0; j < a.front().size(); ++j) {
			if (a[i][j] == '.') ++sum_w;
		}
		if (sum_w == W)
			H_del.push_back(i);
	}

	for (int i = 0; i < a.front().size(); ++i) {
		int sum_h = 0;
		for (int j = 0; j < a.size(); ++j) {
			if (a[j][i] == '.') ++sum_h;
		}
		if (sum_h == H)
			W_del.push_back(i);
	}

	for (auto it = H_del.rbegin(); it != H_del.rend(); ++it) {
		a.erase(a.begin() + (*it));
	}

	for (auto it = W_del.rbegin(); it != W_del.rend(); ++it) {
		for (auto &a_it : a) {
			a_it.erase(a_it.begin() + (*it));
		}
	}


	for (auto it : a) {
		for (auto iit : it) {
			std::cout << iit;
		}std::cout << std::endl;
	}

	return 0;

}