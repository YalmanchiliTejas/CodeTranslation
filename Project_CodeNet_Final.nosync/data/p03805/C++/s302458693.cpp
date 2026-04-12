#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(n));
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a][b] = 1;
		g[b][a] = 1;
	}
	vector<int> p(n-1);
	rep(i, n-1) p[i] = i+1;
	int ans = 0;
	do {
		bool ok = true;
		vector<int> now(n);
		rep(i, n-1) now[i+1] = p[i];
		rep(i, n-1) {
			if(g[now[i]][now[i+1]] == 0) ok = false;
		}
		if(ok) ans++;
	} while(next_permutation(all(p)));
	cout << ans << endl;
	return 0;
}