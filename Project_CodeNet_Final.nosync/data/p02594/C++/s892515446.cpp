
#include "bits/stdc++.h"
using namespace std;

//wierd debugging stuff
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << "\n" ; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
//end of weird debugging stuff
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
 
#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define fo(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define foe(i,x) for(auto& i: x)
#define ar array
#define pb push_back
#define vt vector
#define F first
#define S second

template<class T> bool umin(T& a,const T& b){return b<a?a=b,1:0;}
template<class T> bool umax(T& a,const T& b){return b>a?a=b,1:0;}

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {cin>>x;}
void read(double& d) {string t;read(t);	d=stod(t);}
void read(long double& d) {	string t;read(t);d=stold(t);}
template<class H, class... T> void read(H& h, T&... t) {read(h);read(t...);}
template<class A> void read(vt<A>& x) {	foe(a, x)read(a);}

// no change 
const ll MOD = 1e9+7;  
const int mx = 1e5;
int n;
void Titan(){
	read(n);
	if(n>=30)
		cout << "Yes";
	else
	cout <<"No" ;
}
	

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1;
	//cin >> T;		//cmt if one test case
    fo(T){
		//cout << "Case #" << i+1 << ": " ;
		Titan();
	}
}
/*///////////////////////////////////////////////////////////
Important Notes : 
* check long long 
* check base cases
* do not loose Hope
* if case fails on 2nd test case maybe some cases are missing check them
* do not sit idle
* try to do it using pen/paper.
*/
