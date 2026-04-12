#include <bits/stdc++.h>

typedef int64_t s64;

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	std::vector<std::pair<int,int> > a;
	int max = 0;
	int min = 1000000001;
	for (int i = 0; i < n; i++) {
		int x = ri();
		int y = ri();
		if (x > y) std::swap(x, y);
		a.push_back({x,y});
		max = std::max(max, y);
		min = std::min(min, x);
	}
	std::sort(a.begin(), a.end());
	if (n == 1) {
		std::cout << 0 << std::endl;
		return 0;
	}
	
	s64 res;
	// min != max => min to one, max to the other
	{
		int min_max = 0;
		int max_min = 1000000001;
		for (int i = 0; i < n; i++) {
			min_max = std::max(min_max, a[i].first);
			max_min = std::min(max_min, a[i].second);
		}
		res = (min_max - min) * (s64)(max - max_min);
	}
	
	// min == max => except a[0], 
	using T = std::pair<int, int>;
	std::set<T> que;
	std::multiset<int, std::greater<int> > cur;
	// use a[0].second
	
	for (int i = 1; i < n; i++) {
		que.insert({a[i].first, i});
		cur.insert(a[i].first);
	}
	int sub_res = std::max(a[0].second, *cur.begin()) - std::min(a[0].second, *std::prev(cur.end()));
	while (que.size()) {
		T top = *que.begin(); que.erase(que.begin());
		cur.erase(cur.find(top.first));
		cur.insert(a[top.second].second);
		sub_res = std::min(sub_res, std::max(a[0].second, *cur.begin()) - std::min(a[0].second, *std::prev(cur.end())));
	}
	res = std::min(res, (max - min) * (s64)sub_res);
	std::cout << res << std::endl;
	
	
	return 0;
}
