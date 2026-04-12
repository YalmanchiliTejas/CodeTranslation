#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define STRING(str) #str

template <typename T >
void print_vec_1d(vector<T> x, string name) {
	cout << name << endl;
	cout << "[ ";
	for (int i=0;i<x.size();i++) {
		cout << x[i];
		if (i != x.size()-1) cout << ", ";
		else cout << " ]" << endl;
	}
}

int op(int a, int b) {
	return max(a, b);
}

int e() {
	return int(-1);
}

int target = 0;

bool f(int X) {
	return X<target;
}

int main() {
	int N, Q;
	cin >> N >> Q;
	segtree<int, op, e> seg(N);
	for (int i=0;i<N;i++) {
		int A;
		cin >> A;
		seg.set(i, A);
	}

	for (int i=0;i<Q;i++) {
		int T;
		cin >> T;
		if (T == 1) {
			int X, V;
			cin >> X >> V;
			seg.set(X-1, V);
		} else if (T == 2) {
			int L, R;
			cin >> L >> R;
			cout << seg.prod(L-1, R) << endl;
		} else { // T == 3
			int X, V;
			cin >> X >> V;
			target = V;
			cout << seg.max_right<f>(X-1)+1 << endl;
		}
	}
}