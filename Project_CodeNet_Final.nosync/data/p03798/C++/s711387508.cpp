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

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...)
#endif

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ENDL '\n'
#define print(i) std::cout << (i) << '\n'

#define int long long // at least int64 > 9*10^18
#define all(v) (v).begin(), (v).end()
/* libraries */

signed main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	rep(i,n) {
		char c;
		std::cin >> c;
		if(c=='o') a[i] = 0;
		else a[i] = 1;
	}
	// test all 0, 1
	rep(x0,2) rep(x1,2) {
		std::vector<int> b(n);
		b[0] = x0; b[1] = x1;
		for(int i=2;i<n;i++) {
			b[i] = b[i-1]^b[i-2]^a[i-1];
		}
		if(b[0]^b[n-1]^b[n-2]==a[n-1] && b[0]^b[1]^b[n-1]==a[0]) {
			for(int x:b) {
				if(x==0) std::cout << 'S';
				else std::cout << 'W';
			}
			std::cout << ENDL;
			return 0;
		}
	}
	print(-1);

	return 0;
}
