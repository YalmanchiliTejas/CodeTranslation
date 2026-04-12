#include "bits/stdc++.h"
using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define replrev(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define reprev(i,n) replrev(i,0,n)
#define repi(itr,ds) for(auto itr = ds.begin(); itr != ds.end(); ++itr)
#define mp make_pair
#define INF 2000000000
#define MOD 1000000007
#define PI 3.1415926536
typedef long long ll;
typedef pair<int, int> P;

int ans = 0;
vector<bool> used;
vector<vector<int>>G;
int N, M;

void dfs(int pos, int par) {
	used[pos] = true;

	bool ok = true;
	rep(i, N) {
		ok = ok && used[i];
	}
	if (ok) {
		ans++;
		used[pos] = false;
		return;
	}

	rep(i, G[pos].size()) {
		if (G[pos][i] == par || used[G[pos][i]])continue;
		dfs(G[pos][i], pos);
	}

	used[pos] = false;
}

int main() {
	cin >> N >> M;
	G = vector<vector<int>>(N);
	used = vector<bool>(N);

	rep(i, M) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(0, -1);

	cout << ans << endl;

	return 0;
}