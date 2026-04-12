#include <cstdio>
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
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
#define INF 1LL<<60
#define PI acos(-1)
typedef long long ll;
typedef pair<int, int> p_ii;

struct UF {
	vector<int> v;
	UF(int n) : v(n, -1) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		if (-v[x] < -v[y]) swap(x, y);
		v[x] += v[y]; v[y] = x;
	}
	bool root(int x) { return v[x] < 0; }
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};


int main() {
	int n; cin >> n;
	vector<pair<int, p_ii>> edge;
	vector<pair<p_ii, int>> p1(n), p2(n);
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		p1[i] = pair<p_ii,int>{ p_ii{a, b}, i };
		p2[i] = pair<p_ii,int>{ p_ii{b, a}, i };
	}
	sort(p1.begin(), p1.end());
	sort(p2.begin(), p2.end());

	for (int i = 0; i < n-1; i++) {//xについての辺
		p_ii p = p1[i].first, q = p1[i + 1].first;
		int tmp = min(abs(p.first - q.first), abs(p.second - q.second));
		edge.push_back(pair<int, p_ii>(tmp, p_ii(p1[i].second, p1[i + 1].second)));
	}

	for (int i = 0; i < n - 1; i++) {//yについての辺
		p_ii p = p2[i].first, q = p2[i + 1].first;
		int tmp = min(abs(p.first - q.first), abs(p.second - q.second));
		edge.push_back(pair<int, p_ii>(tmp, p_ii(p2[i].second, p2[i + 1].second)));
	}

	sort(edge.begin(), edge.end());

	ll ret = 0;
	UF road(n + 2);

	for (int i = 0; i < edge.size(); i++) {
		p_ii p = edge[i].second;
		if (!road.same(p.first, p.second)) {
			road.unite(p.first, p.second);
			ret += (ll)edge[i].first;
		}
	}
	cout << ret << endl;

	return 0;
}