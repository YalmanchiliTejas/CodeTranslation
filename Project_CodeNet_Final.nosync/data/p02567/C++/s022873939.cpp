#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;
using namespace atcoder;

typedef long long ll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

ll op(ll a, ll b){ return max(a, b);};
ll e(){ return -1ll;};

ll v;
ll f(ll x){ return x < v;};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;

	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	segtree<ll, op, e> seg(a);
	rep(i, q){
		int t;
		cin >> t;
		if(t == 1){
			ll x;
			cin >> x >> v;
			x--;
			seg.set(x, v);
		}else if(t == 2){
			ll l, r;
			cin >> l >> r;
			l--; r--;
			cout << seg.prod(l, r + 1) << endl;
		}else{
			ll x;
			cin >> x >> v;
			x--;
			cout << seg.max_right(x, f) + 1 << endl;
		}
	}
}
