//### In The Name Of GOD ###

//%% Remember; (((He))) is The (((Accepter))) %%

// GOD IS GREATER ...

#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;

#define sz(a) (int)(a.size())

const int MAXN = 1e5 + 10, MAXD = 11;

vector <int> adj[MAXN];

int dfs(int v = 0, int p = -1) {
	int sum = 0;
	for(int i : adj[v])
		if(i != p)
			sum += dfs(i, v);
//	cout << sum << endl;
	if(sum == 1)
		return 0;
	if(sum == 0)
			return 1;
	cout << "First";
//	cout << v << ' ' << p << ' ' << sum << endl;
	exit(0);
}

signed main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b); 
		adj[b].push_back(a);
	}
	if(!dfs()) cout << "Second";
	else cout << "First";
}
