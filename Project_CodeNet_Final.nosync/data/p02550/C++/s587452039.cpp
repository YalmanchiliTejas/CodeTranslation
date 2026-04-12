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
struct FIO{FIO(){std::cin.tie(0);std::ios_base::sync_with_stdio(0);std::cout<<std::setprecision(15);}}fIO;
template<typename T> using V = std::vector<T>;
template<typename T> void fill(V<T>&v) { for(T&e:v) std::cin >> e; }
/*-*/

int main() {
	lnt n,x,m;
	std::cin >> n >> x >> m;
	V<lnt> to(m,-1);
	lnt cur=x;
	lnt ans=x;
	std::map<lnt,lnt> map;
	rep(i,n) {
		map[cur]=i;
		if(i==n-1) {
			print(ans);
			return 0;
		}
		to[cur]=cur*cur%m;
		cur=to[cur];
		if(to[cur]!=-1) {
			lnt cy=i-map[cur]+1;
			lnt left=n-1-i;
			lnt csum=0;
			lnt xx=cur;
			rep(j,cy) {
				csum+=xx;
				xx=to[xx];
			}
			ans+=(left/cy)*csum;
			left%=cy;
			xx=cur;
			rep(j,left) {
				ans+=xx;
				xx=to[xx];
			}
			print(ans);
			return 0;
		} else {
			ans+=cur;
		}
	}
}
