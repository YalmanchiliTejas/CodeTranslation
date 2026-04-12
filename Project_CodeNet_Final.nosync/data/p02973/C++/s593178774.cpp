#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, U, A[100005], DC[100005], ft[100005];
pair<int, int> T[100005];

inline int ls(int x) { return x & -x; }

int qry(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r = max(r, ft[p]);
	return r;
}

void upd(int p, int v) {
	for (; p <= N; p += ls(p)) ft[p] = max(ft[p], v);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i], T[i] = make_pair(A[i], i);
	sort(T + 1, T + 1 + N);
	for (int i = 1, c = 1; i <= N; i++) {
		DC[T[i].second] = c;
		if (T[i].first ^ T[i + 1].first) c++;
	}
	for (int i = 1; i <= N; i++) {
		int R = qry(N - DC[i] + 1);
		U = max(U, R + 1);
		upd(N - DC[i] + 1, R + 1);
	}
	cout << U << '\n';
}
