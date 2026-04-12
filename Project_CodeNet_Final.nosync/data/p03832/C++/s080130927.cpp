#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <array>
#include <unordered_map>
#include <complex>
#include <deque>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <chrono>
#include <random>
#include <numeric>
#include <tuple>
#include <cstring>
using namespace std;

#define forr(x,arr) for(auto&& x:arr)
#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) _rep3(i,0,n)
#define _rep3(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2,)(__VA_ARGS__)
#define _rrep2(i,n) _rrep3(i,0,n)
#define _rrep3(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define rrep(...) _overload3(__VA_ARGS__,_rrep3,_rrep2,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define bit(n) (1LL<<(n))
#define sz(x) ((int)(x).size())
#define TEN(n) ((ll)(1e##n))
#define fst first
#define snd second

string DBG_DLM(int &i){return(i++==0?"":", ");}
#define DBG_B(exp){int i=0;os<<"{";{exp;}os<<"}";return os;}
template<class T>ostream&operator<<(ostream&os,vector<T>v);
template<class T>ostream&operator<<(ostream&os,set<T>v);
template<class T>ostream&operator<<(ostream&os,queue<T>q);
template<class T>ostream&operator<<(ostream&os,priority_queue<T>q);
template<class T,class K>ostream&operator<<(ostream&os,pair<T,K>p);
template<class T,class K>ostream&operator<<(ostream&os,map<T,K>mp);
template<class T,class K>ostream&operator<<(ostream&os,unordered_map<T,K>mp);
template<int I,class TPL>void DBG(ostream&os,TPL t){}
template<int I,class TPL,class H,class...Ts>void DBG(ostream&os,TPL t){os<<(I==0?"":", ")<<get<I>(t);DBG<I+1,TPL,Ts...>(os,t);}
template<class T,class K>void DBG(ostream&os,pair<T,K>p,string delim){os<<"("<<p.first<<delim<<p.second<<")";}
template<class...Ts>ostream&operator<<(ostream&os,tuple<Ts...>t){os<<"(";DBG<0,tuple<Ts...>,Ts...>(os,t);os<<")";return os;}
template<class T,class K>ostream&operator<<(ostream&os,pair<T,K>p){DBG(os,p,", ");return os;}
template<class T>ostream&operator<<(ostream&os,vector<T>v){DBG_B(forr(t,v){os<<DBG_DLM(i)<<t;});}
template<class T>ostream&operator<<(ostream&os,set<T>s){DBG_B(forr(t,s){os<<DBG_DLM(i)<<t;});}
template<class T>ostream&operator<<(ostream&os,queue<T>q){DBG_B(for(;q.size();q.pop()){os<<DBG_DLM(i)<<q.front();});}
template<class T>ostream&operator<<(ostream&os,priority_queue<T>q){DBG_B(for(;q.size();q.pop()){os<<DBG_DLM(i)<<q.top();});}
template<class T,class K>ostream&operator<<(ostream&os,map<T,K>m){DBG_B(forr(p,m){os<<DBG_DLM(i);DBG(os,p,"->");});}
template<class T,class K>ostream&operator<<(ostream&os,unordered_map<T,K>m){DBG_B(forr(p,m){os<<DBG_DLM(i);DBG(os,p,"->");});}
#define DBG_OVERLOAD(_1,_2,_3,_4,_5,_6,macro_name,...)macro_name
#define DBG_LINE(){char s[99];sprintf(s,"line:%3d | ",__LINE__);cerr<<s;}
#define DBG_OUTPUT(v){cerr<<(#v)<<"="<<(v);}
#define DBG1(v,...){DBG_OUTPUT(v);}
#define DBG2(v,...){DBG_OUTPUT(v);cerr<<", ";DBG1(__VA_ARGS__);}
#define DBG3(v,...){DBG_OUTPUT(v);cerr<<", ";DBG2(__VA_ARGS__);}
#define DBG4(v,...){DBG_OUTPUT(v);cerr<<", ";DBG3(__VA_ARGS__);}
#define DBG5(v,...){DBG_OUTPUT(v);cerr<<", ";DBG4(__VA_ARGS__);}
#define DBG6(v,...){DBG_OUTPUT(v);cerr<<", ";DBG5(__VA_ARGS__);}
#define DEBUG0(){DBG_LINE();cerr<<endl;}
#ifdef LOCAL
#define out(...){DBG_LINE();DBG_OVERLOAD(__VA_ARGS__,DBG6,DBG5,DBG4,DBG3,DBG2,DBG1)(__VA_ARGS__);cerr<<endl;}
#else
#define out(...)
#endif

