#include <bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

using namespace std;

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using ll=long long;
using R=long double;
const R EPS=1e-9L; // [-1000,1000]->EPS=1e-8 [-10000,10000]->EPS=1e-7
inline int sgn(const R& r){return(r > EPS)-(r < -EPS);}
inline R sq(R x){return sqrt(max(x,0.0L));}

template<typename T> vector<T> make_vector(size_t sz){
	return vector<T>(sz);
}

template<typename T,typename... Ts> 
auto make_vector(size_t sz, Ts... ts){
	return vector<decltype(make_vector<T>(ts...))>(sz, make_vector<T>(ts...));
}

template<typename T,typename U,typename... V> 
typename enable_if<is_same<T, U>::value!=0>::type 
fill_value(U &u, const V... v){
	u=U(v...);
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_value(U &u, const V... v){
	for(auto &e:u){
		fill_value<T>(e,v...);
	}
}

const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};

const pid_t pid = getpid();
// Problem Specific Parameter:

ll dp[110][2][2][4];

int main(void){
	string s; int k;
	cin >> s >> k;
	const int n = s.size();

	dp[0][0][0][0] = 1LL;

	rep(i, n) rep(nz, 2) rep(le, 2) rep(a, k + 1) {
		rep(d, 10) {
			const int ni = i + 1;
			const int nnz = nz || (d != 0);
			if(le == 0 and d > s[i] - '0') continue;
			int nle = le;
			if(d < s[i] - '0') nle = 1;
			const int na = a + (d != 0);
			if(na > k) continue;
			dp[ni][nnz][nle][na] += dp[i][nz][le][a];
		}
	}

	cout << dp[n][1][0][k] + dp[n][1][1][k] << endl;

	return 0;
}