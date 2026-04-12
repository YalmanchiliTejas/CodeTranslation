#include "iostream"
#include "vector"
#include "algorithm"
#include "numeric"

int main() {
	int n, m, num = 0;
	std::cin >> n;
	std::cin >> m;

	std::vector<int>v(n);
	std::iota(v.begin(), v.end(), 1);

	std::vector<std::pair<int, int>>x(m);

	for (int i = 0; i < m; ++i) {
		std::cin >> x[i].first;
		std::cin >> x[i].second;
	}

	bool ex;
	do {
		if (v[0] == 1) {
			for (int i = 0; i < n - 1; ++i) {
				ex = false;
				for (int j = 0; j < m; ++j) {
					if ((x[j].first == v[i] && x[j].second == v[i + 1]) || (x[j].first == v[i + 1] && x[j].second == v[i])) {
						ex = true;
						break;
					}
				}
				if (!ex) break;
			}
			if (ex)num++;
		}

	} while (std::next_permutation(v.begin(), v.end()));

	std::cout << num << std::endl;
}