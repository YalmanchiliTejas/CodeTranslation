#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];
bool taken[N];

int matching, n;

static void match(int u, int pap = 0) {
	for (auto v: g[u]) if (v != pap)
		match(v, u);
	for (auto v: g[u])
		if (!taken[v] && !taken[u]) {
			taken[u] = taken[v] = 1;
			matching+= 1; } }

int main() {
#ifdef HOME
	freopen("agc14d.in", "r", stdin);
	freopen("agc14d.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int a, b, i = 1; i < n; ++i) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a); }

	if (n % 2) {
		cout << "First\n";
		return 0; }

	match(1);

	cout << (matching == n / 2 ? "Second" : "First") << endl;

	return 0; }

