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
int powz(int v,int k) { int r(1),t(v); while(k){ if(k&1) r*=t; t*=t; k>>=1; } return r; }

signed main() {
	std::string s;
	int k;
	std::cin >> s >> k;
	int n = s.size();

	std::function<int(int,int)> f = [&] (int i, int j) -> int {
		if(j==0) return 1;
		if(i==n) return 0;
		int d = s[i]-'0';
		if(d==0) return f(i+1,j);
		// f(i+1,j-1) + (d-1)*pow(9,j-1)*(n-i-1)C(j-1) + pow(9,j)*(n-i-1)Cj
		int x = (d-1)*powz(9,j-1);
		if(n-i-1>=j-1) {
			rep(xx,j-1) {
				x*=n-i-1-xx;
				x/=xx+1;
			}
		} else x=0;

		int y = powz(9,j);
		if(n-i-1>=j) {
			rep(yy,j) {
				y*=n-i-1-yy;
				y/=yy+1;
			}
		} else y=0;
		return f(i+1,j-1) + x + y;
	};
	print(f(0,k));

	return 0;
}
