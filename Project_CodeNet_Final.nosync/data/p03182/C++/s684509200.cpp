#include <bits/stdc++.h>
#define LL long long
#define PII pair<int,int>
using namespace std;
const int MAXN = 200005;
const LL MOD = 998244353;

struct Interval {
	int l, r, a;
	bool operator < (const Interval &it) const {
		return r < it.r;
	}
};

struct ST {
	LL maxv[4*MAXN], tag[4*MAXN];
	void add(int ql, int qr, LL v, int l, int r, int idx) {
		if (ql <= l && r <= qr) {
			maxv[idx] += v;
			tag[idx] += v;
			return;
		}
		
		int m = (l + r) >> 1;
		if (qr <= m) add(ql, qr, v, l, m, idx << 1);
		else if (ql > m) add(ql, qr, v, m + 1, r, idx << 1 | 1);
		else {
			add(ql, qr, v, l, m, idx << 1);
			add(ql, qr, v, m + 1, r, idx << 1 | 1);
		}
		
		maxv[idx] = max(maxv[idx << 1], maxv[idx << 1 | 1]) + tag[idx];
	}
	
	LL rmq(int ql, int qr, int l, int r, int idx) {
		if (ql <= l && r <= qr) return maxv[idx];
		
		int m = (l + r) >> 1;
		if (qr <= m) return rmq(ql, qr, l, m, idx << 1) + tag[idx];
		else if (ql > m) return rmq(ql, qr, m + 1, r, idx << 1 | 1) + tag[idx];
		else {
			LL q1 = rmq(ql, qr, l, m, idx << 1);
			LL q2 = rmq(ql, qr, m + 1, r, idx << 1 | 1);
			return max(q1, q2) + tag[idx];
		}
	}
} tree;

int N, M, last[MAXN];
Interval intv[MAXN];
LL dp[MAXN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> intv[i].l >> intv[i].r >> intv[i].a;
	}
	
	int pos = 1;
	sort(intv + 1, intv + 1 + M);
	for (int i = 1; i <= N; i++) {
		while (pos <= M && intv[pos].r < i) pos++;
		last[i] = pos - 1;
	}
	
	pos = 1;
	for (int i = 1; i <= M; i++) {
		tree.add(intv[i].l, intv[i].r, intv[i].a, 1, N, 1);
		while (pos <= intv[i].r) {
//			cout << "Pos " << pos << " -> " << last[pos] << "\n";
			tree.add(pos, pos, dp[last[pos]], 1, N, 1);
			pos++;
		}
		
		dp[i] = max(0LL, tree.rmq(1, intv[i].r, 1, N, 1));
//		cout << i << " -> " << dp[i] << '\n';
	}
	
	cout << dp[M] << "\n";
}
