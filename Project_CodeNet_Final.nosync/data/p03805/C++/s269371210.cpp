#include "iostream"
#include "vector"
#include "algorithm"
#include "numeric"

typedef struct{
	int a;
	int b;
}inp;

int main() {
	int n, m, num = 0;
	std::cin >> n;
	std::cin >> m;

	std::vector<int>v(n);
	std::iota(v.begin(), v.end(), 1);

	std::vector<inp>x(m);

	for (int i = 0; i < m; ++i) {
		std::cin >> x[i].a;
		std::cin >> x[i].b;
	}

	bool ex, ex_tmp;
	do {
		if (v[0] == 1) {
			for (int i = 0; i < n - 1; ++i) {
				ex_tmp = false;
				for (int j = 0; j < m; ++j) {
					if ((x[j].a == v[i] && x[j].b == v[i + 1]) || (x[j].a == v[i + 1] && x[j].b == v[i])) {
						ex_tmp = true;
						break;
					}
				}
				if (ex_tmp == false) {
					ex = false;
					break;
				}
			}
			if (ex_tmp == true) {
				num++;
				ex = true;
			}
		}
		else ex = false;

	} while (std::next_permutation(v.begin(), v.end()));

	std::cout << num << std::endl;
}