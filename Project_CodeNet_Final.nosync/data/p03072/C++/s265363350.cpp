#include <iostream>
#include <string>
#include <algorithm>

class Solver {
public:
    void solve();
};


void Solver::solve() {
    // 入力
	int n;
	std::cin >> n;
	int h[109];
	for (int i = 0; i < n; ++i) {
		std::cin >> h[i];
	}
	int count = 1;
	for (int i = 1; i < n; ++i) {
		bool flag = true;
		for (int j = 0; j < i; ++j) {
			if (h[j] > h[i])
				flag = false;
		}
		if (flag)
			count++;
	}
	std::cout << count << std::endl;
}

int main() {
    Solver solver = Solver();
    solver.solve();
    return 0;
}