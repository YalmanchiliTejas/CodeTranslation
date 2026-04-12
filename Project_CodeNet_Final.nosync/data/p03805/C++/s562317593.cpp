#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60
int cnt = 0;
vector<vector<int>> G;
void dfs(int n,int rev, vector<int> checked) {
	checked[n] = 1;
	bool f = false;
	for (int i = 0; i < checked.size();i++) {
		if (checked[i] == 0) {
			f = true;
			break;
		}
	}
	if (!f) {
		cnt++;
		return;
	}

	for (auto next : G[n]) {
		if (checked[next] == 1)continue;
		//cout << n << " => " << next << endl;

		dfs(next,n, checked);
	}
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	G.resize(N);
	for (int i = 0; i < M;i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> checked(N, 0);
	dfs(0,-1, checked);
	cout << cnt << endl;
	return 0;
}