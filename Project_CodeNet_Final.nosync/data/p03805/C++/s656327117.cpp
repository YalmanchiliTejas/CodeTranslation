#include  <iostream>
#include  <vector>
#include  <numeric>
#include  <algorithm>
using namespace std;

typedef vector<vector<int> > Graph;
#define rep(i, n) for(int i = 0; i < n; i++)

int main()
{
	int n, m;
	cin >> n >> m;
	Graph G(n, vector<int>(n, 0));
	rep(i, m) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		G[u][v] = 1;
		G[v][u] = 1;
	}

	int ans = 0;
	vector<int> perm(n - 1);
	iota(perm.begin(), perm.end(), 1);
	do {
		int z = 0;
		bool flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (G[z][perm[i]] == 0)  flag = false;
			z = perm[i];
		}
		if (flag)  ans++;
	} while (next_permutation(perm.begin(), perm.end()));

	cout << ans << endl;
}