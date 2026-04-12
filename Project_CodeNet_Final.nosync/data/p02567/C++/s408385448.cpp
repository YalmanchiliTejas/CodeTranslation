#include<bits/stdc++.h>
#include<atcoder/segtree>

using namespace std;
using ll = long long;
#define LSG(S,F) S::value_type,S::op,S::e,F::value_type,F::mapping,F::composition,F::id //S: 取得 F: 更新
#define SG(S) S::value_type, S::op, S::e

template<class T> class RMinQ { public:
	using value_type = T;
	static T op(T l, T r) {return min(l, r);}
	static T e(){return (T)1e9;}
};
template<class T> class RMaxQ { public:
using value_type = T;
	static T op(T l, T r){ return max(l, r); }
	static T e(){return (T)-1e9;}
};
template<class T> class RSumQ { public:
	static T op(T l, T r){ return l + r; }
	static T e(){return T(0);}
};



int main()
{
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++)cin >> a[i];
	atcoder::segtree<SG(RMaxQ<int>)> tree(a);

	for(int i = 0; i < q; i++) {
		int t; cin >> t;
		if(t == 1) {
			int x, y; cin >> x >> y; x--;
			tree.set(x, y);
		}
		if(t == 2) {
			int l, r; cin >> l >> r;
			cout << tree.prod(l - 1, r) << endl;
		}
		if(t == 3) {
			int x, v; cin >> x >> v;
			x--;
			cout << tree.max_right(x, [&](int prod) {return prod < v;}) + 1 << endl;
		}
	}
	

}