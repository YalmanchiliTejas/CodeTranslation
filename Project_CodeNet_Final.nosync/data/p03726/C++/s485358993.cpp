#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;


vector<int> g[N];
int st[N], dr[N];
bool f[N], red[N];

int n;


static void dfs(int u, int far = 0) {
	for (auto v: g[u]) if (v != far) {
		red[v] = red[u] ^ true;
		dfs(v, u); } }

static bool pairup(int u) {
	if (f[u]) return false;
	f[u] = true;

	for (auto v: g[u]) if (!dr[v]) {
		st[u] = v;
		dr[v] = u; 
		return true; }

	for (auto v: g[u]) if (pairup(dr[v])) {
		st[u] = v;
		dr[v] = u;
		return true; }

	return false; }


int main() {
#ifdef HOME
	freopen("agc14d.in", "r", stdin);
	freopen("agc14d.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int matching(0);
	bool flag;

	cin >> n;
	for (int a, b, i = 1; i < n; ++i) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a); }

	if (n % 2) {
		cout << "First\n";
		return 0; }

	dfs(1);

	do {
		flag = false;
		for (int i = 1; i <= n; ++i) if (red[i]) {
			if (!st[i] && pairup(i)) {
				flag = true;
				matching+= 1; } }
		memset(f, 0x00, sizeof f); }	
	while (flag);

	cout << (matching == n / 2 ? "Second" : "First") << endl;

	return 0; }
