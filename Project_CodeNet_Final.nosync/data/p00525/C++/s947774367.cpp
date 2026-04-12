
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

class union_find {
private:
	vector<int>parent;
	vector<int>rank;
	vector<int>clump;
public:
	union_find(int siz) {
		parent.resize(siz);
		rank.resize(siz);
		clump.resize(siz);
		for (int i = 0; i < siz; ++i) {
			parent[i] = i;
			rank[i] = 0;
			clump[i] = 1;
		}
	}
	void unite(int x, int y) {
		int xr = find(x);
		int yr = find(y);
		if (xr == yr)return;
		if (rank[xr] > rank[yr]) {
			parent[yr] = xr;
			clump[xr] += clump[yr];
		}
		else if (rank[yr] > rank[xr]) {
			parent[xr] = yr;
			clump[yr] += clump[xr];
		}
		else if (xr != yr) {
			parent[yr] = xr;
			clump[xr] += clump[yr];
			++rank[xr];
		}
	}
	int find(int x) {
		if (parent[x] == x) {
			return x;
		}
		else {
			return parent[x] = find(parent[x]);
		}
	}
	bool check(int x, int y) {
		return find(x) == find(y);
	}
	int size(int x) {
		return clump[find(x)];
	}
};

struct line {
	bool dir;//false:横 true:縦
	LL pos;
	LL b1, b2;
	int id;
	line(bool dir, LL pos, LL b1, LL b2, int id)
		:dir(dir), pos(pos), b1(b1), b2(b2), id(id)
	{}
	bool operator<(const line& o) const {
		if (pos == o.pos) {
			if (b1 == o.b1) {
				return b2 < o.b2;
			}
			return b1 < o.b1;
		}
		return pos < o.pos;
	}
};
vector<line>vec;
vector<LL>tate;
LL W, H, N;

template<typename T>
class BIT {
private:
	vector<T>arr;
	int siz;
public:
	BIT(int n) :siz(1) {
		while (siz < n)siz *= 2;
		arr.resize(siz + 1);
	}
	//[0,x)までの和を取得する
	T query(int x) const {
		T s = 0;
		while (x > 0) {
			s += arr[x];
			x -= (x & -x);
		}
		return s;
	}
	//xに値kを加算する
	void add(int x, const T& k) {
		++x;
		while (x <= siz) {
			arr[x] += k;
			x += (x & -x);
		}
	}
};


vector<LL>border;
vector<vector<pair<pair<LL, LL>, int>>>seg;
int segwidth = 1;

void query(int a, int b, union_find& uf, int id, int yok, int k = 0, int l = 0, int r = -1) {
	if (r < 0)r = segwidth;
	if (r <= a || b <= l)return;
	if (a <= l && r <= b) {
		//マージする
		if (seg[k].empty())return;
		int lim = -1;
		int endid = 0;
		for (int xx = seg[k].size() - 1; xx >= 0; --xx) {
			if (seg[k][xx].first.first >= yok) {
				lim = xx;
				break;
			}
			if (seg[k][xx].first.first < yok && yok < seg[k][xx].first.second) {
				uf.unite(id, seg[k][xx].second);
				endid = seg[k][xx].second;
			}
		}
		bool flag = false;
		auto very = seg[k][seg[k].size() - 1];
		very.second = endid;
		for (int xx = seg[k].size() - 1; xx > lim; --xx) {
			flag = true;
			very.first.first = min(very.first.first, seg[k][xx].first.first);
			very.first.second = max(very.first.second, seg[k][xx].first.second);
			seg[k].pop_back();
		}
		if (flag) {
			seg[k].push_back(very);
		}
		return;
	}
	int mid = (l + r) / 2;
	query(a, b, uf, id, yok, k * 2 + 1, l, mid);
	query(a, b, uf, id, yok, k * 2 + 2, mid, r);
}

