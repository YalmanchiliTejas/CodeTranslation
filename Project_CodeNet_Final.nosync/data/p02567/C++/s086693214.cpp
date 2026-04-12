#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

int op(int a, int b){return max(a, b);}
int e(){return INT32_MIN;}

int n, q, t, x, y;
bool f(int v){return v < y;}

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	segtree<int, op, e> d(a);
	while(q--){
		cin >> t >> x >> y;
		if(t == 1) d.set(x-1, y);
		else if(t == 2) cout << d.prod(x-1, y) << "\n";
		else cout << d.max_right<f>(x-1) + 1 << "\n";
	}
	return 0;
}