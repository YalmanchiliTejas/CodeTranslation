#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"

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
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };
struct Compress {
	map<int, int>mp;
	map<int, int>revmp;

	Compress(vector<int>vs) {
		sort(vs.begin(), vs.end());
		for (int i = 0; i < vs.size(); ++i) {
			mp[vs[i]] = i;
			revmp[i] = vs[i];
		}
	}
	Compress(const set<int>&vs) {
		int num = 0;
		for(auto v:vs){
			mp[v] = num;
			revmp[num] = v;
			num++;
		}
	}
};
struct rect {
	int l, t, r, b;
};
int field[300][300][4];
int main() {
	while (1) {
		memset(field, 0, sizeof(field));
		int N; cin >> N;
		if (!N)break;
		set<int>xs, ys;
		vector<rect>rects;
		for (int i = 0; i < N; ++i) {
			int l, t, r, b; cin >> l >> b>> r >>t;
			xs.emplace(l); xs.emplace(r);
			ys.emplace(t); ys.emplace(b);
			rects.push_back(rect{ l,t,r,b });
		}
		Compress xc(xs);
		Compress yc(ys);
		for (auto &re : rects) {
			re.b = yc.mp[re.b];
			re.t = yc.mp[re.t];
			re.l = xc.mp[re.l];
			re.r = xc.mp[re.r];
		}
		for (auto &re : rects) {
			re.b *= 2;
			re.t *= 2;
			re.l *= 2;
			re.r *= 2;
			re.b += 20;
			re.t += 20;
			re.l += 20;
			re.r += 20;
		}
		for (auto &re : rects) {
			for (int x = re.l; x < re.r;++x) {
				field[re.t][x][3] = true;
				field[re.t - 1][x][1] = true;
				field[re.b][x][3] = true;
				field[re.b - 1][x][1] = true;
			}
			for (int y = re.t; y < re.b; ++y) {
				field[y][re.l][0] = true;
				field[y][re.l - 1][2] = true;
				field[y][re.r][0] = true;
				field[y][re.r - 1][2] = true;
			}
		}
		UnionFind uf(90000);
		for (int y = 1; y < 299; ++y) {
			for (int x = 1; x < 299; ++x) {
				const int ahash = y * 300 + x;
				for (int way = 0; way < 4; ++way) {
					if (!field[y][x][way]) {
						const int ny = y + dy[way];
						const int nx = x + dx[way];
						const int bhash = ny * 300 + nx;
						uf.unionSet(ahash, bhash);
					}
				}
			}
		}
		set<int>aset;
		for (int y = 1; y < 299; ++y) {
			for (int x = 1; x < 299; ++x) {
				const int ahash = y * 300 + x;
				aset.emplace(uf.root(ahash));
			}
		}
		cout << aset.size() << endl;
	}
	return 0;
}