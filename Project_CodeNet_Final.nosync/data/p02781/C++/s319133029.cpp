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
	std::string s;
	std::cin >> s;
	int n=s.size();
	int k;
	std::cin >> k;


	if(k==1) {
		print((int)(s[0]-'0')+(n-1)*9);
		return 0;
	} else if(k==2) {
		int ans = 0;
		ans+=(int)(s[0]-'0'-1)*9*(n-1);
		ans+=(n-1)*(n-2)/2*81;
		rep(i,n) {
			if(i==0) continue;
			if(s[i]!='0') {
				ans+=s[i]-'0';
				ans+=(n-i-1)*9;
				break;
			}
		}
		print(ans);
		return 0;
	} else if(k==3) {
		int ans = 0;
		ans+=(int)(s[0]-'0'-1)*9*9*(n-1)*(n-2)/2;
		ans+=(n-1)*(n-2)*(n-3)/6*9*9*9;
		int i=1;
		for(;i<n;i++) {
			if(s[i]!='0') {
				ans+=(s[i]-'0'-1)*(n-i-1)*9;
				ans+=81*(n-i-1)*(n-i-2)/2;
				i++;
				break;
			}
		}
		for(;i<n;i++) {
			if(s[i]!='0') {
				ans+=s[i]-'0';
				ans+=(n-i-1)*9;
				break;
			}
		}
		print(ans);
		return 0;
	}
	return 0;
}
