#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;

//#define int long long
using bll = boost::multiprecision::cpp_int;
using ll = long long;
//constexpr int INF = 1e9;//INT_MAX=(1<<31)-1=2147483647
constexpr ll INF = (ll)1e18;//(1LL<<63)-1=9223372036854775807
constexpr ll MOD = (ll)1e9 + 7;
constexpr double EPS = 1e-9;
constexpr int dx[2]={1,0};
constexpr int dy[2]={0,1};
#ifdef LOCAL_ENV
	#define debug(var) std::cout<<#var" = "<<var<<std::endl
#else
	#define debug(var)
#endif
#define p(var) std::cout<<var<<std::endl
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)
#define repeq(i, n) for(ll i=1, i##_length=(n); i<=i##_length; ++i)
#define all(a) (a).begin(), (a).end()
#define PI (acos(-1))
template<typename T> inline T power(T x, T n){ return n ? power(x*x%MOD,n/2)*(n%2?x:1)%MOD : 1; }
template<typename T> inline T gcd(T a, T b) { return b ? gcd(b,a%b) : a; }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a,  b) * b; }
template<typename T1, typename T2>inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2>inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {return s << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
	for (int i = 0, len = v.size(); i < len; ++i){
		s << v[i]; if (i < len - 1) s << "\t";
	}
	return s;
}
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
	for (int i = 0, len = vv.size(); i < len; ++i){
		s << vv[i] << endl;
	}
	return s;
}
template<typename T1, typename T2> ostream& operator<<(ostream& s, const map<T1, T2>& m) {
	s << "{" << endl;
	for (typeof(m.begin()) itr = m.begin(); itr != m.end(); ++itr){
		s << "\t" << (*itr).first << " : " << (*itr).second << endl;
	}
	s << "}" << endl;
	return s;
}

/*-----8<-----8<-----*/

constexpr ll W_MAX = 8;


ll H, W;
char A[10][10];

void input() {
	scanf("%lld%lld", &H, &W);
	rep(i, H) scanf("%s", A[i]);
}

bool solve() {

	ll x=0,y=0;
	A[0][0]='.';
	while(1){
		if(x>0 && A[x-1][y]=='#'){
			return false;
		}
		if(y>0 && A[x][y-1]=='#'){
			return false;
		}

		if(x!=H-1 && y!=W-1 && A[x][y+1]=='#' && A[x+1][y]=='#'){
			return false;
		}

		if(x==H-1 && y==W-1){
			return true;
		}

		rep(i,2){
			ll nx=x+dx[i];
			ll ny=y+dy[i];

			if(nx==H)continue;
			if(ny==W)continue;
			if(A[nx][ny]=='#'){
				A[nx][ny]='.';
				x=nx;
				y=ny;
				goto a;
			}
		}
		a:;
	}

	
	
}

signed main() {
	input();
	if (solve()){
		printf("Possible\n");
	}else{
		printf("Impossible\n");
	}
	return 0;
}
