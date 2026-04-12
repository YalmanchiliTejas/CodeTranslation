#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <functional>
#include <string>
#include <utility>
#include <cstdio>
#include <cmath>
#include <deque>
#include <chrono>

#define REP(i,n) for(int i = 0; i < (n); ++i)
#define REP1(i,n) for(int i = 1; i <= (n); ++i)
#define RREP(i, n) for(int i = (n) - 1; i >= 0; --i)
#define ALL(a) begin(a), end(a)
#define MP(a,b) make_pair((a), (b))
#define ROUNDUP(a,b) ((a) / (b) + ((a) % (b) == 0 ? 0 : 1))
#define X first
#define Y second
#define DEBUG(a) cout << #a << ": " << a << "\n"
// #define DEBUG(a) {}

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 1;
constexpr ll LLINF = 4 * 1e18 + 1;
// constexpr int INF = 2147483647; // 2 * 1e9
// constexpr ll LLINF = 9223372036854775807; // 9 * 1e18

template<typename T>
T debug(T x) {
	DEBUG(x);
	return x;
}
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

using Road = pair<int, pii>;

bool lessery(pair<pii, int> x, pair<pii, int> y){
	return x.X.Y < y.X.Y;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	ll ans = 0;
	cin >> n;
	vector<pair<pii, int>> towns(n);
	UnionFind uf(n);
	priority_queue<Road, vector<Road>, greater<Road>> roads;
	REP(i, n) {
		cin >> towns[i].X.X >> towns[i].X.Y;
		towns[i].Y = i;
	}
	sort(ALL(towns));
	REP(i, n - 1) roads.push(MP(abs(towns[i].X.X - towns[i+1].X.X), MP(towns[i].Y, towns[i + 1].Y)));
	sort(ALL(towns), lessery);
	REP(i, n - 1) roads.push(MP(abs(towns[i].X.Y - towns[i+1].X.Y), MP(towns[i].Y, towns[i + 1].Y)));
	
	
	while(!roads.empty()){
		auto r = roads.top(); roads.pop();
		if(uf.findSet(r.Y.X, r.Y.Y)) continue;
		uf.unionSet(r.Y.X, r.Y.Y);
		ans += r.X;
		//cout << r.X << " " << r.Y.X << " " << r.Y.Y << "\n";
	}
	cout << ans << "\n";
	return 0;
}
