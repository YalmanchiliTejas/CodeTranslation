#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define pii pair<int, int>
typedef long long ll;
using namespace std;

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int OFF = (1 << 20);

int n, m, p1, p2, p3;
vector< pair<int, int> > v[200002];
ll t[2 * OFF + 5];
ll p[2 * OFF + 5];

void prop(int x) {
	t[x*2] += p[x];
	t[x*2+1] += p[x];
	p[x*2] += p[x];
	p[x*2+1] += p[x];
	p[x] = 0;
}

void update(int a, int b, int l, int r, int x, ll kol) {
	if (r <= a || b <= l) return;
	if (a <= l && r <= b) {
		p[x] += kol;
		t[x] += kol;
		return;
	}
	
	prop(x);
	
	update(a, b, l, (l+r)/2, x*2, kol);
	update(a, b, (l+r)/2, r, x*2+1, kol);
	t[x] = min(t[x*2], t[x*2+1]);
}

ll query(int a, int b, int l, int r, int x) {
	if (r <= a || b <= l) return INF;
	if (a <= l && r <= b) return t[x];
	
	prop(x);
	
	return min(query(a, b, l, (l+r)/2, x*2), query(a, b, (l+r)/2, r, x*2+1));
}

int main () {

	cin >> n >> m;
	ll sol = 0, minus = 0;
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2 >> p3;
		v[p2].push_back({p1, p3});
		sol += p3;
	}
	
	for (int i = 1; i <= n+1; i++) {
		for (int j = 0; j < v[i-1].size(); j++) {
			update(0, v[i-1][j].X, 0, OFF, 1, v[i-1][j].Y);
		}
		
		ll tren = query(0, i, 0, OFF, 1);
		update(i, i+1, 0, OFF, 1, tren);
		minus = min(minus, tren);	
	}
	
	sol -= minus;
	cout << sol;

	return 0;
}