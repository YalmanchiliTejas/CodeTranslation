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

template<class V, class Merge> struct SegmentTree {
	const int n;
	const V unit_value;
	vector<V> val;

	SegmentTree(int _n) : n(1 << (33-__builtin_clz(_n-1))), unit_value(Merge::unit()), val(n, unit_value) {}

	V get(int i) const { return val[i + n / 2]; }
	void set(int i, const V &v) { val[i + n / 2] = v; }

	void build() {
		for (int i = n / 2 - 1; i > 0; i--) val[i] = Merge::merge(val[i * 2 + 0], val[i * 2 + 1]);
	}

	void update(int i, const V &v) {
		i += n / 2;
		val[i] = v;
		while (i > 1) {
			i >>= 1;
			val[i] = Merge::merge(val[i * 2 + 0], val[i * 2 + 1]);
		}
	}

	V query(int l, int r) const {
		l = max(0, min(n / 2, l)) + n / 2;
		r = max(0, min(n / 2, r)) + n / 2;
		V ret = unit_value;
		for (; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ret = Merge::merge(ret, val[l++]);
			if (r & 1) ret = Merge::merge(ret, val[--r]);
		}
		return ret;
	}
};

template <class V> struct MergeRangeMaxQ {
	static V merge(const V &l, const V &r) { return l > r ? l : r; }
	static V unit() { return numeric_limits<V>::min(); }
};
template<class V> using SegTreeMax = SegmentTree<V, MergeRangeMaxQ<V>>;

ll solve() {
	int n = ri();

	int ma = -1;

	vpii P(n);
	rep(i, n) {
		int x = ri();
		int y = ri();
		P[i].fst = min(x, y);
		P[i].snd = max(x, y);
		amax(ma, P[i].snd);
	}

	sort(all(P));

	int mi = P[0].fst;

	ll cand1;
	{
		ll lmi = P[0].fst;
		ll rmi = P[0].snd;
		ll lma = lmi;
		ll rma = rmi;
		rep(i, n) {
			amin(lmi, P[i].fst);
			amax(lma, P[i].fst);
			amin(rmi, P[i].snd);
			amax(rma, P[i].snd);
		}
		cand1 = (lma - lmi) * (rma - rmi);
		out(lmi, lma, rmi, rma, cand1);
	}

	ll cand2 = 2e18;
	{
		if (P[0].snd != ma) {
			ll d1 = (ma - mi);
			out(d1);

			int lb = 1e9, ub = 0;
			forr(p, P) {
				if (p.fst == mi) amin(lb, p.snd);
				if (p.snd == ma) amax(ub, p.fst);
			}
			if (lb > ub) swap(lb, ub);
			out(lb, ub);

			forr(p, P) {
				amax(ub, p.fst);
				amin(lb, p.snd);
			}
			out(lb, ub);

			vpii Q;
			forr(p, P) {
				if (p.fst < lb && p.snd > ub) {
					Q.emplace_back(p);
				}
			}

			const int m = sz(Q);
			out(m, Q);

			SegTreeMax<int> seg(m);
			rep(i, m) seg.set(i, Q[i].snd);
			seg.build();

			ll d2 = max(ub, seg.query(0, m)) - lb;
			out(d2);

			rep(i, m) {
				int nlb = Q[i].fst;
				int nub = max(ub, seg.query(0, i));
				ll cand = nub - nlb;
				out(i, nlb, nub, cand);
				amin(d2, cand);
			}
			cand2 = d1 * d2;
		}
	}

	out(cand1, cand2);
	return min(cand1, cand2);
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
