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

using Weight = int;
struct Edge {
	int dst;
	Weight weight;
	Edge() : dst(0), weight(0) {}
	Edge(int d, Weight w = 1) : dst(d), weight(w) {}
};
ostream &operator<<(ostream &os, const Edge &e) { return os << e.dst; }
using Edges = vector<Edge>;
using Graph = vector<Edges>;

bool solve() {
	int n = ri();

	Graph G(n);
	vi J(n);
	rep(i, n-1) {
		int u = ri() - 1;
		int v = ri() - 1;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
		J[u]++;
		J[v]++;
	}

	if (n == 2) return false;

	int root = -1;
	rep(i, n) {
		if (J[i] != 1) {
			root = i;
			break;
		}
	}

	out(root);

	vi P(n);
	vi D(n, 1e9);
	D[root] = 0;
	{
		function<void(int, int)> dfs = [&](int cur, int pre) {
			P[cur] = pre;
			forr(nex, G[cur]) {
				if (nex.dst != pre) {
					D[nex.dst] = D[cur] + 1;
					dfs(nex.dst, cur);
				}
			}
		};
		dfs(root, -1);
	}

	priority_queue<pii> Q;
	rep(i, n) {
		if (J[i] == 1) {
			Q.emplace(D[i], i);
		}
	}


	vi U(n);

	while (sz(Q)) {
		int u = Q.top().snd;
		Q.pop();

		int p = P[u];
		out(u, p);

		if (u == root) return true;
		if (U[p]) return true;

		U[u] = U[p] = 1;

		int g = P[p];
		if (g != -1) {
			J[g]--;
			if (J[g] == 1 && g != root) {
				out(g);
				Q.emplace(D[g], g);
			}
		}
	}
	if (U[root]) return false;
	return true;
}

void Main() {
	cout << (solve() ? "First" : "Second") << endl;
}

signed main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	Main();
	return 0;
}
