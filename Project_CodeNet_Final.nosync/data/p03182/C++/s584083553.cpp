#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define N 200010
#define ll long long
using namespace std;

ll T[N * 8], tag[N * 8];
#define ls id<<1
#define rs id<<1|1
void add(int id, ll x) {tag[id] += x, T[id] += x;}
void pushdown(int id) {
	if (tag[id] == 0)return;
	add(ls, tag[id]), add(rs, tag[id]);
	tag[id] = 0;
}
void upd(int l, int r, int id, int L, int R, ll x) {
	if (L <= l && r <= R) {add(id, x); return;}
	pushdown(id);
	int m = (l + r) >> 1;
	if (L <= m)upd(l, m, ls, L, R, x);
	if (R > m)upd(m + 1, r, rs, L, R, x);
	T[id] = max(T[ls], T[rs]);
}

ll Q(int l, int r, int id, int L, int R) {
	if (L <= l && r <= R)return T[id];
	pushdown(id);
	int m = (l + r) >> 1; ll res = 0;
	if (L <= m)res = max(res, Q(l, m, ls, L, R));
	if (R > m)res = max(res, Q(m + 1, r, rs, L, R));
	return res;
}

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-')f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
struct info {int l, x;};
vector<info> A[N];
int main() {
	int n = read();
	for (int o = read(); o--;) {
		int l = read(), r = read(), x = read();
		A[r].push_back((info) {l, x});
	}
	for (int i = 1; i <= n; ++i) {
		upd(1, n, 1, i, i, Q(1, n, 1, 1, i));
		for (info t : A[i])upd(1, n, 1, t.l, i, t.x);
	}
	printf("%lld\n", max(T[1], 0ll));
	return 0;
}
