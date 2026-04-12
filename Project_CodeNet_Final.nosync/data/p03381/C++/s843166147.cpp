#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main(int argc, char const *argv[]) {
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> v[i];
	}
	std::vector<int> vv(v);
	sort(vv.begin(), vv.end());
	int a = vv[n/2-1];
	int b = vv[n/2];

	for (size_t i = 0; i < v.size(); i++) {
		if (v[i] <= a) {
			std::cout << b << '\n';
		}
		else {
			std::cout << a << '\n';
		}
	}
	return 0;
}
