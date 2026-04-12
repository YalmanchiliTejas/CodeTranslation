/************************************************
 * Au: Hany01
 * Date: Jan 14th, 2019
 * Prob: dp_w
 * Email: hany01dxx@gmail.com & hany01@foxmail.com
 * Inst: Yali High School
************************************************/

#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
#define Rep(i, j) for (register int i = 0, i##_end_ = (j); i < i##_end_; ++ i)
#define For(i, j, k) for (register int i = (j), i##_end_ = (k); i <= i##_end_; ++ i)
#define Fordown(i, j, k) for (register int i = (j), i##_end_ = (k); i >= i##_end_; -- i)
#define Set(a, b) memset(a, b, sizeof(a))
#define Cpy(a, b) memcpy(a, b, sizeof(a))
#define X first
#define Y second
#define PB(a) push_back(a)
#define MP(a, b) make_pair(a, b)
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(), a.end()
#define INF (0x3f3f3f3f)
#define INF1 (2139062143)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define y1 WoXiHuanNiA

template <typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> inline bool chkmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <typename T> inline T read() {
	register T _, __; register char c_;
    for (_ = 0, __ = 1, c_ = getchar(); c_ < '0' || c_ > '9'; c_ = getchar()) if (c_ == '-') __ = -1;
    for ( ; c_ >= '0' && c_ <= '9'; c_ = getchar()) _ = (_ << 1) + (_ << 3) + (c_ ^ 48);
    return _ * __;
}
//EOT


const int MAXN = 2e5 + 5;

int n, m;
vector<PII> op[MAXN];

#define lc (t << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)
LL mx[MAXN << 2], tg[MAXN << 2];
void maintain(int t) { mx[t] = max(mx[lc], mx[rc]); }
void pushdown(int t) {
	if (tg[t]) {
		mx[lc] += tg[t], mx[rc] += tg[t];
		tg[lc] += tg[t], tg[rc] += tg[t];
		tg[t] = 0;
	}
}
void update(int t, int l, int r, int x, int y, LL dt) {
	if (x <= l && r <= y) {
		mx[t] += dt, tg[t] += dt;
		return;
	}
	pushdown(t);
	if (x <= mid) update(lc, l, mid, x, y, dt);
	if (y >  mid) update(rc, mid + 1, r, x, y, dt);
	maintain(t);
}

int main() {
#ifdef hany01
	freopen("dp_w.in", "r", stdin);
	freopen("dp_w.out", "w", stdout);
#endif

	n = read<int>(), m = read<int>();
	For(i, 1, m) {
		int l = read<int>(), r = read<int>(), val = read<int>();
		op[r].PB(MP(l, val));
	}

	For(i, 1, n) {
		update(1, 1, n, i, i, mx[1]);
		for (PII t: op[i])
			update(1, 1, n, t.X, i, t.Y);
	}
	printf("%lld\n", max(0ll, mx[1]));

	return 0;
}