#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
static const int INF = 1000010000;
static const int MOD = 1000000007;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb push_back
#define mp make_pair
#define np next_permutation
#define pq priority_queue

//int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

struct edge {
	int u, v;
	ll cost;
};

bool comp(const edge& e1, const edge& e2) {
	return e1.cost < e2.cost;
}

#define N 100010

int par[N];
int urank[N];

void init(int n) {
	REP(i, n) {
		par[i] = i;
		urank[i] = 0;
	}
}

int find(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;

	if (urank[x] < urank[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (urank[x] == urank[y]) urank[x]++;
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

edge es[N];

bool used[N];
int V, E;

ll kruskal() {
	sort(es, es + E, comp);
	init(V);
	ll res = 0;
	REP(i, E) {
		edge e = es[i];
		if (!same(e.u, e.v) && !used[e.u] && !used[e.v]) {
			unite(e.u, e.v);
			res += e.cost;
			used[e.u] = used[e.v] = true;
		}
	}
	return res;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((a * 100 + b * 10 + c) % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
