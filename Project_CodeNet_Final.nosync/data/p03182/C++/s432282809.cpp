// :)
// "Khodaya, be man "Tagwaye setiz" biamooz ta
//  dar anbuh masuliat nalaghzam ..." -Shariati
#include <bits/stdc++.h>

using namespace std;
typedef long long int64;
typedef pair<int,int> pii;
typedef pair<int64,int64> pii64;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 2e5+10;
const int64 MO = 1e9+7;
const int64 IN = 1e18;

vector <pii> v1[maxn];

int64 seg[maxn * 4], lzy[maxn * 4];

int N, M;

void update (int x, int64 val, int l = 0, int r = N + 1, int id = 1) {
	if (x < l || x >= r)
		return;
	if (r - l == 1) {
		seg[id] += val;
		lzy[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	seg[id * 2] += lzy[id];
	seg[id * 2 + 1] += lzy[id];
	lzy[id * 2] += lzy[id];
	lzy[id * 2 + 1] += lzy[id];
	lzy[id] = 0;
	update(x, val, l, mid, id * 2);
	update(x, val, mid, r, id * 2 + 1);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
	return;
}

void add (int st, int en, int64 val, int l = 0, int r = N + 1, int id = 1) {
	if (st >= r || en <= l)
		return;
	if (st <= l && en >= r) {
		seg[id] += val;
		lzy[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	seg[id * 2] += lzy[id];
	seg[id * 2 + 1] += lzy[id];
	lzy[id * 2] += lzy[id];
	lzy[id * 2 + 1] += lzy[id];
	lzy[id] = 0;
	add(st, en, val, l, mid, id * 2);
	add(st, en, val, mid, r, id * 2 + 1);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
	return;
}

int64 getmx (int st, int en, int l = 0, int r = N + 1, int id = 1) {
	if (st >= r || en <= l)
		return -IN;
	if (st <= l && en >= r)
		return seg[id];
	int mid = (l + r) >> 1;
	seg[id * 2] += lzy[id];
	seg[id * 2 + 1] += lzy[id];
	lzy[id * 2] += lzy[id];
	lzy[id * 2 + 1] += lzy[id];
	lzy[id] = 0;
	return max(getmx(st, en, l, mid, id * 2), getmx(st, en, mid, r, id * 2 + 1));
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	// 
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int l, r, a;
		cin >> l >> r >> a;
		v1[r].PB( MP( l , a ) );
	}
	for (int i = 1; i <= N; i++) {
		update(i, getmx(0, i));
		for (auto x : v1[i]) {
			int l = x.F, a = x.S;
			add(l, i + 1, a);
		}
	}
	//
	cout << seg[1] << "\n";
	//
}

