# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <tuple>
# include <unordered_map>
# include <numeric>
# include <complex>
# include <bitset>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<LL, LL> P;
constexpr int INF = 2000000000;
constexpr int HINF = INF / 2;
constexpr double DINF = 100000000000000000.0;
constexpr long long LINF = 9223372036854775807;
constexpr long long HLINF = 4500000000000000000;
const double PI = acos(-1);
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
# define ALL(x)      (x).begin(),(x).end()
# define UNIQ(c)     (c).erase(unique(ALL((c))),(c).end())
# define mp          make_pair
# define eb          emplace_back
# define FOR(i,a,b)  for(int i=(a);i<(b);i++)
# define RFOR(i,a,b) for(int i=(a);i>=(b);i--)
# define REP(i,n)    FOR(i,0,n)
# define INIT        std::ios::sync_with_stdio(false);std::cin.tie(0)

int V;
int E;
struct edge { int from, to, cost; };

typedef pair<int, int> PP;

vector<edge> e;

int Par[100000];
int Rank[100000];

void init(int n) {
	for (int i = 0; i < n; i++) {
		Par[i] = i;
		Rank[i] = 0;
	}
}

int find(int x) {
	if (Par[x] == x) {
		return x;
	}
	else {
		return Par[x] = find(Par[x]);
	}
}

void unite(int  x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (Rank[x] < Rank[y]) {
		Par[x] = y;
	}
	else {
		Par[y] = x;
		if (Rank[x] == Rank[y])Rank[x]++;
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

// ソート時に比較するための関数 
bool comp(const edge& e1, const edge& e2) {
	return e1.cost < e2.cost;
}

int kruskal() {
	init(V);
	sort(e.begin(), e.end(), comp);
	int ans = 0;
	for (int i = 0; i<E; i++) {
		if (!same(e[i].from, e[i].to)) {
			unite(e[i].from, e[i].to);
			ans += e[i].cost;
		}
	}
	return ans;
}

int main() {
	int n;
	int x, y;

	cin >> n;
	V = n;
	vector<pair<int,pair<int, int>>>xy, yx;
	REP(i, n) {
		cin >> x >> y;
		xy.emplace_back(mp(x,mp( y, i)));
		yx.emplace_back(mp(y, mp(x, i)));
	}
	sort(ALL(xy));
	sort(ALL(yx));
	REP(i, xy.size() - 1) {
		E++;
		e.emplace_back(edge{ xy[i].second.second,xy[i + 1].second.second,min(abs(xy[i].first - xy[i + 1].first),abs(xy[i].second.first - xy[i + 1].second.first)) });
	}
	REP(i, yx.size() - 1) {
		E++;
		e.emplace_back(edge{ yx[i].second.second,yx[i + 1].second.second,min(abs(yx[i].first - yx[i + 1].first),abs(yx[i].second.first - yx[i + 1].second.first)) });
	}
	cout << kruskal() << endl;
}