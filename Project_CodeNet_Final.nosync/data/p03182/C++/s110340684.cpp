#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_of_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;

const int nax = 2e5 + 111, pod = (1 << 18);
const long long INF = 1e16;

ll lazy[2 * pod], maxi[2 * pod];

void upd(int u, int son) {
	lazy[son] += lazy[u];
	maxi[son] += lazy[u];
}

void push(int u) {
	upd(u, 2 * u);
	upd(u, 2 * u + 1);
	lazy[u] = 0;
}

void add(int x, int y, ll val, int u = 1, int l = 0, int r = pod - 1) {
	if(x <= l && r <= y) {
		lazy[u] += val;
		maxi[u] += val;
		return ;
	}
	push(u);
	int m = (l + r) / 2;
	if(x <= m)
		add(x, y, val, 2 * u, l, m);
	if(m < y)
		add(x, y, val, 2 * u + 1, m + 1, r);
	maxi[u] = max(maxi[2 * u], maxi[2 * u + 1]);
}

int n, m;
int l, r, c;
vector <pair<int, int>> Add[nax], Era[nax];


int main() {
	ios;
	
	FOR(i, 1, 2 * pod - 1) 
		maxi[i] = -INF;
	add(0, 0, INF);
	cin >> n >> m;
	FOR(i, 1, m) {
		cin >> l >> r >> c;
		Add[l].pb(mp(l - 1, c));
		Era[r + 1].pb(mp(l - 1, -c));
	}
	
	ll best = 0;
	FOR(i, 1, n) {
		for(auto it: Add[i])
			add(0, it.fi, it.se);
		for(auto it: Era[i])
			add(0, it.fi, it.se);
		ll val = maxi[1];
		add(i, i, val + INF);
		best = max(best, val);
	}
	
	cout << best;
	
	
		
	
	
	
	
	
	
	return 0;
}
		
