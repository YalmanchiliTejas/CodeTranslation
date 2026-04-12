#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5 + 5;
int cnt;
int par[maxn];
int n;

struct roads {
	int x, y, id;
	roads(int _x = 0, int _y = 0, int _z = 0) :x(_x), y(_y), id(_z) {};
}road[maxn], road2[maxn * 2];

bool cmp1(const roads &a, const roads &b) {
	return a.x < b.x;
}

bool cmp2(const roads &a, const roads &b) {
	return a.y < b.y;
}

bool cmp3(const roads &a, const roads &b) {
	return a.id < b.id;
}

void init() {
	for (int i = 1; i <= n; i++)
		par[i] = i;
}

int find(int x) {
	if (x == par[x])return x;
	return par[x] = find(par[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	par[x] = y;
}

bool same(int x, int y) {
	return find(x) == find(y);
}

int kruskal() {
	int sum = 0;
	init();
	for (int i = 0; i<cnt; i++) {
		roads r = road2[i];
		if (r.id == 0)unite(r.x, r.y);
		if (!same(r.x, r.y)) {
			unite(r.x, r.y);
			sum += r.id;
		}
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> road[i].x >> road[i].y;
			road[i].id = i + 1;
		}
		cnt = 0;
		sort(road, road + n, cmp1);
		for (int i = 1; i < n; i++) {
			road2[cnt++] = roads( road[i].id,road[i - 1].id,road[i].x - road[i - 1].x );
		}
		sort(road, road + n, cmp2);
		for (int i = 1; i < n; i++) {
			road2[cnt++] = roads(road[i].id, road[i - 1].id, road[i].y - road[i - 1].y);
		}
		sort(road2, road2 + cnt, cmp3);
		int t = kruskal();
		cout << t << endl;
	}
	return 0;
}