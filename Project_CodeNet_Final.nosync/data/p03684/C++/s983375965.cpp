#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> Point;
typedef pair<int,Point> Edge;
#define x first
#define y second

const int N = 100010;
int n;
Point a[N];

int dist(Point a, Point b) {
	return min(abs(a.x - b.x), abs(a.y - b.y));
}

bool cmp_x(Point a, Point b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool cmpx(Edge a, Edge b) {
	bool ok = cmp_x(a.second, b.second);
	if (ok) return true;
	else if (a.second == b.second && a.first < b.first);
	return false;
}

bool cmp_y(Point a, Point b) {
	return a.y < b.y || (a.y == b.y && a.x < b.x);
}
bool cmpy(Edge a, Edge b) {
	bool ok = cmp_y(a.second, b.second);
	if (ok) return true;
	else if (a.second == b.second && a.first < b.first);
	return false;
}

int par[N];
int anc(int p) { return p == par[p] ? p : par[p] = anc(par[p]); }
void join(int p, int q) { par[anc(p)] = anc(q); }

vector <Edge> e, A;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y;
	for (int i = 1; i <= n; ++i) A.push_back(make_pair(i, a[i]));
	sort(A.begin(), A.end(), cmpx);
	for (int i = 0; i < n - 1; ++i) {
		int d = dist(A[i].second, A[i + 1].second);
		e.push_back(Edge(d, make_pair(A[i].first, A[i + 1].first)));
	}
	sort(A.begin(), A.end(), cmpy);
	for (int i = 0; i < n - 1; ++i) {
		int d = dist(A[i].second, A[i + 1].second);
		e.push_back(Edge(d, make_pair(A[i].first, A[i + 1].first)));
	}

	for (int i = 1; i <= n; ++i) par[i] = i;
	sort(e.begin(), e.end());
	long long ans = 0;
	for (auto edge: e) {
		int u = edge.second.first, v = edge.second.second;
		u = anc(u), v = anc(v);
		if (u != v) {
			join(u,v);
			ans += edge.first;
		}
	}
	cout << ans << endl;
}