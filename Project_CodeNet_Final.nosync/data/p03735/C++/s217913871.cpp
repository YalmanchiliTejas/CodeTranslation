#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

typedef long long lint;
typedef std::pair<lint, lint> bag;

std::multiset<lint> left, right;
bag list[200000];

inline lint calc() {
	return ((*left.rbegin()) - (*left.begin()))* ((*right.rbegin()) - (*right.begin()));
}

int main() {
	int count;
	std::cin >> count;

	for (int i = 0; i < count; i++) {
		scanf("%lld%lld", &list[i].first, &list[i].second);
		if (list[i].first > list[i].second) {
			std::swap(list[i].first, list[i].second);
		}

		left.insert(list[i].first);
		right.insert(list[i].second);
	}

	lint res = calc();
	std::sort(list, list + count);

	for (int i = 0; i < count; i++) {
		right.insert(list[i].first);
		left.erase(left.find(list[i].first));

		left.insert(list[i].second);
		right.erase(right.find(list[i].second));

		lint temp = calc();
		res = std::min(res, temp);
	}

	std::cout << res << std::endl;
	return 0;
}