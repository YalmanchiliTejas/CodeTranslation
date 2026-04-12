#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int N = 1e5 + 10;
int n, par[N], high[N], mark[N];
vector <int> adj[N];
set <pii> st;

void make_par(int v = 0, int p = 0, int h = 0) {
	par[v] = p;
	high[v] = h;
	for (int i : adj[v])
		if (i != p)
			make_par(i, v, h + 1);
}

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		v--;
		u--;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	make_par();
	
	if (n == 1)
		return cout << "First", 0;
	
	for (int i = 1; i < n; i++)
		if (adj[i].size() == 1)
			st.insert({-high[i], i});
	
	while (st.size()) {
		int v = st.begin() -> second;
		st.erase(st.begin());
		if (mark[v])
			continue;
//		cout << v + 1 << endl;
		
		if (mark[par[v]] || par[v] == v)
			return cout << "First", 0;
		mark[par[v]] = 1;
		mark[v] = 2;
		if (par[par[v]] != par[v])
			st.insert({-high[par[par[v]]], par[par[v]]});
	}
	cout << "Second";
}