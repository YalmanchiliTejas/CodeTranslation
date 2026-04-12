#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;

typedef modint998244353 mint;

const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
//const ll MOD = 1e9 + 7;
const ll MOD = 998244353;

const ll MAX = 1e9 + 5;
int target;

int op(int a, int b) {
	return max(a, b);
}

int e() {
	return -1;
}
bool f(int v) {
	return v < target;
}
int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	segtree<int, op, e> seg(a);
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, v;
			cin >> x >> v;
			x--;
			seg.set(x, v);
		}
		else if (t == 2) {
			int l, r;
			cin >> l >> r;
			l--;
			cout << seg.prod(l, r) << endl;
		}
		else {
			int p;
			cin >> p >> target;
			p--;
			cout << seg.max_right<f>(p) + 1 << endl;
		}
	}
}