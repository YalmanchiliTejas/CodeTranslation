#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>
#include <array>
#include <chrono>
#include <random>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define VAR(type, ...)type __VA_ARGS__;Scan(__VA_ARGS__);
template<typename T> void Scan(T& t) { std::cin >> t; }
template<typename First, typename...Rest>void Scan(First& first, Rest&...rest) { std::cin >> first; Scan(rest...); }
#define OUT(d) std::cout<<d;
#define FOUT(n, d) std::cout<<std::fixed<<std::setprecision(n)<<d;
#define SOUT(n, c, d) std::cout<<std::setw(n)<<std::setfill(c)<<d;
#define SP std::cout<<" ";
#define TAB std::cout<<"\t";
#define BR std::cout<<"\n";
#define ENDL std::cout<<std::endl;
#define FLUSH std::cout<<std::flush;
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define MAT(type, c, m, n) std::vector<std::vector<type>> c(m, std::vector<type>(n));for(auto& r:c)for(auto& i:r)std::cin>>i;
#define ALL(a) (a).begin(),(a).end()
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)
#define FORLL(i, a, b) for(ll i=ll(a);i<ll(b);++i)
#define RFORLL(i, a, b) for(ll i=ll(b)-1;i>=ll(a);--i)
#define REPLL(i, n) for(ll i=0;i<ll(n);++i)
#define RREPLL(i, n) for(ll i=ll(n)-1;i>=0;--i)
#define PAIR std::pair<int, int>
#define PAIRLL std::pair<ll, ll>
#define IN(a, x, b) (a<=x && x<b)
#define SHOW(d) {std::cerr << #d << "\t:" << d << "\t";}
#define SHOWVECTOR(v) {std::cerr << #v << "\t:";for(const auto& i : v){std::cerr << i << " ";}std::cerr << "\n";}
#define SHOWVECTOR2(v) {std::cerr << #v << "\t:\n";for(const auto& i : v){for(const auto& j : i){std::cerr << j << " ";}std::cerr << "\n";}}
#define SHOWPAIRVECTOR2(v) {std::cerr << #v << "\t:\n";for(const auto& i : v){for(const auto& j : i){std::cerr<<'('<<j.first<<", "<<j.second<<") ";}std::cerr << "\n";}}
#define SHOWPAIRVECTOR(v) {for(const auto& i:v){std::cerr<<'('<<i.first<<", "<<i.second<<") ";}std::cout<<"\n";}
#define CHECKTIME(state) {auto start=std::chrono::system_clock::now();state();auto end=std::chrono::system_clock::now();auto res=std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();std::cerr<<"[Time:"<<res<<"ns  ("<<res/(1.0e9)<<"s)]\n";}
#define SHOWQUEUE(a) {std::queue<decltype(a.front())> tmp(a);std::cerr << #a << "\t:";for(int i=0; i<static_cast<int>(a.size()); ++i){std::cerr << tmp.front() << "\n";tmp.pop();}std::cerr << "\n";}
#define CHMAX(a, b) a = (((a)<(b)) ? (b) : (a))
#define CHMIN(a, b) a = (((a)>(b)) ? (b) : (a))
#define EXCEPTION(msg) throw std::string("Exception : " msg " [ in ") + __func__ + " : " + std::to_string(__LINE__) + " lines ]"
#define TRY(cond, msg) try {if (cond) EXCEPTION(msg);}catch (std::string s) {std::cerr << s << std::endl;}

#define int ll
using ll = long long;
using ull = unsigned long long;
constexpr int INFINT = 1 << 30;                          // 1.07x10^ 9
constexpr int INFINT_LIM = (1LL << 31) - 1;              // 2.15x10^ 9
constexpr ll INFLL = 1LL << 60;                          // 1.15x10^18
constexpr ll INFLL_LIM = (1LL << 62) - 1 + (1LL << 62);  // 9.22x10^19
constexpr double EPS = 1e-9;
constexpr int MOD = 1000000007;
constexpr double PI = 3.141592653589793238;

signed main() {
	INIT;
	VAR(int, h, w);
	MAT(char, a, h, w);
	
	std::function<void(int, int)> dfs = [&](int i, int j) {
		a[i][j] = '.';
		int x, y;
		{
			x = j, y = i + 1;
			if (IN(0, y, h) && IN(0, x, w)) {
				if (a[y][x] == '#') {
					dfs(y, x);
					return;
				}
			}
		}
		{
			x = j + 1, y = i;
			if (IN(0, y, h) && IN(0, x, w)) {
				if (a[y][x] == '#') {
					dfs(y, x);
					return;
				}
			}
		}
	};
	dfs(0, 0);
	REP(i, h) REP(j, w) {
		if (a[i][j] == '#') {
			OUT("Impossible")BR;
			return 0;
		}
	}
	OUT("Possible")BR;
	return 0;
}