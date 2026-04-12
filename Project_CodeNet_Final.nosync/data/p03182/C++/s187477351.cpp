#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long llint;

const int maxn = 2e5+10;
const int base = 31337;
const int mod = 1e9+7;
const int logo = 18;
const int off = 1 << logo;
const int treesiz = off << 1;

int n, m;
vector< pair<int, int> > v[maxn];
llint tour[treesiz], prop[treesiz];
llint dp[maxn];

void send(int node) {
	tour[node * 2] += prop[node];
	tour[node * 2 + 1] += prop[node];
	
	prop[node * 2] += prop[node];
	prop[node * 2 + 1] += prop[node];
	prop[node] = 0;
}

void update(int a, int b, int l, int r, int node, llint val) {
	if (l >= a && r <= b) {
		tour[node] += val;
		prop[node] += val;
		return;
	} 
	if (r < a || l > b) return;
	
	int mid = (l + r) / 2;
	send(node);
	update(a, b, l, mid, node * 2, val);
	update(a, b, mid + 1, r, node * 2 + 1, val);
	tour[node] = max(tour[node * 2], tour[node * 2 + 1]);
}

llint query(int a, int b, int l, int r, int node) {
	if (l >= a && r <= b) return tour[node];
	if (r < a || l > b) return -(1LL << 60);
	
	int mid = (l + r) / 2;
	send(node);
	return max(query(a, b, l, mid, node * 2), query(a, b, mid + 1, r, node * 2 + 1));
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		
		v[a].push_back(make_pair(c, a - 1));
		v[b + 1].push_back(make_pair(-c, a - 1));
	}
	
	llint sol = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < v[i].size(); j++) 
			update(0, v[i][j].Y, 0, off - 1, 1, v[i][j].X);
		
		dp[i] = query(0, i - 1, 0, off - 1, 1);
		sol = max(sol, dp[i]);
		update(i, i, 0, off - 1, 1, dp[i]);
	}
	printf("%lld\n", sol);
	return 0;
}
