#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
ld eps=1e-9;
#define Seg_Max_N (1<<18) 

using Value = pair<bool, long long int>;
const Value ini = make_pair(false,0);
struct segtree {
	int N;
	vector<Value>dat;

	segtree() {}
	segtree(int n) :dat(2 * Seg_Max_N) {
		N = 1;
		while (N < n) N *= 2;
		for (int i = 0; i < 2 * N - 1; i++) {
			dat[i] = ini;
		}
	}
	Value connect(const Value&l, const Value&r) {
		if (l.first) {
			if (r.first) {
				return make_pair(false,r.second-l.second);
			}
			else {
				return make_pair(true,l.second+r.second);
			}
		}
		else {
			if (r.first) {
				return make_pair(true,r.second-l.second);
			}
			else {
				return make_pair(false,l.second+r.second);
			}
		}
	}
	// update k th element
	void update(int k, Value a) {
		k += N - 1;
		dat[k] = a;

		while (k > 0) {
			k = (k - 1) / 2;
			const Value al(dat[k * 2 + 1]);
			const Value ar(dat[k * 2 + 2]);
			dat[k] = connect(al, ar);
		}
	}
	// min [a, b)
	Value  query(int a, int b) { return query(a, b, 0, 0, N); }
	Value  query(int a, int b, int k, int l, int r) {
		if (r <= a or b <= l) return ini;
		if (a <= l and r <= b) return dat[k];
		const int m = (l + r) / 2;
		const Value al(query(a, b, k * 2 + 1, l, m));
		const Value ar(query(a, b, k * 2 + 2, m, r));
		return connect(al, ar);
	}
};
int main() {
	int X;cin>>X;
	if(X==3||X==5||X==7)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}