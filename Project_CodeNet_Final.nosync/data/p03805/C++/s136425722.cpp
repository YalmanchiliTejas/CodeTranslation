#include <bits/stdc++.h>

using namespace std;

typedef long ll;


bool ps[9][9];

int n, m;

#define DB

ll dfs(int node, vector<bool>& bs) 
{
	ll as = 0;
	vector<bool> st(bs);
	st[node] = true;

	for (int i = 0; i < n; ++i) {
		if ( ! ps[node][i]) continue;
		if (st[i]) continue;

		as += dfs(i, st); 
	}

	bool isOK = true;
	for (int i = 0; i < n; ++i) {
		if( ! st[i]) { isOK = false; break; }
	}

	if (isOK) as++;
	return as;
}

int main(int, char**)
{
	ll ans;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		ps[a][b] = ps[b][a] = true;
	}

	vector<bool> st(n, false);
	ans = dfs(0, st);

	cout << ans << endl;

	return 0;
}

