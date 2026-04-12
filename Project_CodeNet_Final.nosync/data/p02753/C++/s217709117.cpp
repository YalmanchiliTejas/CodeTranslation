
#include <bits/stdc++.h>
    
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ld;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ll> vl;
typedef vector<vector<int>>  vvi ;
typedef vector<vc> vvc;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vpi ;

#define sz(a) (int)(a.size())
#define all(a) a.begin(),a.end()
#define rall(x) x.rbegin(), x.rend()
#define F first 
#define S second
#define pb push_back 
#define mp make_pair
#define ar array
#define lb lower_bound
#define ub upper_bound
#define FIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define mem(X,val) memset(X, val, sizeof((X)))
#define FOR(i, n) for(int i = 0 ; i < (int) n ; ++i)
#define UNQ(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define P(x) cout << x <<'\n';
#define W(x) cout << x;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

const db PI = acos(-1);
const ll mod = 1e9+7;
template <typename A, typename B>istream& operator>>(istream& input,pair<A,B>& x) {input>>x.F>>x.S;return input;}
template <typename A>istream& operator>>(istream& input,vector<A>& x) {for(auto& i:x)input>>i;return input;}
template<typename A>ostream& operator<<(ostream& output,vector<A>& x) {for(auto& i:x)output<<i<<' ';return output;}
template<class T> void _R(T &x) { cin >> x; } void R() {}template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...);}
template <class T>void smax(T& x,T y){ if(x<y)x=y;}
template <class T>void smin(T& x,T y){ if(x>y)x=y;}
template<typename T1, typename T2> T1 powz(T1 A, T2 B);
template <typename T1, typename T2>T1 ADD(T1,T2);
template <typename T1, typename T2>void ADDZ(T1&,T2);
template<class T1, class T2> T1 mul(T1 A, T2 B);
template<typename T1, typename T2> T1 GCD(T1 A,T2 B);
template<typename T1> T1 MOD(T1 A){return (A%mod + mod)%mod;}
/***************************************************main code**************************************************************/
const int MXN=1e6+5;
const ll INF = 9e18+200;
const int inf = 1e9+100;
const int mxn = 2e5+20;

void test_case()
{
	vector<char> g;
	string s; R(s);
	for(auto x: s)
		g.pb(x);
	
	UNQ(g);
	if(sz(g)>1){
		W("Yes");
	}else W("No");
	
	
	
}

/*************----------------------------******************/
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int Tests = 1;
	//cin >> Tests;
	
	for(int tc = 1; tc <= Tests; ++tc){
		//cout <<"Case #"<<tc<<": ";
		test_case();
		cout<<'\n';
	}
		
}
template <typename T1, typename T2> 
T1 ADD(T1 A, T2 B)
{
	ll res = (A+B)%mod;
	if(res<0)res+=mod;
	return res;
}
template <typename T1, typename T2> 
void ADDZ(T1& A, T2 B)
{
	ll res = (A+B)%mod;
	if(res<0)res+=mod;
	A = res;
}
template<typename T1, typename T2>
T1 powz(T1 X,T2 B)
{
	ll A = X;
	ll res=1;
		A%=mod; 
		assert(B>=0); 
	for( ; B ; B>>=1){
		if(B&1)res=res*A%mod;
		A= A*A%mod;
	}
	return res;
}
template<typename T1, typename T2> 
T1 GCD(T1 A,T2 B)
{
	 return B?GCD(B,A%B):A;
}
template <class T1 , class T2> 
T1 mul(T1 A, T2 B)
{
	ll res = 1;
	res = (1LL * A%mod * B%mod )%mod;
	return res;
}
