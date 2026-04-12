
#include <bits/stdc++.h>

#define ln                 '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 2e3;
const int inf = 0x3f3f3f3f;
int n, a[3 * nsz + 5], f[nsz + 5][nsz + 5], mx[nsz + 5], maxi, ans;

struct value {
	int a, b, val;
	
	value() {}
	value(int a, int b, int val) {
		this->a = a, this->b = b, this->val = val;
	}
};
vector<value> dat;

bool inline all_same(int a, int b, int c) {
	return a == b && b == c;
}

void inline upd(int a, int b, int val) {
	dat.push_back({a, b, val});
}

void inline upd_all() {
	for (auto&[a, b, val] : dat) {
		f[a][b] = max(f[a][b], val);
		f[b][a] = max(f[b][a], val);
		mx[a] = max(mx[a], val);
		mx[b] = max(mx[b], val);
		maxi = max(maxi, val);
	}
	dat.clear();
}

int main() {
	scanf("%d", &n);
	cont (i, n * 3) scanf("%d", &a[i]);
	memset(f, -inf, sizeof(f));
	memset(mx, -inf, sizeof(mx));
	maxi = -inf;
	upd(a[1], a[2], 0);
	upd_all();
	loop (rnd, n) {
		int i = rnd * 3 + 3;
		sort(a + i, a + i + 3);
		if (a[i] == a[i + 2]) { ans += 1; continue; }
		upd(a[i + 0], a[i + 1], maxi);
		upd(a[i + 0], a[i + 2], maxi);
		upd(a[i + 1], a[i + 2], maxi);
		cont (k, n) {
			upd(a[i + 0], a[i + 1], f[k][k] + all_same(k, k, a[i + 2]));
			upd(a[i + 0], a[i + 2], f[k][k] + all_same(k, k, a[i + 1]));
			upd(a[i + 1], a[i + 2], f[k][k] + all_same(k, k, a[i + 0]));
		}
		cont (k, n) {
			upd(k, a[i + 0], mx[k]);
			if (a[i + 1] == a[i + 2]) upd(k, a[i + 0], f[k][a[i + 1]] + 1);
			upd(k, a[i + 1], mx[k]);
			if (a[i + 0] == a[i + 2]) upd(k, a[i + 1], f[k][a[i + 0]] + 1);
			upd(k, a[i + 2], mx[k]);
			if (a[i + 0] == a[i + 1]) upd(k, a[i + 2], f[k][a[i + 0]] + 1);
		}
		upd_all();
	}
	ans += maxi;
	printf("%d\n", ans);
}