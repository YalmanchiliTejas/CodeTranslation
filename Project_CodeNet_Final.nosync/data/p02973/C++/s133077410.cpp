#include <iostream> // cin, cout, cerr, clog
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota, accumulate, inner_product
#include <cstdio> // printf, scanf
#include <climits> // INT_MIN, LLONG_MIN
#include <cmath> // long, trig, pow
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <stack> // stack
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <unordered_map> // hashed by keys
#include <unordered_set> // hashed by keys
#include <iomanip> // cout<<setprecision(n)
#include <functional> // std::function<void(int)>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ENDL '\n'
#define print(i) std::cout << (i) << '\n'

#define int long long // at least int64 > 9*10^18
#define all(v) (v).begin(), (v).end()
/* libraries */

int LIS(std::vector<int> a) {
	const int INF = 1e9;
	std::vector<int> dp(a.size()+1,INF);
	for(auto i:a) {
		auto lb = std::upper_bound(all(dp),i);
		if(*lb>i) *lb = i;
	}
	int len = 0;
	while(dp[len]!=INF) len++;
	return len;
}


signed main() {
	int n;
	std::cin >> n;
	std::vector<int> a;
	rep(i,n) {
		int x;
		std::cin >> x;
		a.emplace_back(-x);
	}
	print(LIS(a));
	return 0;
}
