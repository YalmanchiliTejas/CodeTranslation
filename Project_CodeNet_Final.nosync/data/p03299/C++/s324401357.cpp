#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <complex>
#include <cstdint>
#include <tuple>
#define M_PI       3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)

#define MOD 1000000007

LL mod_pow(LL a, LL p) {
	LL tmp = a;
	LL ret = 1LL;
	while (p) {
		if (p & 1) ret = (ret*tmp)%MOD;
		p >>= 1;
		tmp = (tmp*tmp) % MOD;
	}
	return ret;
}

struct node {
public:
	int h, w, parent;
	node(int _h, int _w, int _p) :h(_h), w(_w), parent(_p) {};
	vector<int> childs;
	void add_child(int idx) {
		childs.PB(idx);
	}
};

using graph = vector<node>;
int h[100];
graph g;
int n;
LL dp1[100], dp2[100];

int build_tree(int s, int e, int parent=-1, int offset=0) {
	if (s == e)return -1;
	int x = 1e9 + 5;
	FOR(i, s, e)x = min(x, h[i]-offset);
	g.PB(node(x, e - s, parent));
	int myIdx = g.size() - 1;
	if(parent!=-1)g[parent].w -= g[myIdx].w;
	int start = s;
	FOR(i, s, e) {
		if (h[i] == x + offset) {
			auto childIdx = build_tree(start, i, myIdx, x+offset);
			if (childIdx != -1) g[myIdx].add_child(childIdx);
			start = i + 1;
		}
	}
	auto childIdx = build_tree(start, e, myIdx, x + offset);
	if (childIdx != -1) g[myIdx].add_child(childIdx);
	return myIdx;
}

pair<LL, LL> calc(int idx = 0) {
	LL p1 = 1, p2 = 1;
	for (auto child : g[idx].childs) {
		auto tmp = calc(child);
		p1 = (p1*tmp.first) % MOD;
		p2 = (p2*(tmp.first+tmp.second)) % MOD;
	}
	return MP((p1*mod_pow(2, g[idx].h)) % MOD, (((p2*mod_pow(2, g[idx].w)) % MOD + (p1*mod_pow(2, g[idx].h)) % MOD) % MOD - p1 * 2 + 2 * MOD) % MOD);
}

int main() {
	scanf("%d", &n);
	REP(i, n)scanf("%d", &h[i]);
	build_tree(0, n);
	auto ans = calc();
	cout << ans.second << endl;
	return 0;
}
