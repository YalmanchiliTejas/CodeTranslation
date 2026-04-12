#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define ll long long

int op(int a, int b) {
	return max(a, b);
}
int e() {
	return -1;
}
int target;
bool f(int v) {
	return v < target;
}

signed main() {
	int N, Q; cin >> N >> Q;
	vector<int>A(N);
	for (int i = 0; i < N; i++)cin >> A[i];
	segtree<int, op, e>seg(A);
	for (int i = 0; i < Q; i++) {
		int T; cin >> T;
		if (T == 1) {
			int X, V; cin >> X >> V; X--;
			seg.set(X, V);
		}
		else if (T == 2) {
			int L, R; cin >> L >> R; L--;
			cout << seg.prod(L, R) << endl;
		}
		else {
			int X; cin >> X >> target; X--;
			cout << seg.max_right<f>(X) + 1 << endl;
		}
	}
	return 0;
}
