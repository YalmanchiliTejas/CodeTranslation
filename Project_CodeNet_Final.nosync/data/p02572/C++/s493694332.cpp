#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
#include <cassert>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

using namespace std;

#define cauto const auto&
#define ALL(v) begin(v),end(v)
#else
#define ALL(v) (v).begin(),(v).end()
#endif

namespace{
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}
template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }
template <class F, class T>
void convert(const F &f, T &t){
	stringstream ss;
	ss << f;
	ss >> t;
}
template <class Con>
string concat(const Con &c, const string &spr){
	stringstream ss;
	typename Con::const_iterator it = c.begin(), en = c.end();
	bool fst = true;
	for(; it != en; ++it){
		if(!fst){ ss << spr; }
		fst = false;
		ss << *it;
	}
	return ss.str();
}

template <class Con, class Fun>
vector<typename Con::value_type> cfilter(const Con &c, Fun f) {
	vector<typename Con::value_type> ret;
	typename Con::const_iterator it = c.begin(), en = c.end();
	for(; it != en; ++it){
		if(f(*it)){
			ret.emplace_back(*it);
		}
	}
	return ret;
}
#if __cplusplus >= 201103L
template <class Con, class Fun>
auto cmap(const Con &c, Fun f) -> vector<decltype(f(*c.begin()))> {
	vector<decltype(f(*c.begin()))> ret;
	ret.reserve(c.size());
	for(const auto &x: c){
		ret.emplace_back(f(x));
	}
	return ret;
}
#endif


#define REP(i,n) for(int i=0;i<int(n);++i)
#define RALL(v) (v).rbegin(),(v).rend()
#define tget(t,i) get<i>(t)

#define MOD 1000000007LL
#define EPS 1e-8


void mainmain(){
	int n;
	scanf("%d", &n);
	LL s = 0, s2 = 0;
	for(int i = 0; i < n; ++i){
		LL a;
		scanf("%lld", &a);
		s = (s + a) % MOD;
		s2 = (s2 + a * a) % MOD;
	}
	LL ans = (s * s % MOD - s2 + MOD) * ((MOD + 1) / 2) % MOD;
	printf("%lld\n", ans);
}



}
int main() try{
//	ios::sync_with_stdio(false); cin.tie(0);
	cout << fixed << setprecision(10);
	cerr << fixed << setprecision(4);
	mainmain();
}
catch(const exception &e){
	cerr << "exception: " << e.what() << endl;
	abort();
}
catch(...){
	cerr << "exception" << endl;
	abort();
}
