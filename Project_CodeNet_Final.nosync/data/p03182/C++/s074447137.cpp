#include <bits/stdc++.h>
#define eb emplace_back
#define INFLL (0x3f3f3f3f3f3f3f3fll)
using namespace std;
typedef long long ll;

const int MAXN = 200055;
const int MAXM = 200055;

struct SEG {
	SEG() { init(); }
	ll dmx[MAXN*4], du[MAXN*4];

	void init() { fill(dmx, dmx+MAXN*4, -INFLL); }
	void cal(int i) {
		dmx[i] = max(dmx[i<<1] + du[i<<1], dmx[i<<1|1] + du[i<<1|1]);
		if(dmx[i] < -INFLL) dmx[i] = -INFLL;
	}
	void upd(int i, int s, int e, int p, int q, int r) {
		if(q < p || e < p || q < s) return;
		if(p <= s && e <= q) {
			du[i] += r;
			return;
		}
		int m = (s+e) >> 1;
		upd(i<<1, s, m, p, q, r);
		upd(i<<1|1, m+1, e, p, q, r);
		cal(i);
	}
	void upd(int i, int s, int e, int x, ll r) {
		if(s == e) {
			dmx[i] = r;
			return;
		}
		int m = (s+e) >> 1;
		if(x <= m) upd(i<<1, s, m, x, r);
		else upd(i<<1|1, m+1, e, x, r);
		cal(i);
	}
	ll get(int i, int s, int e, int p, int q) {
		if(q < p || e < p || q < s) return -INFLL;
		if(p <= s && e <= q) return max(dmx[i] + du[i], -INFLL);
		int m = (s+e) >> 1;
		return max(max(get(i<<1, s, m, p, q), get(i<<1|1, m+1, e, p, q)) + du[i], -INFLL);
	}
} seg;

vector<int> EVI[MAXN], EVO[MAXN];
ll dp[MAXN];

int A[MAXM], B[MAXM], C[MAXM];

ll Sum;
int N, M;

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for(int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i] >> C[i];
		EVI[A[i]].eb(i);
		EVO[B[i]].eb(i);
	}

	for(int i = 1; i <= N; i++) {
		for(int v : EVI[i]) {
			Sum += C[v];
			seg.upd(1, 1, N, A[v], B[v], -C[v]);
		}
		dp[i] = max(0ll, seg.get(1, 1, N, 1, i)) + Sum;
		seg.upd(1, 1, N, i, dp[i]);
		for(int v : EVO[i]) {
			Sum -= C[v];
			seg.upd(1, 1, N, A[v], B[v], C[v]);
		}
	}

	cout << *max_element(dp, dp+N+1) << endl;
	return 0;
}