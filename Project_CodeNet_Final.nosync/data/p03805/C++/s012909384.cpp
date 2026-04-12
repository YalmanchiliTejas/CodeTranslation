#include <iostream>

using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i = s;i<n;i++)

int C[8][8];
bool v[8];
int N;
int ans = 0;

bool checkallvisited() {
	bool allvisited = true;
	rep(i, 0, N) {
		allvisited &= v[i];
	}
	return allvisited;
}

void dfs(int n) {
	rep(i, 0, N) {
		if (i != n && C[n][i] == 1 && !v[i]) {
			v[i] = true;
			dfs(i);
			v[i] = false;
		}
	}

	if (checkallvisited()) {
		ans++;
		return;
	}
}

int main() {
	int  M; cin >> N >> M;
	rep(i, 0, N) {
		rep(j, 0, N) {
			C[i][j] = 0;
		}
	}

	rep(i, 0, N) {
		v[i] = false;
	}

	rep(i, 0, M) {
		int a, b; cin >> a >> b;
		C[a - 1][b - 1] = 1;
		C[b - 1][a - 1] = 1;
	}

	v[0] = true;
	dfs(0);
	cout << ans << endl;
	return 0;
}