#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define fore(i,a) for(auto &i:a)

typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 1<<25;
const ll INFL = 1223372036854775807;
const ll mod = 1000000007;



struct UnionFind {
	vector<int> par;
	int cnt;
	UnionFind(int size_) : par(size_, -1), cnt(size_) { }
	bool unite(int x, int y) {
		x = find(x); y = find(y);
		if (x != y) {
			if (par[y] < par[x]) swap(x, y);
			par[x] += par[y]; par[y] = x;
			cnt--;
		}
		return x != y;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int find(int x) {
		return par[x] < 0 ? x : par[x] = find(par[x]);
	}
	int size(int x) {
		return -par[find(x)];
	}
	int size() {
		return cnt;
	}
};



int main() {
	int n;
	cin >> n;
	
	VVLL x(n, VLL(2)), y(n, VLL(2));

	REP(i, n) {
		cin >> x[i][0] >> y[i][0];
		x[i][1] = i;
		y[i][1] = i;
	}

	sort(ALL(x));
	sort(ALL(y));


	UnionFind uf(n);

	ll ans = 0;

	priority_queue < pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;

	REP(i, n - 1) {
		q.push(make_pair(x[i + 1][0] - x[i][0], x[i + 1][1] * n + x[i][1]));
		q.push(make_pair(y[i + 1][0] - y[i][0], y[i + 1][1] * n + y[i][1]));
	}

	while (!q.empty()) {
		pair<ll, ll>p = q.top();
		q.pop();
		if (!uf.same(p.second / n, p.second%n)) {
			uf.unite(p.second / n, p.second%n);
			ans += p.first;
		}
	}

	
	cout << ans << endl;



	return 0;
}