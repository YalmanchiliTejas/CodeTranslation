#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define SZ(x) ((int)(x).size())

typedef long long ll;

ll solve(std::vector<int>& a) {
	std::reverse(a.begin(), a.end());
	int it_be = 0, it_en = SZ(a) - 1;
	ll ret = 0, mi = 2e9;
	for(bool st = 0; it_be <= it_en; st ^= 1) {
		if(it_be == it_en) 
			it_be = SZ(a) - 1;
		ret += std::abs((ll)a[it_be] - a[it_en]);
		mi = std::min(mi, std::abs((ll)a[it_be] - a[it_en]));
		if(st) 
			++it_be;
		else
			--it_en;
	}
	return ret - mi;
}

int main() {
	std::vector<int> a;
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; ++i) {
		int x;
		std::cin >> x;
		a.push_back(x);
	}
	std::sort(a.begin(), a.end());
	ll ans = std::max(solve(a), solve(a));
	std::cout << ans << '\n';
	return 0;
}
