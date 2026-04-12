#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
template<typename T> class segtree {
private:
	int n, sz, h;
	vector<T> node, lazy;
	void eval(int k) {
		if (lazy[k]) {
			node[k] += lazy[k];
			if (k < n) {
				lazy[k * 2] += lazy[k], lazy[k * 2 + 1] += lazy[k];
			}
			lazy[k] = 0;
		}
	}

public:
	segtree(int _sz) {
		sz = _sz;
		h = 0;
		n = 1;
		while (n < sz) n *= 2, h++;
		node.resize(2 * n, numeric_limits<T>::max());
		lazy.resize(2 * n, 0);
		for (int i = 0; i < sz; i++) node[i + n] = 0;
		for (int i = n - 1; i >= 1; i--) node[i] = min(node[2 * i], node[2 * i + 1]);
	}
	void range(int a, int b, T x) {
		a += n, b += n - 1;
		for (int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
		int ta = a, tb = b++;
		while (a < b) {
			if (a & 1) lazy[a++] += x;
			if (b & 1) lazy[--b] += x;
			a >>= 1, b >>= 1;
		}
		while (ta >>= 1, tb >>= 1, ta) {
			if (!lazy[ta]) {
				eval(2 * ta), eval(2 * ta + 1), node[ta] = min(node[2 * ta], node[2 * ta + 1]);
			}
			if (!lazy[tb]) {
				eval(2 * tb), eval(2 * tb + 1), node[tb] = min(node[2 * tb], node[2 * tb + 1]);
			}
		}
	}
	T query(int a, int b) {
		a += n, b += n - 1;
		for (int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
		b++;
		T res1 = numeric_limits<T>::max(), res2 = numeric_limits<T>::max();
		while (a < b) {
			if (a & 1) eval(a), res1 = min(res1, node[a++]);
			if (b & 1) eval(--b), res2 = min(res2, node[b]);
			a >>= 1, b >>= 1;
		}
		return min(res1, res2);
	}
	void print() { for (int i = 0; i < sz; i++) cout << query(i, i + 1) << " "; cout << endl; }
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, int> > > L(N + 1);
	int res = 0;
	int l, r, a;
	for (int i = 0; i < M; i++) {
		cin >> l >> r >> a;
		L[r].emplace_back(l, a);
		res += a;
	}
	for (int i = 1; i <= N; i++) {
		sort(L[i].rbegin(), L[i].rend());
	}
	vector<int> dp(N + 2, 0);
	segtree<int> sg(N + 5);
	for (int i = 1; i <= N + 1; i++) {
		//dp[i] = min(dp[i], dp[i - 1]);
		for (auto &j : L[i - 1]) {
			l = j.first;
			a = j.second;
			sg.range(0, l + 1, a);
		}

		dp[i] = sg.query(0, i + 1);
		sg.range(i + 1, i + 2, dp[i]);
		//cerr << dp[i] << " ";
	}
	//cerr << endl;

	cout << res - dp.back() << endl;
}