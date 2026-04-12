#include <iostream>
using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i = s;i<n;i++)

ll c[10000][10000];
bool v[10000];
ll N, M;
ll cnt = 0;

bool isVisitedAll() {
	bool valid = true;
	rep(i, 0, N) {
		valid &= v[i];
	}
	return valid;
}

void dfs(int id) {
	if (isVisitedAll()) {
		cnt++;
		return;
	}

	rep(i, 0, N) {
		if (id != i && c[id][i] != 0 && !v[i]) {
			v[i] = true;
			dfs(i);
			v[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	rep(i, 0, M) {
		int a, b; cin >> a >> b;
		c[a - 1][b - 1] = 1;
		c[b - 1][a - 1] = 1;
	}

	v[0] = true;
	dfs(0);

	cout << cnt << endl;
	return 0;
}