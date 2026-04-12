#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n;

	void build(int n2) {
		memset(seg,INF,sizeof seg);
		n = n2;
	}
	void prop(int p, int l, int r) {
		if (!lazy[p]) return;
		seg[2*p] += lazy[p];
		seg[2*p+1] += lazy[p];
		lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return LINF;
		if (a <= l and r <= b) return seg[p];
		prop(p, l, r);
		int m = (l+r)/2;
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	ll upd(int a, int b, ll x, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return seg[p];
		if (a <= l and r <= b) {
			seg[p] += x;
			lazy[p] += x;
			return seg[p];
		}
		prop(p, l, r);
		int m = (l+r)/2;
		return seg[p] = min(upd(a, b, x, 2*p, l, m), upd(a, b, x, 2*p+1, m+1, r));
	}
};


ll memo[MAX], suf[MAX];

int main(){ _

	int n, m; cin >> n >> m;
	ll sum = 0;
	vector<vector<pair<int,int>>> inter(n);
	for(int i=0; i<m; i++) {
		int l, r, a; cin >> l >> r >> a; l--, r--;
		inter[r].push_back({l,a});
		sum += a;
		suf[l] += a;
	}
	
	for(int i=n-1; i>=0; i--) suf[i] += suf[i+1];

	seg::build(n);

	ll part = 0;
	for(int i=0; i<n; i++) {
		memo[i] = part;
		memo[i] = min(memo[i], seg::query(0,i-1));
		
		seg::upd(i,i,memo[i]-LINF);
		
		for(auto p : inter[i]) {
			seg::upd(0,p.f-1,p.s);
			part += p.s;
		}
	}

	ll ans = sum;
	for(int i=0; i<n; i++) ans = min(ans, memo[i] + suf[i+1]);
	ans = sum-ans;

	cout << ans << endl;

	return 0;
}
