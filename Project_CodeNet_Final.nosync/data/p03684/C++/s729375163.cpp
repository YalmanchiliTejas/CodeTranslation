#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
template <typename T> using ord_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5 + 123;
int n, par[N], sz[N];

struct pt {
	int x, y, ind;
	bool operator < (const pt & p) {
		return x < p.x;
	}
};
pt p[N];

struct edge {
	int x, y, w;
	bool operator < (const edge & e) {
		return w < e.w;
	}
};
vector <edge> v;

void make_set(int x) {
	par[x] = x;
	sz[x] = 1;
}

int find_set(int x) {
	if (x == par[x]) return x;
	return par[x] = find_set(par[x]);
}

bool union_set(int x, int y) {
	x = find_set(x), y = find_set(y);
	if (x == y) return false;
	if (sz[x] < sz[y])
		swap(x, y);
	par[y] = x;
	sz[x] += sz[y];
	return true;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y, p[i].ind = i;
		make_set(i);
	}
	sort(p, p + n);
	edge t;
	for (int i = 1; i < n; i++) {
		t.x = p[i - 1].ind, t.y = p[i].ind;
		t.w = min(abs(p[i - 1].x - p[i].x), abs(p[i - 1].y - p[i].y));
		v.pb(t);
	}
	for (int i = 0; i < n; i++) swap(p[i].x, p[i].y);
	sort(p, p + n);
	for (int i = 0; i < n; i++) swap(p[i].x, p[i].y);
	for (int i = 1; i < n; i++) {
		t.x = p[i - 1].ind, t.y = p[i].ind;
		t.w = min(abs(p[i - 1].x - p[i].x), abs(p[i - 1].y - p[i].y));
		v.pb(t);
	}
	sort(all(v));
	ll res = 0;
	for (int i = 0; i < (int)v.size(); i++) {
		if (union_set(v[i].x, v[i].y))
			res += v[i].w;
	}
	cout << res;
}
