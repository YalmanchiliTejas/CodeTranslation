#include <iostream>
#include <vector>

int main() {
	long long n, x, m;
	std::cin >> n >> x >> m;
	
	std::vector<bool> ap(100100, false);
	std::vector<long long> value;
	
	while (not ap[x]) {
		value.push_back(x);
		ap[x] = true;
		x = (x * x) % m;
	}
	
	std::vector<long long> first, loop;
	{
		int sz = (int)(value.size());
		int i = 0;
		for (; value[i] != x; i++) first.push_back(value[i]);
		for (; i < sz; i++) loop.push_back(value[i]);
	}
	
	long long ans = 0;
	long long fir = std::min<long long>(n, first.size());
	for (int i = 0; i < fir; i++) ans += first[i];
	n -= fir;
	
	long long ls = loop.size();
	long long d = n / ls, k = n % ls;
	for (int i = 0; i < ls; i++) {
		long long s = loop[i] * d;
		if (i < k) s += loop[i];
		ans += s;
	}
	
	std::cout << ans << '\n';
	
	return 0;
}