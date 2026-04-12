#include <vector>
#include <iostream>

using namespace std;
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

int n;
vector<int> a, col, tree;

int merge(int l, int r) {
	if (col[l] < col[r]) return l;
	return r;
}

void update(int ui, int uval, int l, int r, int ind) {
	if (l == r) {
		if (l == ui) {
			col[ui] = uval;
			tree[ind] = l;
			return;
		}
	}

	if (ui < l or r < ui) return;

	int mid((l + r) >> 1);
	if (ui <= mid) update(ui, uval, l, mid, 2 * ind);
	else update(ui, uval, mid + 1, r, 2 * ind + 1);

	tree[ind] = merge(tree[2 * ind], tree[2 * ind + 1]);
	return;
}

int query(int ql, int qr, int qval, int l, int r, int ind) {
	if (col[tree[ind]] >= qval) return -1;

	if (qr < l or r < ql) return -1;

	if (l == r) return l;

	int mid((l + r) >> 1);

	int left = query(ql, qr, qval, l, mid, 2 * ind);
	if (left != -1) return left;

	int right = query(ql, qr, qval, mid + 1, r, 2 * ind + 1);
	return right;

}

int main() {

	cin >> n;
	a.resize(n, 0); for (int i = 0; i <= n - 1; i++) cin >> a[i];
	col.resize(n, -1);
	tree.resize(4 * n + 1, 0);

	int mx = 0;

	for (int i = 0; i <= n - 1; i++) {
		int j = query(0, mx - 1, a[i], 0, n - 1, 1);

		if (j != -1) update(j, a[i], 0, n - 1, 1);
		else {
			update(mx, a[i], 0, n - 1, 1);
			mx++;
		}
	}

	cout << mx;

	return 0;
}