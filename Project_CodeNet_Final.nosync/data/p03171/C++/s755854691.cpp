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

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...)
#endif

#define int long long // at least int64 > 9*10^18
#define ENDL '\n'
#define rep(i,n) for(int i = 0; i < (n); i++)
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
/* libraries */

signed main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];
	// dp[l][r]
	std::vector<std::vector<int> > dp(n+1,std::vector<int>(n+1));
	rep(i,n+1) dp[i][i]=0;
	for(int l=n-1;l>=0;l--) {
		for(int r=l+1;r<=n;r++) {
			bool first = (n-(r-l))%2==0;
			if(first) dp[l][r] = std::max(dp[l+1][r]+a[l], dp[l][r-1]+a[r-1]);
			else dp[l][r] = std::min(dp[l+1][r]-a[l], dp[l][r-1]-a[r-1]);
		}
	}
	print(dp[0][n]);
	return 0;
};
