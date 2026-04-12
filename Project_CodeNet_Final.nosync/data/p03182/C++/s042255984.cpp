#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <iomanip>

using namespace std;

const int maxn = 200002;

int n, m;

struct node
{
	int l, r;
	long long maxv, lazy;
} segTree[maxn<<2];

void build(int idx, int l, int r) {
	segTree[idx].l = l;
	segTree[idx].r = r;
	segTree[idx].maxv = segTree[idx].lazy = 0;

	if (l == r)
		return;

	int mid = (l+r)>>1;
	build(idx<<1, l, mid);
	build((idx<<1)+1, mid+1, r);
}

void update(int idx) {
	segTree[idx].maxv = max(segTree[idx<<1].maxv, segTree[(idx<<1)+1].maxv);
}

void pushdown(int idx) {
	if (segTree[idx].lazy) {
		long long v = segTree[idx].lazy;
		segTree[idx].lazy = 0;

		segTree[idx<<1].maxv += v;
		segTree[idx<<1].lazy += v;
		segTree[(idx<<1)+1].maxv += v;
		segTree[(idx<<1)+1].lazy += v;
	}
}

void add(int idx, int st, int en, long long v) {
	if (st <= segTree[idx].l && segTree[idx].r <= en) {
		segTree[idx].maxv += v;
		segTree[idx].lazy += v;
		return;
	}

	pushdown(idx);

	int mid = (segTree[idx].l + segTree[idx].r)>>1;
	if (st <= mid)
		add(idx<<1, st, en, v);
	if (en > mid)
		add((idx<<1)+1, st, en, v);

	update(idx);
}

long long query(int idx, int st, int en) {
	if (st <= segTree[idx].l && segTree[idx].r <= en)
		return segTree[idx].maxv;

	pushdown(idx);

	int mid = (segTree[idx].l + segTree[idx].r)>>1;
	if (en <= mid)
		return query(idx<<1, st, en);
	if (st > mid)
		return query((idx<<1)+1, st, en);

	return max(query(idx<<1, st, en), query((idx<<1)+1, st, en));
}

struct interval
{
	int l, r, v;
};

bool mycmp(const interval& a, const interval &b) {
	return a.r < b.r;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;

	vector<interval> intervals(m);
	for (int i = 0; i < m; ++i) {
		cin >> intervals[i].l >> intervals[i].r >> intervals[i].v;
	}

	sort(intervals.begin(), intervals.end(), mycmp);
	
	build(1, 1, n);

	int j = 0;
	for (int i = 1; i <= n; ++i) {
		add(1, i, i, query(1, 1, i));

		while (j < m && intervals[j].r == i) {
			add(1, intervals[j].l, intervals[j].r, intervals[j].v);
			++j;
		}
	}

	long long ans = max(0LL, query(1, 1, n));
	cout << ans << endl;

	return 0;
}