using ll=long long;
using pii=pair<int,int>;using pll=pair<ll,ll>;using pil=pair<int,ll>;using pli=pair<ll,int>;
using vs=vector<string>;using vvs=vector<vs>;using vvvs=vector<vvs>;
using vb=vector<bool>;using vvb=vector<vb>;using vvvb=vector<vvb>;
using vi=vector<int>;using vvi=vector<vi>;using vvvi=vector<vvi>;
using vl=vector<ll>;using vvl=vector<vl>;using vvvl=vector<vvl>;
using vd=vector<double>;using vvd=vector<vd>;using vvvd=vector<vvd>;
using vpii=vector<pii>;using vvpii=vector<vpii>;using vvvpii=vector<vvpii>;
template<class A,class B>bool amax(A&a,const B&b){return b>a?a=b,1:0;}
template<class A,class B>bool amin(A&a,const B&b){return b<a?a=b,1:0;}
ll ri(){ll l;cin>>l;return l;} string rs(){string s;cin>>s;return s;}

const int mod = 1e9+7;

template<int MOD> struct Mint {
	int x;
	Mint() : x(0) {}
	Mint(int y) : x(y >= 0 ? y % MOD : MOD - (-y) % MOD) {}
	Mint(int64_t sll) : x(sll % MOD) { if (x < 0) x += MOD; }
	Mint &operator+=(const Mint &rhs){ if((x += rhs.x) >= MOD) x -= MOD; return *this; }
	Mint &operator-=(const Mint &rhs){ if((x += MOD - rhs.x) >= MOD) x -= MOD; return *this; }
	Mint &operator*=(const Mint &rhs){ x = 1LL*x*rhs.x % MOD; return *this; }
	Mint &operator/=(const Mint &rhs){ x = (1LL*x*rhs.inv().x) % MOD; return *this; }
	Mint operator-() const { return Mint(-x); }
	Mint operator+(const Mint &rhs) const { return Mint(*this) += rhs; }
	Mint operator-(const Mint &rhs) const { return Mint(*this) -= rhs; }
	Mint operator*(const Mint &rhs) const { return Mint(*this) *= rhs; }
	Mint operator/(const Mint &rhs) const { return Mint(*this) /= rhs; }
	bool operator<(const Mint &rhs) const { return x < rhs.x; }
	Mint inv() const {
		assert(x != 0);
		signed a = x, b = MOD, u = 1, v = 0, t;
		while (b) { t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
		return Mint(u);
	}
	Mint operator^(uint64_t t) const {
		Mint e = *this, res = 1;
		for(; t; e *= e, t>>=1) if (t & 1) res *= e;
		return res;
	}
};
template<int MOD> ostream &operator<<(ostream &os, const Mint<MOD> &rhs) { return os << rhs.x; }
template<int MOD> istream &operator>>(istream &is, Mint<MOD> &rhs) { int64_t s; is >> s; rhs = Mint<MOD>(s); return is; };

using mint = Mint<mod>;
using vm=vector<mint>;using vvm=vector<vm>;using vvvm=vector<vvm>;

const int SET_FACT_MAX = 1010;
mint fact[SET_FACT_MAX];
mint revFact[SET_FACT_MAX];

void setFact() {
	const int N = SET_FACT_MAX;
	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = fact[i - 1] * i;
	}
	revFact[N - 1] = fact[N - 1] ^ (mod - 2);
	for (int i = N - 2; i >= 0; i--) {
		revFact[i] = revFact[i + 1] * (i + 1);
	}
}

mint nPr(int n, int r) { return n >= r ? fact[n] * revFact[n - r] : 0; }
mint nCr(int n, int r) { return nPr(n, r) * revFact[r]; }

mint solve() {
	setFact();
	int n = ri(), a = ri(), b = ri(), c = ri(), d = ri();
	out(n,a,b,c,d);
	vvm dp(b+1, vm(n+1));
	dp[a-1][0] = 1;

	vm inv(d+1);
	rep(i, 1, d+1) inv[i] = mint(i).inv();

	rep(i, a, b+1) {
		rep(j, n+1) {
			if (dp[i-1][j].x == 0) continue;
			dp[i][j] += dp[i-1][j];
			mint cnt = dp[i-1][j];
			rep(k, 1, d+1) {
				if (j + k*i > n) break;
				cnt *= nCr(n-j-(k-1)*i, i);
				cnt *= inv[k];
				if (k >= c) dp[i][j+k*i] += cnt;
			}
		}
	}
	mint ans = dp[b][n];
	return ans;
}

void Main() {
	cout << solve() << endl;
}
signed main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	Main();
	return 0;
}
