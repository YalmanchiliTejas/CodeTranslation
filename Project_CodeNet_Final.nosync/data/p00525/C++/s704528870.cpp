#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <iterator>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

// -------------------------------------------------- ライブラリ 1（非自明なやつ） ---------------------------------------------------
const int MAX_N = (1 << 19);

class SuperSegmentTree {
public:
	int size_ = 1;
	int A[MAX_N];
	set<int> dat[MAX_N * 2], idx[MAX_N];
	vector<int> I;

	void init(int sz) {
		while (size_ <= sz) size_ *= 2;
		for (int i = 0; i <= sz; i++) A[i] = 0;
	}
	void dels(int pos, int x) {
		idx[x].erase(pos); pos += size_;
		dat[pos].erase(x);
		while (pos >= 1) {
			auto itr1 = dat[pos * 2 + 0].lower_bound(x);
			auto itr2 = dat[pos * 2 + 1].lower_bound(x);
			int cntv = 0;
			if (itr1 == dat[pos * 2 + 0].end() || (*itr1) != x) cntv++;
			if (itr2 == dat[pos * 2 + 1].end() || (*itr2) != x) cntv++;
			if (cntv == 2) dat[pos].erase(x);
			pos >>= 1;
		}
	}
	void adds(int pos, int x) {
		idx[x].insert(pos); pos += size_;
		while (pos >= 1) {
			dat[pos].insert(x);
			pos >>= 1;
		}
	}
	void update(int pos, int x) {
		if (A[pos] != 0) {
			dels(pos, A[pos]);
			A[pos] = 0;
		}
		if (x != 0) {
			A[pos] = x;
			adds(pos, A[pos]);
		}
	}
	bool check(int x) {
		if (idx[x].size() >= 1) return true;
		return false;
	}
	int reads(int pos) {
		return A[pos];
	}
	void query(int l, int r, int a, int b, int u) {
		if (l <= a && b <= r) {
			auto itr = dat[u].begin();
			while (itr != dat[u].end()) { I.push_back(*itr); itr++; }
			return;
		}
		if (r <= a || b <= l) return;
		query(l, r, a, (a + b) >> 1, u * 2);
		query(l, r, (a + b) >> 1, b, u * 2 + 1);
	}
	void conquer(int cl, int cr) {
		I.clear();
		query(cl, cr, 0, size_, 1);
		sort(I.begin(), I.end());
		I.erase(unique(I.begin(), I.end()), I.end());

		vector<pair<int, int>> Z;
		for (int i : I) Z.push_back(make_pair(idx[i].size(), i));
		sort(Z.begin(), Z.end());

		for (int i = 0; i < (int)Z.size() - 1; i++) {
			int pos = Z[i].second; vector<int> vecs;
			auto itr = idx[pos].begin();
			while (itr != idx[pos].end()) { vecs.push_back(*itr); itr++; }
			for (int j : vecs) update(j, Z[Z.size() - 1].second);
		}
		return;
	}
};

// --------------------------------------------------- ライブラリ 2（自明なやつ） ----------------------------------------------------
class BIT {
public:
	int size_ = 1;
	vector<int> bit;

	void init(int sz) {
		size_ = sz + 2;
		bit.resize(size_ + 2, 0);
	}
	void add(int pos, int x) {
		pos++;
		while (pos <= size_) {
			bit[pos] += x;
			pos += (pos & -pos);
		}
	}
	int sum(int pos) {
		pos++; int s = 0;
		while (pos >= 1) {
			s += bit[pos];
			pos -= (pos & -pos);
		}
		return s;
	}
};

struct Point {
	int px, py;
};

bool operator<(const Point& a1, const Point& a2) {
	if (a1.px < a2.px) return true;
	if (a1.px > a2.px) return false;
	if (a1.py < a2.py) return true;
	return false;
}

bool operator==(const Point& a1, const Point& a2) {
	if (a1.px == a2.px && a1.py == a2.py) return true;
	return false;
}

class UnionFind {
public:
	vector<int> par;

