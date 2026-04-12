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
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <climits>
#include <cassert>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> vi;
typedef vector<string> VS;
typedef pair<int, int> pii;
typedef long long ll;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

const double EPS = 1e-9;
const double PI  = acos(-1.0);
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,1,-1};

#define CLR(a) memset((a), 0 ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

class unionfind {
	vector<int> par, rank;

public:
	void init(int n) {
		par.resize(n);
		rank.resize(n);

		for (int i = 0; i < n; i++) {
			par[i] = i;
			rank[i] = 0;
		}
	}

	int find(int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return ;

		if (rank[x] < rank[y]) par[x] = y;
		else {
			par[y] = x;
			if (rank[x] == rank[y]) ++rank[x];
		}
	}

	bool same(int x, int y) { return (find(x) == find(y)); }
} uf;

int N;
pii pt[100010];
vector<pair<pii,int>> v1, v2;
vector<pair<int, pii>> es;
ll ret;

int main() {
	cin >> N;
	uf.init(N);

	rep(i, N) {
		cin >> pt[i].fi >> pt[i].se;
		v1.eb(pt[i], i);
		v2.eb(mp(pt[i].se, pt[i].fi), i);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	rep(i, N-1) {
		es.eb(mp(v1[i+1].fi.fi - v1[i].fi.fi, mp(v1[i].se, v1[i+1].se)));
	}

	rep(i, N-1) {
		es.eb(mp(v2[i+1].fi.fi - v2[i].fi.fi, mp(v2[i].se, v2[i+1].se)));
	}

	sort(es.begin(), es.end());

	for (auto t : es) {
		int a = t.se.fi, b = t.se.se, c = t.fi;
		if (!uf.same(a, b)) {
			uf.unite(a, b);
			ret += c;
		}
	}

	cout << ret << endl;

	return 0;
}