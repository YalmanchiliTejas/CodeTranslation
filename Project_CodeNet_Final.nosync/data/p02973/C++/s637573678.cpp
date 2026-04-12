#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define pb push_back

#define INF int(1e9)
#define EPS 1e-9
#define MOD int(1e9 + 7)

template<typename T>
struct SegmentTree {     // One-based except Input Array
	int N;
	vector<T> stree;

	inline T f(T a, T b) { return max(a, b); }

	SegmentTree(int n) {
		N = n;
		int sz = 1;
		while(sz < N)
			sz <<= 1;
		stree.assign(sz << 1, 0);
	}

	void updatePoint(int v, int l, int r, int idx, T val) {
		if(l == r) {
			stree[v] += val;
			return;
		}
		int mid = (l + r) >> 1;
		if(idx <= mid)
			updatePoint(v << 1, l, mid, idx, val);
		else
			updatePoint(v << 1 | 1, mid + 1, r, idx, val);
		stree[v] = f(stree[v << 1], stree[v << 1 | 1]);
	}

	void updatePoint(int idx, T val) {  //Input index 1-based
		updatePoint(1, 1, N, idx, val);
	}


	T query(int v, int l, int r, int queryStart, int queryEnd) {
		if(r < queryStart || l > queryEnd)
			return 0; //dummy variable
		if(l >= queryStart && r <= queryEnd)
			return stree[v];
		int mid = (l + r) >> 1;
		T q1 = query(v << 1, l, mid, queryStart, queryEnd);
		T q2 = query(v << 1 | 1, mid + 1, r, queryStart, queryEnd);
		return f(q1, q2);
	}

	T query(int l, int r) {
		return query(1, 1, N, l, r);
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x;
	cin >> n;
	ii arr[n];
	for(int i = 0; i < n; i++) {
		cin >> x;
		arr[i] = {x, i + 1};
	}
	sort(arr, arr + n, [](ii& a, ii& b) {
		if(a.first == b.first)
			return a.second > b.second;
		return a.first < b.first;
	});
	int ans = 0;
	SegmentTree<int> tree(n);
	for(int i = 0; i < n; i++) {
		int idx = arr[i].second;
		int q = tree.query(1, idx);
		if(q == 0) {
			ans++;
		} else {
			tree.updatePoint(q, -q);
		}
		tree.updatePoint(idx, idx);
	}
	cout << ans << '\n';
	return 0;
}
