#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define REP(i,n) FOR(i,0,n)
typedef long long ll;
const ll inf = 2e9 + 7;

template <class T = int> T in() { T x; cin >> x; return (x); }

typedef pair<int, pair<int, int>> edge;

class UnionFind {
private:
	vector<int> par;
public:
	UnionFind(int N) { par = vector<int>(N, -1); }
	int find(int x);
	ll size(int x);
	void unite(int x, int y);
	bool same(int x, int y);
};



class Kruskal {
private:
	UnionFind *uf;
	vector<edge> e;
public:
	vector<edge> mst;
	Kruskal(int N) { uf = new UnionFind(N); }
	void add(int x, int y, ll z);
	void run();
};



//----UnionFind-------------------------------
int UnionFind::find(int x) {
	if (par[x] < 0) return x;
	else return par[x] = find(par[x]);
}

ll UnionFind::size(int x) {
	return -par[find(x)];
}

void UnionFind::unite(int x, int y) {
	x = find(x);
	y = find(y);

	//大きい方に小さい方をくっ付ける
	if (size(x) < size(y)) swap(x, y);
	par[x] += par[y];
	par[y] = x;
}

bool UnionFind::same(int x, int y) {
	x = find(x);
	y = find(y);
	return x == y;
}



//----Kruskal-------------------------------
void Kruskal::add(int x, int y, ll z) {
	e.push_back({ z,{x,y} });
}

void Kruskal::run() {
	sort(e.begin(), e.end());
	for (auto x : e) {
		if (uf->same(x.second.first, x.second.second)) {
			continue;
		}
		else {
			mst.push_back(x);
			uf->unite(x.second.first, x.second.second);
		}
	}
}

typedef struct {
	ll x, y;
	int I;
} pos;

//左から右へ
bool cmpx(pos &a, pos &b) {
	if (a.x != b.x) return a.x < b.x;
	else return a.y < b.y;
}

//下から上へ
bool cmpy(pos &a, pos &b) {
	if (a.y != b.y) return a.y < b.y;
	else return a.x < b.x;
}

int main() {
	int n = in();
	vector<pos> tate, yoko;
	tate = vector<pos>(n); yoko = vector<pos>(n);
	REP(i, n) {
		yoko[i].I = tate[i].I = i;
		yoko[i].x = tate[i].x = in();
		yoko[i].y = tate[i].y = in();
	}
	sort(yoko.begin(), yoko.end(), cmpx);
	sort(tate.begin(), tate.end(), cmpy);
	Kruskal ks(n);
	ks.add(yoko[0].I, yoko[1].I, min(abs(yoko[1].x - yoko[0].x), abs(yoko[1].y - yoko[0].y)));
	ks.add(yoko[n - 1].I, yoko[n - 2].I, min(abs(yoko[n - 1].x - yoko[n - 2].x), abs(yoko[n - 1].y - yoko[n - 2].y)));
	ks.add(tate[0].I, tate[1].I, min(abs(tate[1].x - tate[0].x), abs(tate[1].y - tate[0].y)));
	ks.add(tate[n - 1].I, tate[n - 2].I, min(abs(tate[n - 1].x - tate[n - 2].x), abs(tate[n - 1].y - tate[n - 2].y)));
	FOR(i, 1, n - 1) {
		ks.add(yoko[i].I, yoko[i - 1].I, min(abs(yoko[i].x - yoko[i - 1].x), abs(yoko[i].y - yoko[i - 1].y)));
		ks.add(yoko[i].I, yoko[i + 1].I, min(abs(yoko[i].x - yoko[i + 1].x), abs(yoko[i].y - yoko[i + 1].y)));
		ks.add(tate[i].I, tate[i - 1].I, min(abs(tate[i].x - tate[i - 1].x), abs(tate[i].y - tate[i - 1].y)));
		ks.add(tate[i].I, tate[i + 1].I, min(abs(tate[i].x - tate[i + 1].x), abs(tate[i].y - tate[i + 1].y)));
	}
	ks.run();
	ll ans = 0;
	for (auto x : ks.mst) {
		ans += x.first;
	}
	cout << ans << endl;
}