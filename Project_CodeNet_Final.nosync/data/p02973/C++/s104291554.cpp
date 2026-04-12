#include <iostream>
#include <vector>
#include <set>

int main() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (auto&& e : a)
		std::cin >> e;

	int ans = 1;

	std::multiset<int> set;
	set.insert(a.back());
	for (int i = n - 2; i >= 0; --i) {
		if (a[i] >= *set.rbegin()) {
			++ans;
			set.insert(set.end(), a[i]);
			continue;
		}

		auto it = set.upper_bound(a[i]);
		set.erase(it);

		set.insert(a[i]);
	}

	std::cout << ans << std::endl;
}