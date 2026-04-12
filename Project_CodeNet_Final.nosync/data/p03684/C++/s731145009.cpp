#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <numeric>
#include <math.h>
#include <algorithm>
#include <functional>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <complex>
#include <bitset>
#define full(c) c.begin(), c.end()
#define vector2d(name,type,h,w,init) vector<vector<type>> name(h,vector<type>(w,init)) 
const int PRIME = 1000000007;
const int INT_INF = 2147483647;
const long long int LL_INF = 9223372036854775807;
const double PI = acos(-1);
const double EPS = 0.000000001;
typedef unsigned long long int ull;
typedef long long int ll;
using namespace std;

struct point {
	int n, x, y;
};
struct edge {
	int n1, n2, w;
};
class UnionFind {
private:
	vector<int> parent, rank;
public:
	UnionFind(int n) {
		int i;
		for (i = 0; i < n; i++) {
			parent.push_back(i);
			rank.push_back(0);
		}
	}
	int root(int x) {
		if (parent[x] == x) return x;
		else return parent[x] = root(parent[x]);
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	void unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return;
		if (rank[x] < rank[y]) parent[x] = y;
		else {
			parent[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
	}
};
int main() {
	int i, n, cnt = 0;
	cin >> n;
	vector<point> p(n);
	vector<edge> e;
	for (i = 0; i < n; i++) {
		p[i].n = i;
		cin >> p[i].x >> p[i].y;
	}
	sort(full(p), [](const point &l, const point &r) {return l.x > r.x; });
	for (i = 0; i < n - 1; i++) {
		int n1, n2;
		n1 = p[i].n;
		n2 = p[i + 1].n;
		if (n1 > n2) swap(n1, n2);
		e.push_back({ n1,n2,p[i].x - p[i + 1].x });
	}
	sort(full(p), [](const point &l, const point &r) {return l.y > r.y; });
	for (i = 0; i < n - 1; i++) {
		int n1, n2;
		n1 = p[i].n;
		n2 = p[i + 1].n;
		if (n1 > n2) swap(n1, n2);
		e.push_back({ n1,n2,p[i].y - p[i + 1].y });
	}
	UnionFind uf(n);
	sort(full(e), [](const edge &l, const edge &r) {return l.w < r.w; });
	for (i = 0; i < e.size(); i++) {
		if (uf.same(e[i].n1, e[i].n2) == false) {
			uf.unite(e[i].n1, e[i].n2);
			cnt += e[i].w;
		}
	}
	cout << cnt << endl;
	return 0;
}
