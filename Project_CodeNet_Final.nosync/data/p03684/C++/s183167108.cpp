
//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <limits>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

//math
//-------------------------------------------
template<class T> inline T sqr(T x) { return x * x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define EXISTch(s,c) ((((s).find_first_of(c)) != std::string::npos)? 1 : 0)//cがあれば1 if(1)
#define SORT(c) sort((c).begin(),(c).end())

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF = (int)1000000007;
const LL MOD = (LL)1000000007;//10^9+7
const LL INF2 = (LL)100000000000000000;//10^18

template< typename T >
struct edge {
	int src, to;
	T cost;

	edge(int to, T cost) : src(-1), to(to), cost(cost) {}

	edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

	edge &operator=(const int &x) {
		to = x;
		return *this;
	}

	operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

struct UnionFind {
	vector< int > data;

	UnionFind(int sz) {
		data.assign(sz, -1);
	}

	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return (false);
		if (data[x] > data[y]) swap(x, y);
		data[x] += data[y];
		data[y] = x;
		return (true);
	}

	int find(int k) {
		if (data[k] < 0) return (k);
		return (data[k] = find(data[k]));
	}

	int size(int k) {
		return (-data[find(k)]);
	}
};

template< typename T >
T kruskal(Edges< T > &edges, int V) {
	sort(begin(edges), end(edges), [](const edge< T > &a, const edge< T > &b) {
		return (a.cost < b.cost);
	});
	UnionFind tree(V);
	T ret = 0;
	for (auto &e : edges) {
		if (tree.unite(e.src, e.to)) ret += e.cost;
	}
	return (ret);
}

int main() {
	int n; cin >> n;

	vector<pair<LL,LL>> x;
	vector<pair<LL,LL>> y;

	for (int i = 0; i < n; i++) {
		LL n, m; cin >> n >> m;

		x.push_back({ n,i });
		y.push_back({ m,i });
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	Edges<LL> edges;

	for (int i = 0; i < n-1; i++) {
		edges.emplace_back(x[i].second,x[i + 1].second,x[i + 1].first - x[i].first);
		edges.emplace_back(y[i].second,y[i + 1].second,y[i + 1].first - y[i].first);
	}

	cout << kruskal(edges, n) << endl;
	
}

