#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
// iteration helper
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define RREP(i,n) RFOR(i,0,n)
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define PB push_back
// MyVector
template <typename T>
class MyVector : private std::vector<T, std::allocator<T>> {
public:
    using basetype = std::vector<T, std::allocator<T>>;
	using basetype::vector; // constractor
	using basetype::operator=;
	using basetype::begin; using basetype::end; using basetype::cbegin; using basetype::cend; using basetype::rbegin;	using basetype::rend; using basetype::crbegin; using basetype::crend;
	using basetype::size; using basetype::max_size; using basetype::resize; using basetype::capacity; using basetype::empty; using basetype::reserve; using basetype::shrink_to_fit;

	// []のかわりに at をつかう
	typename MyVector<T>::reference operator[](typename basetype::size_type n){ basetype::at(n); }
	typename MyVector<T>::const_reference operator[](typename basetype::size_type n) const { basetype::at(n); };

	using basetype::at; using basetype::data; using basetype::front; using basetype::back;
	using basetype::assign; using basetype::push_back; using basetype::emplace_back; using basetype::pop_back; using basetype::insert; using basetype::emplace; using basetype::erase; using basetype::swap; using basetype::clear;
};
#ifdef _DEBUG
#define vector MyVector
#else
#define vector std::vector
#endif
// typedefs
#define ll long long
#define vi vector<int>
#define vi2 vector<vi>
// input
#define ci(x) int x;cin>>x
#define cs(x) string x;cin>>x
#define cd(x) double x;cin>>x
#define cvi(x,n) vi x(n);REP(i,n){cin>>x[i];}
// const input
#define cci(x) const int x = [](){int t;cin>>t;return t;}()
#define ccs(x) const string x = [](){string t;cin>>t;return t;}()
#define ccd(x) const double x = [](){double t;cin>>t;return t;}()
// output
#define pr(x) cout<<x<<endl
#define prvec(v) REP(i,v.size()) pr(v[i])
#define ppr(x) cout<<x
#define lf() cout<<endl
// debug methods
// usage: debug(x,y);
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x
#define debug_1(x1) cout<<#x1<<": "<<x1<<endl
#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<", "#x5<<": "<<x5<<endl
#ifdef _DEBUG
#define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)
#else
#define debug(...)
#endif
// const number
const double PI  = acos(-1.0);
const double EPS = 1e-10;

int powint(int a, int x){
	int res = 1;
	REP(i,x){
		res = res *a; 
	}
	return res;
}
#pragma endregion

signed main(){
#ifdef _DEBUG
try{
#endif
// main program ---------------------------------------------
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cci(N);
	vi A(N);
	REP(i,N){
		cin>>A[i];
	}
	multiset<int, greater<int>> c;
	REP(i,N){
		auto it = c.upper_bound(A[i]);
		if(it == c.end()){
			//ないとき
			//debug("ない i:"<<i<<" A[i]"<<A[i]);
			c.insert(A[i]);
		} else {
			it=c.erase(it);
			c.insert(A[i]);
		}
	}
	pr(c.size());
// end main program -----------------------------------------
#ifdef _DEBUG
} catch (std::out_of_range& ex){ pr("out of range"); }
#endif
	return 0;
}
