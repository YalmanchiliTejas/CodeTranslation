#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <functional>
#include <bitset>
#include <limits>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <random>

#ifdef DEBUG
#include "library/Utility/debug.cpp"
#else
#define debug(...)
#endif

#define rep(i,n) for(int i=0;i<(n);++i)
#define EL '\n'
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
using lnt = long long;
constexpr lnt INF = 2e18;
/*-*/

int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int> > g(n);
	rep(i,n-1) {
		int a,b;
		std::cin >> a >> b;
		a--;b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	auto dfs = [&] (auto f, int i, int par) -> int {
		// -1 is win otherwise return parity
		int p=1;
		for(auto to:g[i]) {
			if(to==par) continue;
			int o=f(f,to,i);
			if(o==-1) return -1;
			if(o==1) p++;
		}
		if(p>2) return -1;
		return p%2;
	};
	int ans=dfs(dfs,0,-1);
	if(ans==1||ans==-1) print("First");
	else print("Second");
}