int main(void)
{
	cin >> W >> H >> N;
	for (int i = 0; i < N; ++i) {
		LL a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a == c) {
			//縦
			LL up = min(b, d);
			LL dn = max(b, d);
			vec.push_back({ true,a * 2,up * 3 - 1,dn * 3 + 1 ,i });
			tate.push_back(up * 3 - 1);
			tate.push_back(dn * 3 + 1);
			border.push_back(up * 3 - 1);
			border.push_back(dn * 3 + 1);
		}
		else {
			//横
			LL lf = min(a, c);
			LL rh = max(a, c);
			vec.push_back({ false, b * 3,2 * lf - 1,2 * rh + 1,i });
			tate.push_back(b * 3);
		}
	}
	vec.push_back({ true,0,-1,H * 3 + 1 ,(int)N });
	vec.push_back({ true,W * 2,-1,H * 3 + 1,(int)N + 1 });
	vec.push_back({ false,0,-1,W * 2 + 1 ,(int)N + 2 });
	vec.push_back({ false,H * 3,-1,W * 2 + 1 ,(int)N + 3 });
	tate.push_back(0);
	tate.push_back(H * 3);
	tate.push_back(-1);
	tate.push_back(H * 3 + 1);
	border.push_back(-1);
	border.push_back(H * 3 + 1);
	sort(tate.begin(), tate.end());
	tate.erase(unique(tate.begin(), tate.end()), tate.end());
	sort(border.begin(), border.end());
	border.erase(unique(border.begin(), border.end()), border.end());
	N += 4;
	LL M = tate.size();
	map<LL, int>inv;
	for (int i = 0; i < M; ++i) {
		inv[tate[i]] = i;
	}
	vector<pair<LL, pair<LL, LL>>>events;
	LL crossnum = 0;
	for (auto& elm : vec) {
		if (elm.dir) {
			events.push_back({ elm.pos,{ elm.b1,elm.b2 } });
		}
		else {
			events.push_back({ elm.b1,{ elm.pos,elm.pos } });
			events.push_back({ elm.b2,{ elm.pos,elm.pos } });
		}
	}
	BIT<int>bit(M);
	sort(events.begin(), events.end());
	for (auto& elm : events) {
		if (elm.second.first == elm.second.second) {
			int index = inv[elm.second.first];
			if (bit.query(index + 1) - bit.query(index)) {
				bit.add(index, -1);
			}
			else {
				bit.add(index, 1);
			}
		}
		else {
			int rind = inv[elm.second.second];
			int lind = inv[elm.second.first];
			crossnum += (bit.query(rind) - bit.query(lind));
		}
	}
	assert(border.size());
	int rawwidth = border.size() - 1;
	while (segwidth < rawwidth) {
		segwidth *= 2;
	}
	seg.resize(segwidth * 2 - 1);
	//横の線分をセグ木に入れていく
	for (auto& elm : vec) {
		if (!elm.dir) {
			LL y = elm.pos;
			int index = lower_bound(border.begin(), border.end(), y) - border.begin();
			if (index != 0 && index != border.size()) {
				//index-1番目に格納する
				seg[index - 1 + segwidth - 1].push_back({ { elm.b1,elm.b2 } ,elm.id });
			}
		}
	}
	//セグ木情報を上に伝播させていく
	for (int k = segwidth - 2; k >= 0; --k) {
		for (auto& par : seg[k * 2 + 1]) {
			seg[k].push_back(par);
		}
		for (auto& par : seg[k * 2 + 2]) {
			seg[k].push_back(par);
		}
	}
	//セグ木内部の線分を区分ごとにソートする(stack的に後ろから見る)
	for (int k = 0; k < segwidth * 2 - 1; ++k) {
		sort(seg[k].rbegin(), seg[k].rend());
	}
	//縦直線をクエリで処理
	union_find uf(N);
	sort(vec.begin(), vec.end());
	for (auto&elm : vec) {
		if (elm.dir) {
			int lef = lower_bound(border.begin(), border.end(), elm.b1) - border.begin();
			int rht = lower_bound(border.begin(), border.end(), elm.b2) - border.begin();
			query(lef, rht, uf, elm.id, elm.pos);
		}
	}
	//親の種類数で断定
	set<int>parset;
	for (int i = 0; i < N; ++i) {
		parset.insert(uf.find(i));
	}
	LL groupnum = parset.size();
	LL answer = crossnum + groupnum - N;
	cout << answer << endl;
	return 0;
}

