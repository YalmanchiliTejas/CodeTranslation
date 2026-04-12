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
struct FIO{FIO(){std::cin.tie(0);std::cout.tie(0);std::ios_base::sync_with_stdio(0);std::cout<<std::fixed<<std::setprecision(15);}}fIO;
/*-*/

int main() {
	std::string s,t;
	std::cin >> s >> t;
	std::vector<int> f;
	{
		int curr=0;
		rep(i,s.size()) {
			if(curr==t.size()) break;
			if(s[i]==t[curr]) {
				f.emplace_back(i);
				curr++;
			}
		}
		if(curr!=t.size()) {
			print("no");
			return 0;
		}
	}
	std::reverse(all(s));
	std::reverse(all(t));
	std::vector<int> ff;
	{
		int curr=0;
		rep(i,s.size()) {
			if(curr==t.size()) break;
			if(s[i]==t[curr]) {
				ff.emplace_back(i);
				curr++;
			}
		}
		if(curr!=t.size()) {
			print("no");
			return 0;
		}
	}
	std::reverse(all(ff));
	rep(i,f.size()) {
		debug(f[i],ff[i]);
		if(f[i]!=s.size()-1-ff[i]) {
			print("no");
			return 0;
		}
	}
	print("yes");
}

