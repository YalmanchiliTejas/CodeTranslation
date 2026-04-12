#include <bits/stdc++.h>
#define pii pair<int, int>
#define pb push_back
using namespace std;

const int N = 1e5 + 2;

struct Point {
	int x, y, id;
};

int n;
Point p[N], og[N];
vector<pair<int, int>>edges;

bool cmp1(const Point &a, const Point &b ) {
	if (a.x == b.x)return a.y < b.y;
	return a.x < b.x;
}
bool cmp2(const Point &a, const Point &b) {
	if (a.y == b.y)return a.x < b.x;
	return a.y < b.y;
}

int cost(pair<int, int>a) {
	int d1 = min(abs(og[a.first].x - og[a.second].x), abs(og[a.first].y - og[a.second].y));
	return d1;
}


bool cmpEdges(const pair<int, int>&a, const pair<int, int>&b) {
	return cost(a) < cost(b);
}

void buildEdges(bool tip) {
	if (!tip) sort(p, p + n, cmp1);
	else sort(p, p + n, cmp2);
	set<pair<int, int>>y;
	map < int, vector<pair<int, int>>>coords;
	for (int i = 0; i < n; ++i) {
		coords[p[i].x].emplace_back(p[i].y, p[i].id);
	}
	for (auto &all : coords) {
		auto &vec = all.second;
		sort(vec.begin(), vec.end());
		for (auto &itr : vec) {
			if(y.empty()) continue;
			auto good = y.lower_bound(make_pair(itr.first, -1));
			if (good != end(y)) {
				edges.emplace_back(itr.second, good->second);
			}
			if (good != begin(y)) {
				good--;
				edges.emplace_back(good->second, itr.second);
			}
		}
		for (int i = 0; i < vec.size() - 1; ++i)
			edges.emplace_back(vec[i].second, vec[i + 1].second);
		for (auto &itr : vec)
			y.insert(make_pair(itr.first, itr.second));
	}
	y.clear();
	for (auto all = coords.rbegin(); all != coords.rend(); ++all) {
		auto &vec = all->second;
		for (auto &itr : vec) {
			if(y.empty()) continue;
			auto good = y.lower_bound(make_pair(itr.first, -1));
			if (good != end(y)) {
				edges.emplace_back(itr.second, good->second);
			}
			if (good != begin(y)) {
				good--;
				edges.emplace_back(good->second, itr.second);
			}
		}
		for (int i = 0; i < vec.size() - 1; ++i)
			edges.emplace_back(vec[i].second, vec[i + 1].second);
		for (auto &itr : vec)
			y.insert(make_pair(itr.first, itr.second));
	}
}

int dsu[N];

int get(int node) {
	if (node == dsu[node]) {
		return node;
	}
	return dsu[node] = get(dsu[node]);
}

void join(int a, int b) {
	a = get(a);
	b = get(b);
	dsu[a] = b;
}

void initdsu() {
	for (int i = 0; i < n; ++i) {
		dsu[i] = i;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> p[i].x >> p[i].y, p[i].id = i, og[i] = p[i];
	sort(p, p + n, cmp1);
	for (int i = 1; i < n; ++i) {
		edges.emplace_back(p[i].id, p[i - 1].id);
	}
	sort(p, p + n, cmp2);
	for (int i = 1; i < n; ++i) edges.emplace_back(p[i].id, p[i - 1].id);
	buildEdges(0);
	for (int i = 0; i < n; ++i) swap(p[i].x, p[i].y);
	buildEdges(1);
	initdsu();
	sort(edges.begin(), edges.end(), cmpEdges);
	long long apm = 0;
	for (auto itr : edges) {
		if(itr.first == itr.second)
			continue;
		if (get(itr.first) != get(itr.second))
			apm += cost(itr), join(itr.first, itr.second);
	}
	cout << apm;

}
