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
	LL n, x, m;
	cin >> n >> x >> m;
	vector<int> prv(m, -1);
	vector<LL> vals = {x};
	prv[x] = 0;
	for(int i = 1; i < n; ++i){
		x = x * x % m;
		if(prv[x] != -1){ break; }
		vals.push_back(x);
		prv[x] = i;
	}
	LL ans = accumulate(ALL(vals), 0LL);
	int sz = vals.size();
	if(sz < n){
		LL rem = n - sz;
		LL per = sz - prv[x];
		LL t = rem / per;
		ans += accumulate(vals.begin() + prv[x], vals.end(), 0LL) * t;
		rem %= per;
		ans += accumulate(vals.begin() + prv[x], vals.begin() + prv[x] + rem, 0LL);
	}
	cout << ans << endl;
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
