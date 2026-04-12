#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 2e5 + 7;
int n, m, a, b, c;
long long ans = 0, it[4 * N], lz[4 * N];
vector < pair <int, int> > add[N], sub[N];

void lazy(int k, int l, int r){
	if(lz[k] == 0) return;
	it[k] += lz[k];
	if(l != r) lz[k << 1] += lz[k], lz[k << 1 | 1] += lz[k];
	lz[k] = 0;
}

void update(int k, int l, int r, int L, int R, long long val){
	lazy(k, l, r);
	if(l > R || r < L) return;
	if(l >= L && r <= R){
		it[k] += val;
		if(l != r) lz[k << 1] += val, lz[k << 1 | 1] += val;
		return;
	}
	int mid = (l + r) >> 1;
	update(k << 1, l, mid, L, R, val);
	update(k << 1 | 1, mid + 1, r, L, R, val);
	it[k] = max(it[k << 1], it[k << 1 | 1]);
}

void update(int k, int l, int r, int pos, long long val){
	lazy(k, l, r);
	if(l > pos || r < pos) return;
	if(l == r){
		it[k] = val;
		return;
	}
	int mid = (l + r) >> 1;
	update(k << 1, l, mid, pos, val);
	update(k << 1 | 1, mid + 1, r, pos, val);
	it[k] = max(it[k << 1], it[k << 1 | 1]);
}

long long get(int k, int l, int r, int L, int R){
	lazy(k, l, r);
	if(l > R || r < L) return (long long)-1e18;
	if(l >= L && r <= R) return it[k];
	int mid = (l + r) >> 1;
	return max(get(k << 1, l, mid, L, R), get(k << 1 | 1, mid + 1, r, L, R));
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> a >> b >> c;
		add[a].pb(mp(b, c));
		sub[b].pb(mp(a, c));
	}
	for(int i = 1; i <= n; i++){
		for(pair <int, int> x : add[i]) update(1, 1, n, 1, i, x.se);
		long long cur = get(1, 1, n, 1, i);
		ans = max(ans, cur);
		//cout << cur << endl;
		if(i < n) update(1, 1, n, i + 1, cur);
		for(pair <int, int> x : sub[i]) update(1, 1, n, 1, x.fi, -x.se);
	}
	cout << ans;
}
