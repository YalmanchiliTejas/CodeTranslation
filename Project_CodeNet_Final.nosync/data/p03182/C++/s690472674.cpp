#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
#include <deque>
#include <array>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <map>
#include <functional>
#include <bitset>
#include <complex>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	struct Seg {
		int l, r, a;
	};
	int n, m;
	cin >> n >> m;
	vector<Seg> ss(m);
	vector<vi> st(n + 1), en(n + 1);
	for(int i = 0; i < m; i++) {
		auto& s = ss[i];
		cin >> s.l >> s.r >> s.a;
		st[s.l].pb(i);
		en[s.r].pb(i);
	}
	struct SegTree {
		struct Node {
			ll mx, ad;
		};
		Node merge(const Node& a, const Node& b) {
			return { max(a.mx, b.mx), 0 };
		};
		vector<Node> t;
		SegTree(int n) : t(4 * n, { 0, 0 }) {}
		void push(int v) {
			if (t[v].ad) {
				ll x = t[v].ad;
				t[v].ad = 0;
				t[v << 1].ad += x;
				t[v << 1].mx += x;
				t[v << 1 | 1].ad += x;
				t[v << 1 | 1].mx += x;
			}
		}
		void upd(int v, int l, int r, int l1, int r1, ll x) {
			if (r < l1 || r1 < l) return;
			if (l1 <= l && r <= r1) {
				t[v].ad += x;
				t[v].mx += x;
				return;
			}
			push(v);
			int m = (l + r) >> 1;
			upd(v << 1, l, m, l1, r1, x);
			upd(v << 1 | 1, m + 1, r, l1, r1, x);
			t[v] = merge(t[v << 1], t[v << 1 | 1]);
		}
		const ll inf = 1e18 + 228;
		ll get(int v, int l, int r, int l1, int r1) {
			if (r < l1 || r1 < l) {
				return -inf;
			}
			if (l1 <= l && r <= r1) {
				return t[v].mx;
			}
			push(v);
			int m = (l + r) >> 1;
			return max(get(v << 1, l, m, l1, r1), get(v << 1 | 1, m + 1, r, l1, r1));
		}
	};
	SegTree t(n + 1);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int s : st[i]) {
			t.upd(1, 0, n, 0, i - 1, ss[s].a);
		}
		ll dp = t.get(1, 0, n, 0, i - 1);
		ans = max(ans, dp);
		t.upd(1, 0, n, i, i, dp);
		for (int s : en[i]) {
			t.upd(1, 0, n, 0, ss[s].l - 1, -ss[s].a);
		}
	}
	cout << ans;
}
