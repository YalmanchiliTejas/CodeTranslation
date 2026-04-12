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
constexpr int dx[4]={1,0,-1,0};
constexpr int dy[4]={0,1,0,-1};
#define p(var) std::cout<<var<<std::endl
#define PI (acos(-1))
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)
#define repeq(i, n) for(ll i=1, i##_length=(n); i<=i##_length; ++i)
#define all(v) (v).begin(), (v).end()
#define uniq(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
template<typename T> inline void pv(vector<T> v) { for(ll i=0, N=v.size(); i<N; i++) cout<< v[i] << (i==N-1 ? '\n' : ' '); }
template<typename T> inline T gcd(T a, T b) { return b ? gcd(b,a%b) : a; }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a,  b) * b; }
template<typename T1, typename T2> inline T1 power(T1 x, T2 n){ return n ? power(x*x%MOD,n/2)*(n%2?x:1)%MOD : 1; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template<typename T> class dvector : public std::vector<T> {
public:
	dvector() : std::vector<T>() {}
	explicit dvector(size_t n, const T& value = T()) : std::vector<T>(n,value) {}
	dvector(const std::vector<T>& v) : std::vector<T>(v) {}
	dvector(const std::initializer_list<T> il) : std::vector<T>(il) {}
	dvector(const typename std::vector<T>::iterator first, const typename std::vector<T>::iterator last) : std::vector<T>(first, last) {}
	dvector(const std::string::iterator first, const std::string::iterator last) : std::vector<T>(first, last) {}
	T& operator[](size_t n) { return this->at(n); }
	const T& operator[](size_t n) const { return this->at(n); }
};
class dbool{
public:
	dbool() : boolvalue(false) {}
	dbool(bool b) : boolvalue(b) {}
	dbool(const dbool &b) : boolvalue(b.boolvalue) {}
	operator bool&() { return boolvalue; }
	operator const bool&() const { return boolvalue; }
private:
	bool boolvalue;
};
template<typename T1, typename T2> ostream& operator<<(ostream& s, pair<T1, T2>& p) {return s << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator<<(ostream& s, dvector<T>& v) {
	for (int i = 0, len = v.size(); i < len; ++i){ s << v[i]; if (i < len - 1) s << "\t"; } return s; }
template<typename T> ostream& operator<<(ostream& s, dvector< dvector<T> >& vv) {
	for (int i = 0, len = vv.size(); i < len; ++i){ s << vv[i] << endl; } return s; }
template<typename T1, typename T2> ostream& operator<<(ostream& s, map<T1, T2>& m) {
	s << "{" << endl; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << endl; } s << "}" << endl; return s; }
template<typename T> ostream& operator<<(ostream& s, set<T>& se) {
	s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}" << endl; return s; }
template<typename T> ostream& operator<<(ostream& s, multiset<T>& se) {
	s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}" << endl; return s; }
#ifdef LOCAL_DEV
	#define debug(var) std::cout<<#var" = "<<var<<std::endl
#else
	#define debug(var)
#endif
#ifdef LOCAL_TEST
	#define vector dvector
	#define bool dbool
#endif

/*-----8<-----8<-----*/

signed main() {
	ll H,W;
	cin>>H>>W;
	vector<string> s(H,"");
	rep(i,H)cin>>s[i];

	vector<string> t;
	rep(i,H){
		if([&]{
			rep(j,W){
				if(s[i][j]=='#')return true;
			}
			return false;
		}()){
			t.push_back(s[i]);
		}
	}

	auto u=t;
	ll c=0;
	rep(j,W){
		if([&]{
			rep(i,t.size()){
				if(t[i][j]=='#')return false;
			}
			return true;
		}()){
			debug(j-c);
			rep(i,t.size()){
				u[i].erase(j-c,1);
			}
			c++;		
		}
		debug(u);
	}

	rep(i,u.size())p(u[i]);
	return 0;
}
