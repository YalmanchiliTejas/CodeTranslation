#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

#define REP(i, n) for(ll i = 0;i < n;i++)
#define REPR(i, n) for(ll i = n;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define FORR(i, m, n) for(ll i = m;i >= n;i--)
#define REPO(i, n) for(ll i = 1;i <= n;i++)
#define ll long long
#define INF 1999999999
#define MINF -1999999999
#define INF64 (ll)1 << 60
#define ALL(n) n.begin(),n.end()
#define MOD 1000000007
#define P pair<ll, ll>



#define PP pair<ll, P>
ll n, ans = 0;
vector<P> a, b;
vector<PP> c;

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

UnionFind u(110000);
int main() {
	cin >> n;
	REP(i, n) {
		ll x, y;
		cin >> x >> y;
		a.push_back(P(x, i));
		b.push_back(P(y, i));
	}
	sort(ALL(a));
	sort(ALL(b));
	REP(i, n - 1) {
		c.push_back(PP(abs(a[i].first - a[i + 1].first), P(a[i].second, a[i + 1].second)));
		c.push_back(PP(abs(b[i].first - b[i + 1].first), P(b[i].second, b[i + 1].second)));
	}
	sort(ALL(c));
	REP(i, c.size()) {
		if (!u.findSet(c[i].second.first, c[i].second.second)) {
			u.unionSet(c[i].second.first, c[i].second.second);
			ans += c[i].first;
		}
	}
	cout << ans << endl;
}


