#include <iostream>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;

int op(int a, int b) { return max(a, b); }
int e() { return -1; }
int tar;
bool f(int x) { return x < tar; }

int main() {
	int N, Q;
	cin >> N >> Q;
	segtree<int, op, e> seg(N);
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		seg.set(i, A);
	}
	for (int q = 0; q < Q; q++) {
		int t;
		cin >> t;
		int x;
		switch (t) {
		case 1:
			int v;
			cin >> x >> v;
			seg.set(x - 1, v);
			break;
		case 2:
			int l, r;
			cin >> l >> r;
			cout << seg.prod(l - 1, r) << endl;
			break;
		case 3:
			cin >> x >> tar;
			cout << seg.max_right<f> (x - 1) + 1 << endl;
		}
	}
}
