#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = INT_MAX;//2147483647
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
#ifdef LOCAL_ENV
	#define debug(var) std::cout<<#var" = "<<var<<std::endl
#else
	#define debug(var)
#endif
#define p(var)  std::cout<<var<<std::endl
#define PI (acos(-1))
#define rep(i, n)   for(int i=0, i##_length=(n); i< i##_length; ++i)
#define repeq(i, n) for(int i=1, i##_length=(n); i<=i##_length; ++i)
#define all(a) (a).begin(), (a).end()
#define pb push_back
inline double isnatural(double a) { return a>=0 && ceil(a)==floor(a); }
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


int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> path(m, vector<int>(2, 0));
	rep(i,m){
		int a,b;
		cin >> a >> b;
		path[i]={a,b};
	}

	vector<int> route(n,0);
	repeq(i,n){
		route[i-1]=i;
	}

	debug(path);

	int count=0;
	do {
		if(route[0]!=1)continue;
		[&]{
			for (int i = 1; i < route.size(); i++) {
				bool ok=false;
				int a=route[i-1];
				int b=route[i];
				if(a>b)swap(a,b);
				for(auto pp:path){
					if(pp[0]==a && pp[1]==b){
						ok=true;
						break;
					}
				}
				if(!ok){
					return;
				}
			}
			count++;
		}();
	} while (std::next_permutation(route.begin(), route.end()));//昇順順列生成、vが昇順ソート済みの必要あり

	p(count);
	return 0;
}

