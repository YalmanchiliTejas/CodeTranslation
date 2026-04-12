#include <iostream> // cin, cout, cerr
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota
#include <cstdio> // printf, scanf
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <iomanip> // cout<<setprecision(n)
#include <functional> // function<void(int)>
#include <cmath>
#include <cassert>
#include <bitset>

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...)
#endif

#define int long long // at least int64 > 9*10^18
#define EL '\n'
#define rep(i,n) for(int i = 0; i < (n); i++)
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
/* libraries */

signed main() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	std::vector<int> p(1<<n);
	rep(i,1<<n) std::cin >> p[i];
	auto f = [&] (int a, int b) -> int {
		if(a>b) std::swap(a,b);
		if(s[b-a-1]=='0') return a;
		return b;
	};
	std::vector<std::vector<int> > dp(n+1,std::vector<int>(1<<n));
	dp[0]=p;
	rep(i,n) {
		int dx=1<<i;
		rep(j,1<<n) {
			dp[i+1][j]=f(dp[i][j],dp[i][(j+dx)%(1<<n)]);
		}
	}
	debug(dp);
	rep(i,1<<n) print(dp[n][i]);

	return 0;
}

