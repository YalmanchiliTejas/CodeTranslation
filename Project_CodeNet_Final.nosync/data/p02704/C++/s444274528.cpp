#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
#include <cassert>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

using namespace std;

#define cauto const auto&
#define ALL(v) begin(v),end(v)
#else
#define ALL(v) (v).begin(),(v).end()
#endif

namespace{
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}
template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }
template <class F, class T>
void convert(const F &f, T &t){
	stringstream ss;
	ss << f;
	ss >> t;
}
template <class Con>
string concat(const Con &c, const string &spr){
	stringstream ss;
	typename Con::const_iterator it = c.begin(), en = c.end();
	bool fst = true;
	for(; it != en; ++it){
		if(!fst){ ss << spr; }
		fst = false;
		ss << *it;
	}
	return ss.str();
}

template <class Con, class Fun>
vector<typename Con::value_type> cfilter(const Con &c, Fun f) {
	vector<typename Con::value_type> ret;
	typename Con::const_iterator it = c.begin(), en = c.end();
	for(; it != en; ++it){
		if(f(*it)){
			ret.emplace_back(*it);
		}
	}
	return ret;
}
#if __cplusplus >= 201402L
template <class Con, class Fun>
auto cmap(const Con &c, Fun f) -> vector<decltype(f(*c.begin()))> {
	vector<decltype(f(*c.begin()))> ret;
	ret.reserve(c.size());
	for(const auto &x: c){
		ret.emplace_back(f(x));
	}
	return ret;
}
#endif


#define REP(i,n) for(int i=0;i<int(n);++i)
#define RALL(v) (v).rbegin(),(v).rend()
#define tget(t,i) get<i>(t)

#define MOD 1000000007LL
#define EPS 1e-8

struct dinic{
	typedef int flow_type;

	struct edge{
		int to;
		flow_type cap;
		int rev;
		edge(int t, flow_type c, int r) : to(t), cap(c), rev(r) {}
	};

	vector<vector<edge> > gr;
	vector<int> level;
	vector<int> iter;

	dinic(){}
	dinic(int m) : gr(m), level(m), iter(m) {}
	
	size_t size() const{
		return level.size();
	}

	void initialize(int m){
		*this = dinic(m);
	}

	void add_edge(int from, int to, flow_type cap) {
		if(cap > 0){
			gr[from].push_back(edge(to, cap, gr[to].size()));
			gr[to].push_back(edge(from, 0, gr[from].size() - 1));
		}
	}

	void bfs(int s){
		level.assign(level.size(), -1);
		queue<int> qu;
		level[s] = 0;
		qu.push(s);
		while(!qu.empty()){
			int v = qu.front();
			qu.pop();
			for(int i = 0; i < (int)gr[v].size(); i++){
				edge &e = gr[v][i];
				if(e.cap > 0 && level[e.to] < 0){
					level[e.to] = level[v] + 1;
					qu.push(e.to);
				}
			}
		}
	}

	flow_type dfs(int v, int t, flow_type f){
		if(v == t){
			return f;
		}
		for(int &i = iter[v]; i < (int)gr[v].size(); i++){
			edge &e = gr[v][i];
			if(e.cap > 0 && level[v] < level[e.to]){
				flow_type d = dfs(e.to, t, min(f, e.cap));
				if(d > 0){
					e.cap -= d;
					gr[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	flow_type max_flow(int s, int t){
		flow_type flow = 0;
		const flow_type INF = numeric_limits<flow_type>::max();
		for(;;){
			bfs(s);
			if(level[t] < 0){
				return flow;
			}
			iter.assign(iter.size(), 0);
			flow_type f;
			while((f = dfs(s, t, INF)) > 0) {
				flow += f;
			}
		}
	}
};

typedef unsigned long long ULL;

void mainmain(){
	int n;
	cin >> n;
	vector<int> ss(n), ts(n);
	REP(i, n){ cin >> ss[i]; }
	REP(i, n){ cin >> ts[i]; }
	vector<ULL> us(n), vs(n);
	REP(i, n){ cin >> us[i]; }
	REP(i, n){ cin >> vs[i]; }

	VV(ULL) ans;
	initvv(ans, n, n);
	REP(b, 64){
		dinic dn(2 * n + 10);
		int src = 2 * n + 2;
		int sink = src + 1;
		int srcm = sink + 1;
		int sinkm = srcm + 1;

		REP(i, n){
			if(ss[i] == 0){
				if(us[i] >> b & 1){
					dn.add_edge(src, sinkm, n);
					dn.add_edge(srcm, i, n);
				}
				else{
					dn.add_edge(src, i, n - 1);
				}
			}
			else if(us[i] >> b & 1){
				dn.add_edge(src, i, n - 1);
				dn.add_edge(src, sinkm, 1);
				dn.add_edge(srcm, i, 1);
			}
			if(ts[i] == 0){
				if(vs[i] >> b & 1){
					dn.add_edge(i + n, sinkm, n);
					dn.add_edge(srcm, sink, n);
				}
				else{
					dn.add_edge(i + n, sink, n - 1);
				}
			}
			else if(vs[i] >> b & 1){
				dn.add_edge(i + n, sink, n - 1);
				dn.add_edge(i + n, sinkm, 1);
				dn.add_edge(srcm, sink, 1);
			}
			REP(j, n){
				dn.add_edge(i, j + n, 1);
			}
		}
		
		dn.max_flow(srcm, sinkm);
		dn.max_flow(src, sinkm);
		dn.max_flow(srcm, sink);
		dn.max_flow(src, sink);
		REP(i, n){
			for(cauto e : dn.gr[i]){
				if(e.to >= n && e.to < 2 * n && e.cap == 0){
					ans[i][e.to - n] |= 1ull << b;
				}
			}
		}
	}

	bool ok = true;
	REP(i, n){
		if(ss[i] == 0){
			ULL z = -1;
			REP(j, n){ z &= ans[i][j]; }
			ok &= z == us[i];
		}
		else{
			ULL z = 0;
			REP(j, n){ z |= ans[i][j]; }
			ok &= z == us[i];
		}
		if(ts[i] == 0){
			ULL z = -1;
			REP(j, n){ z &= ans[j][i]; }
			ok &= z == vs[i];
		}
		else{
			ULL z = 0;
			REP(j, n){ z |= ans[j][i]; }
			ok &= z == vs[i];
		}
	}
	if(ok){
		for(cauto c : ans){
			const char *spr = "";
			for(ULL x : c){
				cout << spr << x;
				spr = " ";
			}
			cout << "\n";
		}
	}
	else{
		cout << "-1\n";
	}
}



}
int main() try{
//	ios::sync_with_stdio(false); cin.tie(0);
	cout << fixed << setprecision(10);
	cerr << fixed << setprecision(4);
	mainmain();
}
catch(const exception &e){
	cerr << "exception: " << e.what() << endl;
	abort();
}
catch(...){
	cerr << "exception" << endl;
	abort();
}
