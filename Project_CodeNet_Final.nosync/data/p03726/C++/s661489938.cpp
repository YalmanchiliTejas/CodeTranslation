
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define f(i,a,b) for (int i = a; i < b; i++)
#define pb push_back

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif

	int n; cin >> n;
	vi adj[n];
	f(i,0,n-1) {
		int a,b; cin>>a>>b;
		adj[--a].pb(--b); adj[b].pb(a);
	}
	bool found = 0;
	function<int(int,int)> dfs = [&](int v, int p) {
		int ans = 0;
		for (int w : adj[v]) if (w != p)
			ans += dfs(w,v);
		if (ans == 0) return 1;
		if (ans == 1) return 0;
		found = 1;
		return 0;
	};
	found |= dfs(0,-1);
	cout << (found?"First":"Second") << endl;


#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}

