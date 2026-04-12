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
using Graph = std::vector<std::vector<int> >;
const int INF = 1e17;
/* libraries */

signed main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];
	// hope n*sqrt(n) will work
	int sn=1;
	{
		while(sn*sn<=n) sn++;
	}
	std::vector<std::vector<int> > dp(n,std::vector<int>(sn,0));
	for(int j=1;j<sn;j++) {
		for(int i=0;i<n;i+=j) {
			dp[i][j]=(i-j>=0) ? dp[i-j][j] : (int)0;
			dp[i][j]+=a[i]+a[n-i-1];
		}
	}
	debug(dp);
	int max=0;
	for(int i=2;i<n-1;i++) {
		int x=n-i-1;
		for(int xx=1;xx*xx<=x;xx++) {
			if(x%xx) continue;
			if(!(x>=i && (x-i)%xx==0) && xx<i) {
				max=std::max(max,dp[x][xx]);
			}
			int yy=x/xx;
			if(!(x>=i && (x-i)%yy==0) && yy<i) {
				int sum=0;
				for(int l=0;l<=x;l+=yy) sum+=a[l]+a[n-l-1];
				max=std::max(max,sum);
			}
		}
	}
	print(max);
	return 0;
}
