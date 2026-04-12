#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
ll ans;
int par[100005];
int root(int p)
{
	if (par[p] == p)return p;
	return par[p] = root(par[p]);
}
void uni(int a, int b) {
	a = root(a); b = root(b);
	par[a] = b;
}
bool sameuni(int a, int b) {
	a = root(a); b = root(b);
	return (a == b);
}
struct point {
	int x, y, idx;
	point(int a, int b, int c) {
		x = a, y = b, idx = c;
	}
};
vector<point> v, v2;
bool cmpx(point a, point b)
{
	if (a.x != b.x)return a.x < b.x;
	if (a.y != b.y)return a.y < b.y;
	return a.idx < b.idx;
}
bool cmpy(point a, point b)
{
	if (a.y != b.y)return a.y < b.y;
	if (a.x != b.x)return a.x < b.x;
	return a.idx < b.idx;
}
struct Edge {
	int n1, n2, cost;
	Edge(int a, int b, int c) {
		n1 = a, n2 = b, cost = c;
	}
	bool operator<(const Edge &i)const {
		if (cost != i.cost)return cost < i.cost;
		return n1 < i.n1;
	}
};
vector<Edge> E;
int n;
int main() {
	scanf("%d", &n);
	for (int x, y, i = 1; i <= n; i++) {
		par[i] = i;
		scanf("%d %d", &x, &y);
		v.push_back(point(x, y, i));
		v2.push_back(point(x, y, i));
	}
	sort(v.begin(), v.end(), cmpx);
	sort(v2.begin(), v2.end(), cmpy);
	for (int i = 1; i < v.size(); i++) {
		int cc = min(abs(v[i - 1].x - v[i].x), abs(v[i - 1].y - v[i].y));
		E.push_back(Edge(v[i - 1].idx, v[i].idx, cc));
		cc = min(abs(v2[i - 1].x - v2[i].x), abs(v2[i - 1].y- v2[i].y));
		E.push_back(Edge(v2[i - 1].idx, v2[i].idx, cc));
	}
	sort(E.begin(), E.end());
	for (int i = 0; i < E.size(); i++) {
		if (sameuni(E[i].n1, E[i].n2))continue;
		uni(E[i].n1, E[i].n2);
		ans += E[i].cost;
	}
	printf("%I64d", ans);
}