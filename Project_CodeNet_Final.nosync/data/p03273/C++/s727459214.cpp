#include<iostream>
#include<string>
#include<array>
#include<algorithm>
#include<deque>
#include<vector>

int main(void) {
	int h;
	std::cin >> h;
	int w;
	std::cin >> w;

	std::vector<std::string>a(h);
	std::vector<bool>tate(w, false);
	std::vector<bool>yoko(h, false);

	for (int i = 0; i < h; i++) {
		std::cin >> a[i];
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') {
				yoko[i] = true;
				tate[j] = true;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		if (yoko[i] == true) {
			for (int j = 0; j < w; j++) {
				if (tate[j] == true) {
					std::cout << a[i][j];
				}
			}
			std::cout << std::endl;
		}
	}

}