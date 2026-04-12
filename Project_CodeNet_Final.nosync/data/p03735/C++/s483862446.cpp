#include <bits/stdc++.h>
#define PII pair<int, int>
#define LL long long
using namespace std;
const int MAXN = 200005;
const LL INF = (LL)1e9 + 5;
const LL MOD = 1000000007;

#define val first
#define id second

int N, cnt[MAXN];
int x[MAXN], y[MAXN];
PII ord[MAXN*2];

LL test1() {
	if (N == 1) return 0;
	
	int l = 1, r = 1, cover = 0, res = INF;
	while (l < 2 * N - 1) {
		while (r < 2 * N - 1 && cover < N) {
			cnt[ord[r].id]++;
			if (cnt[ord[r].id] == 1) cover++;
			r++;
		}
		if (cover == N) {
			if (ord[r - 1].id != ord[l].id) {
				res = min(res, ord[r - 1].val - ord[l].val);
//				cout << "At " << l << ' ' << r << " get " << ord[l].val << ' ' << ord[r - 1].val << '\n';
			}
		}
		
		cnt[ord[l].id]--;
		if (cnt[ord[l].id] == 0) cover--;
		l++;
	}
	return (LL) res * (ord[2 * N - 1].val - ord[0].val);
}

LL test2() {
	if (N == 1) return 0;
	
	int mi = INF, ma = -INF;
	for (int i = 0; i < N; i++) {
		ma = max(ma, x[i]);
		mi = min(mi, y[i]);
	}
	return (LL) (ma - ord[0].val) * (ord[2 * N - 1].val - mi);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
		if (x[i] > y[i]) swap(x[i], y[i]);
		ord[i << 1] = {x[i], i};
		ord[i << 1 | 1] = {y[i], i};
	}
	sort(ord, ord + 2 * N);
	
	LL ans = test2();
	if (ord[0].id != ord[2 * N - 1].id) {
		ans = min(ans, test1());
	}
	
	cout << ans << '\n';
	
	return 0;
}