	void init(int sz) {
		par.resize(sz, -1);
	}
	int root(int pos) {
		if (par[pos] == -1) return pos;
		par[pos] = root(par[pos]);
		return par[pos];
	}
	void unite(int u, int v) {
		u = root(u); v = root(v);
		if (u == v) return;
		par[u] = v;
	}
	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
};

// -------------------------------------------- 本質 -----------------------------------------------
int H, W, N;
Point G1[1 << 17], G2[1 << 17];
vector<int> V[1 << 18][3];
set<int> Set;
SuperSegmentTree S;

int main() {
	// ステップ 1. 入力
	scanf("%d%d%d", &W, &H, &N);
	for (int i = 1; i <= N; i++) scanf("%d%d%d%d", &G1[i].px, &G1[i].py, &G2[i].px, &G2[i].py);
	G1[N + 1] = Point{ 0, 0 }; G2[N + 1] = Point{ W,0 };
	G1[N + 2] = Point{ 0, H }; G2[N + 2] = Point{ W,H };
	G1[N + 3] = Point{ 0, 0 }; G2[N + 3] = Point{ 0,H };
	G1[N + 4] = Point{ W, 0 }; G2[N + 4] = Point{ W,H };
	N += 4;

	// ステップ 2. 座標圧縮
	vector<int> LX, LY;
	for (int i = 1; i <= N; i++) {
		LX.push_back(G1[i].px); LY.push_back(G1[i].py);
		LX.push_back(G2[i].px); LY.push_back(G2[i].py);
	}
	sort(LX.begin(), LX.end()); LX.erase(unique(LX.begin(), LX.end()), LX.end());
	sort(LY.begin(), LY.end()); LY.erase(unique(LY.begin(), LY.end()), LY.end());
	for (int i = 1; i <= N; i++) {
		G1[i].px = lower_bound(LX.begin(), LX.end(), G1[i].px) - LX.begin();
		G1[i].py = lower_bound(LY.begin(), LY.end(), G1[i].py) - LY.begin();
		G2[i].px = lower_bound(LX.begin(), LX.end(), G2[i].px) - LX.begin();
		G2[i].py = lower_bound(LY.begin(), LY.end(), G2[i].py) - LY.begin();
		if (G1[i].px > G2[i].px) swap(G1[i].px, G2[i].px);
		if (G1[i].py > G2[i].py) swap(G1[i].py, G2[i].py);
	}
	W = LX.size() - 1;
	H = LY.size() - 1;

	// ステップ 3. 頂点個数の数え上げ（準備編）
	for (int i = 1; i <= N; i++) {
		if (G1[i].px == G2[i].px) {
			V[G1[i].px][1].push_back(i);
		}
		else {
			V[G1[i].px][0].push_back(i);
			V[G2[i].px][2].push_back(i);
		}
	}

	long long Vertex = 0;
	long long Edges = N;
	long long Connect = 0;

	// ステップ 4. 頂点個数の数え上げ（実践編）
	BIT Z; Z.init(H + 2);
	for (int i = 0; i <= W; i++) {
		for (int j : V[i][0]) Z.add(G1[j].py, 1);
		for (int j : V[i][1]) {
			Vertex += 1LL * (Z.sum(G2[j].py) - Z.sum(G1[j].py - 1));
		}
		for (int j : V[i][2]) Z.add(G1[j].py, -1);
	}

	// ステップ 5. 連結成分数の数え上げ
	int cnts = 0; S.init(H + 2);
	for (int i = 0; i <= W; i++) {
		for (int j : V[i][0]) {
			cnts++;
			S.update(G1[j].py, cnts);
			Set.insert(G1[j].py);
		}
		for (int j : V[i][1]) {
			auto itr = Set.lower_bound(G1[j].py);
			if (itr == Set.end() || (*itr) > G2[j].py) Connect++;
			else {
				S.conquer(G1[j].py, G2[j].py + 1);
			}
		}
		for (int j : V[i][2]) {
			int val = S.reads(G1[j].py);
			S.update(G1[j].py, 0);
			if (S.check(val) == false) Connect++;
			Set.erase(G1[j].py);
		}
	}

	// ステップ 6. 出力
	cout << Vertex - Edges + Connect << endl;
	return 0;
}
