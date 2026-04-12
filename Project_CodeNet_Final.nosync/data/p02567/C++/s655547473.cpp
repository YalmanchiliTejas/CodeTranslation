#include<bits/stdc++.h>
#include<atcoder/segtree>

using namespace std;
using ll = long long;

template<class T> class RMaxQ { public:
using value_type = T;
	static T op(T l, T r){ return max(l, r); }
	static T id(){return (T)-1e9;}
};
int target;

bool f(int v) { return v < target; }


int main()
{
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++)cin >> a[i];
	atcoder::segtree<int, RMaxQ<int>::op, RMaxQ<int>::id> tree(a);

	for(int i = 0; i < q; i++) {
		int t; cin >> t;
		if(t == 1) {
			int x, v; cin >> x >> v;
			x--;
			tree.set(x, v);
		}
		if(t == 2) {
			int l, r; cin >> l >> r;
			l--;
			cout << tree.prod(l, r) << endl;
		}
		if(t == 3) {
			int x; cin >> x >> target;
			x--;
			cout << tree.max_right<f>(x) + 1 << endl;
			
		}
	}
	
}