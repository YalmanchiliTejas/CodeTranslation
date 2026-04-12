#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dg[N], par[N];
vector<int> gr[N];
bool mark[N];
set<pair<int, int> > s;
void dfs(int v, int pr, int h) {
	par[v] = pr;
	s.insert({-h, v});
	for (auto u : gr[v]) 
		if (u != pr)
			dfs(u, v, h + 1);
	return;
}
int main() {
	int n;
	cin >> n;
	if (n % 2 == 1) {
		cout << "First";
		return 0;
	}
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		dg[x]++, dg[y]++;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	dfs(0, 0, 1);
	int z = 0;
	while (!s.empty()) {
		auto p = *s.begin();
		s.erase(s.begin());
		int v = p.second, pr = par[v];
//		cout << "v = " << v << " h = " << h << " pr = " << pr << endl;
		if (mark[v])
			continue;
		if (dg[pr] > 2 || dg[pr] == 2 && dg[par[pr]] == 1 || dg[pr] == 2 && pr == 0) {
			z = 1;
			break;
		}
		dg[par[pr]]--, mark[pr] = 1;
	}
	if (z)
		cout << "First";
	else
		cout << "Second";
	return 0;
}
